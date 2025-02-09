#include <avr/io.h>
#include <avr/pgmspace.h>
#include <string.h>
#include <util/delay.h>

#include "../inc/font.h"
#include "../inc/num_types.h"
#include "../inc/ssd1306.h"
#include "../inc/twi.h"

#define SSD1306_COLUMN_START   (0)
#define SSD1306_COLUMN_END     (SSD1306_COLUMNS - 1)
#define SSD1306_PAGE_START     (0)
#define SSD1306_PAGE_END       (SSD1306_PAGES - 1)

#define SSD1306_BLOCK_COLUMNS  (SSD1306_COLUMNS / BLOCK_WIDTH)
#define SSD1306_BLOCK_ROWS     (SSD1306_ROWS / BLOCK_HEIGHT)

#define SSD1306_DELAY_POWER_ON (2500)

enum SSD1306_Command {
	SSD1306_SetMemoryMode       = 0x20,
	SSD1306_SetColumnRange      = 0x21,
	SSD1306_SetPageRange        = 0x22,
	SSD1306_ScrollDisable       = 0x2E,
	SSD1306_ScrollEnable        = 0x2F,
	SSD1306_SetDisplayStartLine = 0x40,
	SSD1306_SetContrast         = 0x81,
	SSD1306_ChargePump          = 0x8D,
	SSD1306_SegRemapNoFlip      = 0xA0,
	SSD1306_SegRemapFlip        = 0xA1,
	SSD1306_DisplayRam          = 0xA4,
	SSD1306_DisplayAllOn        = 0xA5,
	SSD1306_SetNormalDisplay    = 0xA6,
	SSD1306_SetInvertDisplay    = 0xA7,
	SSD1306_SetMultiplexRatio   = 0xA8,
	SSD1306_DisplayOff          = 0xAE,
	SSD1306_DisplayOn           = 0xAF,
	SSD1306_ComScanInc          = 0xC0,
	SSD1306_ComScanDec          = 0xC8,
	SSD1306_SetDisplayOffset    = 0xD3,
	SSD1306_SetDisplayClockDiv  = 0xD5,
	SSD1306_SetPrecharge        = 0xD9,
	SSD1306_SetComPins          = 0xDA,
	SSD1306_SetVcomDeselect     = 0xDB,
};

enum SSD1306_Control {
	SSD1306_Command = 0x00,
	SSD1306_Data    = 0x40,
};

enum SSD1306_ChargePump {
	SSD1306_ChargePumpDisable = 0x10,
	SSD1306_ChargePumpEnable  = 0x14,
};

static void ssd1306_command(const struct SSD1306* oled, u8 cmd);
static void
ssd1306_command_list(const struct SSD1306* oled, const u8* cmds, u8 length);
static void ssd1306_data_list(const struct SSD1306* oled, u8* data, u16 length);
static void ssd1306_newline(struct SSD1306* oled);
static void ssd1306_advance_cursor(struct SSD1306* oled);

static void ssd1306_command(const struct SSD1306* oled, u8 cmd)
{
	twi_mtx_begin(oled->twi_addr);
	twi_mtx_write_byte(SSD1306_Command);
	twi_mtx_write_byte(cmd);
	twi_mtx_end();

	return;
}

static void
ssd1306_command_list(const struct SSD1306* oled, const u8* cmds, u8 length)
{
	twi_mtx_begin(oled->twi_addr);
	twi_mtx_write_byte(SSD1306_Command);

	for (u16 i = 0; i < length; ++i) {
		twi_mtx_write_byte(pgm_read_byte(cmds + i));
	}

	twi_mtx_end();

	return;
}

static void ssd1306_data_list(const struct SSD1306* oled, u8* data, u16 length)
{
	twi_mtx_begin(oled->twi_addr);
	twi_mtx_write_byte(SSD1306_Data);

	for (u16 i = 0; i < length; ++i) {
		twi_mtx_write_byte(data[i]);
	}

	twi_mtx_end();

	return;
}

static void ssd1306_newline(struct SSD1306* oled)
{
	if (!oled) {
		return;
	}

	oled->cursor_x = 0;
	oled->cursor_y += oled->font_size;

	return;
}

static void ssd1306_advance_cursor(struct SSD1306* oled)
{
	if (!oled) {
		return;
	}

	oled->cursor_x += oled->font_size;
	if (oled->cursor_x >= SSD1306_BLOCK_COLUMNS) {
		ssd1306_newline(oled);
	}
	if (oled->cursor_y >= SSD1306_BLOCK_ROWS) {
		oled->cursor_y = 0;
	}

	return;
}

void ssd1306_init(struct SSD1306* oled, u8 twi_addr)
{
	if (!oled) {
		return;
	}

	oled->twi_addr  = twi_addr;
	oled->cursor_x  = SSD1306_COLUMN_START;
	oled->cursor_y  = SSD1306_PAGE_START;
	oled->font_size = FontSize_6x8;

#ifndef DEBUG
	_delay_ms(SSD1306_DELAY_POWER_ON);
#endif

	static const PROGMEM u8 init_cmds[] = {
			// Display off during configuration
			SSD1306_DisplayOff,

			// Set memory addressing mode to horizontal
			SSD1306_SetMemoryMode, 0x00,

			// Set display start line to top
			// SSD1306_SetDisplayStartLine | 0x00,

			// Set segment remap (column 127 mapped to SEG0)
			SSD1306_SegRemapFlip,

			// Set COM output scan direction (remapped mode)
			SSD1306_ComScanDec,

			// Set contrast control to default value
			// SSD1306_SetContrast, 0x7F,

			// Normal display (not inverted)
			// SSD1306_SetNormalDisplay,

			// Set multiplex ratio to 1/64 duty
			SSD1306_SetMultiplexRatio, 0x3F,

			// Set no display offset
			SSD1306_SetDisplayOffset, 0x00,

			// Set display clock divide ratio/oscillator frequency
			// to default value
			SSD1306_SetDisplayClockDiv, 0x80,

			// Set precharge period to default period
			SSD1306_SetPrecharge, 0xF1,

			// Alternative COM pin configuration
			SSD1306_SetComPins, 0x12,

			// Default VCOMH deselect level
			SSD1306_SetVcomDeselect, 0x40,

			// Enable charge pump
			SSD1306_ChargePump, SSD1306_ChargePumpEnable,

			// Display values from RAM
			SSD1306_DisplayRam,

			// Set column range to all columns
			SSD1306_SetColumnRange, SSD1306_COLUMN_START,
			SSD1306_COLUMN_END,

			// Set page range to all pages
			SSD1306_SetPageRange, SSD1306_PAGE_START,
			SSD1306_PAGE_END
	};

	ssd1306_command_list(oled, init_cmds, sizeof(init_cmds));

	// Start with blank display
	ssd1306_clear(oled);
	ssd1306_display(oled);

	// Display on after configuration
	ssd1306_command(oled, SSD1306_DisplayOn);

	return;
}

void ssd1306_set_cursor(struct SSD1306* oled, u8 row, u8 col)
{
	if (!oled) {
		return;
	}

	oled->cursor_x = col;
	oled->cursor_y = row;

	return;
}

void ssd1306_set_font(struct SSD1306* oled, enum FontSize font_size)
{
	if (!oled) {
		return;
	}

	oled->font_size = font_size;

	return;
}

void ssd1306_clear(const struct SSD1306* oled)
{
	if (!oled) {
		return;
	}

	memset((void*)oled->buffer, 0, SSD1306_BUFFER_SIZE);

	return;
}

void ssd1306_putc(struct SSD1306* oled, char c)
{
	if (!oled) {
		return;
	}

	if (c == '\n') {
		ssd1306_newline(oled);
		return;
	}

	if (c < ' ') {
		return;
	}

	const u8 font_width = BLOCK_WIDTH * oled->font_size;

	const u8* glyph = get_glyph(oled->font_size, c);
	for (u8 page_d = 0; page_d < oled->font_size; ++page_d) {
		for (u8 col_d = 0; col_d < oled->font_size; ++col_d) {
			for (u8 i = 0; i < SMALL_FONT_WIDTH; ++i) {
				const u8 page = oled->cursor_y + page_d;
				const u8 col  = (oled->cursor_x + col_d) *
						BLOCK_WIDTH + i;
				const u8* glyph_byte = glyph +
						page_d * font_width +
						col_d * BLOCK_WIDTH + i;
				oled->buffer[page][col] =
						pgm_read_byte(glyph_byte);
			}
		}
	}

#ifdef DEBUG
	for (u8 page_d = 0; page_d < oled->font_size; ++page_d) {
		for (u8 col_d = 0; col_d < oled->font_size; ++col_d) {
			oled->chars[oled->cursor_y + page_d]
				   [oled->cursor_x + col_d] = c;
		}
	}
#endif

	ssd1306_advance_cursor(oled);

	return;
}

void ssd1306_puts(struct SSD1306* oled, const char* s)
{
	if (!oled) {
		return;
	}

	for (const char* pc = s; *pc != '\0'; ++pc) {
		ssd1306_putc(oled, *pc);
	}

	return;
}

void ssd1306_display(const struct SSD1306* oled)
{
	if (!oled) {
		return;
	}

	static const PROGMEM u8 set_ranges[] = {
			// Set column range to all columns
			SSD1306_SetColumnRange, SSD1306_COLUMN_START,
			SSD1306_COLUMN_END,

			// Set page range to all pages
			SSD1306_SetPageRange, SSD1306_PAGE_START,
			SSD1306_PAGE_END
	};

	ssd1306_command_list(oled, set_ranges, sizeof(set_ranges));

	ssd1306_data_list(oled, (u8*)oled->buffer, SSD1306_BUFFER_SIZE);

	return;
}

