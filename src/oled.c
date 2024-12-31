#include <avr/io.h>
#include <util/delay.h>

#include "../inc/num_types.h"
#include "../inc/oled.h"
#include "../inc/twi.h"

#define OLED_DELAY_POWER_ON	(2500)
#define OLED_DEFAULT_CURSOR_X	(0)
#define OLED_DEFAULT_CURSOR_Y 	(0)
#define OLED_DEFAULT_BUFFER_IDX	(0)
#define OLED_DEFAULT_FONT_SIZE 	(1)

enum SSD1306_Command {
	SSD1306_SetMemoryMode		= 0x20,
	SSD1306_SetColumnAddr		= 0x21,
	SSD1306_SetPageAddr		= 0x22,
	SSD1306_ScrollDisable		= 0x2E,
	SSD1306_ScrollEnable		= 0x2F,
	SSD1306_SetDisplayStartLine	= 0x40,
	SSD1306_SetContrast		= 0x81,
	SSD1306_ChargePump		= 0x8D,
	SSD1306_SegRemap		= 0xA0,
	SSD1306_DisplayRamResume	= 0xA4,
	SSD1306_DisplayAllOn		= 0xA5,
	SSD1306_SetNormalDisplay	= 0xA6,
	SSD1306_SetInvertDisplay	= 0xA7,
	SSD1306_SetMultiplexRatio	= 0xA8,
	SSD1306_DisplayOff		= 0xAE,
	SSD1306_DisplayOn		= 0xAF,
	SSD1306_ComScanInc		= 0xC0,
	SSD1306_ComScanDec		= 0xC8,
	SSD1306_SetDisplayOffset	= 0xD3,
	SSD1306_SetDisplayClockDiv	= 0xD5,
	SSD1306_SetPrecharge		= 0xD9,
	SSD1306_SetComPins		= 0xDA,
	SSD1306_SetVcomDetect		= 0xDB,
};

enum SSD1306_Control {
	SSD1306_Command			= 0x00,
	SSD1306_Data   			= 0x40,
};

static u16 buffer_index(u8 row_width, u8 row, u8 col);

static u16 buffer_index(u8 row_width, u8 row, u8 col)
{
	return (u16) row * (u16) row_width +
		(((u16) col + BITS_PER_U8 - 1) / BITS_PER_U8);
}

void oled_init(
	struct	SSD1306* oled,
	u8	twi_addr,
	u8 	width,
	u8 	height,
	u8*	buf
) {
	if (!oled) {
		return;
	}

	oled->twi_addr = twi_addr;
	oled->width = width;
	oled->height = height;
	oled->buffer = buf;
	oled->buffer_size = OLED_BUFFER_SIZE(width, height);
	oled->buffer_index = OLED_DEFAULT_BUFFER_IDX;
	oled->cursor_x = OLED_DEFAULT_CURSOR_X;
	oled->cursor_y = OLED_DEFAULT_CURSOR_Y;
	oled->font_size = OLED_DEFAULT_FONT_SIZE;

	_delay_ms(OLED_DELAY_POWER_ON);

	twi_mtx_begin(oled->twi_addr);
	twi_mtx_write_byte(SSD1306_Command);
	twi_mtx_write_byte(SSD1306_DisplayOff);
	twi_mtx_write_byte(SSD1306_SetDisplayClockDiv);
	twi_mtx_write_byte(0x80);  // Suggested ratio
	twi_mtx_write_byte(SSD1306_SetMultiplexRatio);
	twi_mtx_write_byte(oled->height - 1);
	twi_mtx_write_byte(SSD1306_SetDisplayOffset);
	twi_mtx_write_byte(0x00);  // No offset
	twi_mtx_write_byte(SSD1306_SetDisplayStartLine | 0x00);  // Line 0
	twi_mtx_write_byte(SSD1306_ChargePump);
	twi_mtx_write_byte(0x14);  // Enable charge pump
	twi_mtx_write_byte(SSD1306_SetMemoryMode);
	twi_mtx_write_byte(0x02);  // Page mode hopefully
	// twi_mtx_write_byte(SSD1306_SegRemap | 0x01);
	// twi_mtx_write_byte(SSD1306_ComScanInc);
	twi_mtx_write_byte(SSD1306_SetComPins);
	twi_mtx_write_byte(0x12);  // Adafruit says so
	twi_mtx_write_byte(SSD1306_SetContrast);
	twi_mtx_write_byte(0x7F);  // Adafruit says so
	twi_mtx_write_byte(SSD1306_SetPrecharge);
	twi_mtx_write_byte(0xF1);  // Adafruit says so
	twi_mtx_write_byte(SSD1306_SetVcomDetect);
	twi_mtx_write_byte(0x40);  // Adafruit says so
	twi_mtx_write_byte(SSD1306_DisplayRamResume);
	twi_mtx_write_byte(SSD1306_SetNormalDisplay);
	// twi_mtx_write_byte(SSD1306_DeactivateScroll);
	twi_mtx_write_byte(SSD1306_DisplayOn);
	twi_mtx_end();

	// ...

	return;
}

void oled_set_cursor(struct SSD1306* oled, u8 row, u8 col)
{
	if (!oled) {
		return;
	}

	oled->cursor_x = col;
	oled->cursor_y = row;
	oled->buffer_index = buffer_index(oled->width, row, col);

	return;
}

void oled_set_font_size(struct SSD1306* oled, u8 size)
{
	if (!oled) {
		return;
	}

	oled->font_size = size;

	return;
}

void oled_clear_display(struct SSD1306* oled)
{
	if (!oled) {
		return;
	}

	return;
}

void oled_putc(struct SSD1306* oled, char c)
{
	if (!oled) {
		return;
	}

	(void) c;

	return;
}

void oled_puts(struct SSD1306* oled, const char *s)
{
	if (!oled) {
		return;
	}

	(void) s;

	return;
}

void oled_display(const struct SSD1306* oled)
{
	if (!oled) {
		return;
	}

	return;
}


// /* Print a two digit number to OLED display, padding with a 0 if under 10 */
// void oled_print_padded(u8 val)
// {
// 	if (val < 10) {
// 		oled.print("0");
// 	}
// 	oled.print(val, DEC);
// }

// /* Update quantities displayed on OLED */
// void oled_update(
// 	f64 velocity_sample,
// 	f64 velocity_average,
// 	f64 distance,
// 	u32 seconds,
// 	u32 minutes,
// 	u32 pulses
// ) {
// 	oled.clearDisplay();
// 
// #ifdef NO_PRETTY 
// 	oled.setCursor(0, 0);
// 
// 	oled.print(velocity_sample);
// 	oled.println(" kph");
// 
// 	oled.print(velocity_average);
// 	oled.println(" kph avg");
// 
// 	oled.print(distance);
// 	oled.println(" km");
// 
// 	oled_print_padded(minutes);
// 	oled.print(":");
// 	oled_print_padded(seconds);
// 	oled.println();
// 
// 	oled.print(pulses);
// 	oled.println(" pulses");
// 
// #else
// 	oled.setCursor(6, 8);
// 	oled.setTextSize(3);
// 	oled_print_padded((u8) velocity_sample);
// 	oled.setTextSize(1);
// 	oled.setCursor(7 * 6, 1 * 8);
// 	oled.print("k");
// 	oled.setCursor(7 * 6, 2 * 8 - 1);
// 	oled.print("p");
// 	oled.setCursor(7 * 6, 3 * 8);
// 	oled.print("h");
// 	
// 	oled.setCursor(1 * 6, 5 * 8);
// 	oled.setTextSize(2);
// 	oled_print_padded((u8) velocity_average);
// 	oled.setTextSize(1);
// 	oled.print("kph");
// 	oled.setCursor(5 * 6, 6 * 8);
// 	oled.print("avg");
// 	
// 	oled.setCursor(10 * 6, 1 * 8 + 4);
// 	oled.setTextSize(2);
// 	oled_print_padded((u8) distance);
// 	oled.print(".");
// 	oled.print(((u8) (10 * distance)) % 10, DEC);
// 	oled.setCursor(18 * 6, 2 * 8);
// 	oled.setTextSize(1);
// 	oled.print("km");
// 	
// 	oled.setCursor(10 * 6, 5 * 8);
// 	oled.setTextSize(2);
// 	oled_print_padded(minutes);
// 	oled.print(":");
// 	oled_print_padded(seconds);
// #endif
// 	
// 	oled.display();
// }

// /* Initialize OLED displau */
// void oled_init()
// {
// 	delay(DELAY_OLED_POWER_UP);	// Allow OLED millis_elapsed to power up
// 
// 	if(!oled.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
// 		error();
// 	}
// 
// 	oled.clearDisplay();
// 	oled.setTextColor(SSD1306_WHITE);
// }

void oled_test(struct SSD1306* oled)
{
	twi_mtx_begin(oled->twi_addr);
	twi_mtx_write_byte(SSD1306_Data);
	twi_mtx_write_byte(0xFF);
	twi_mtx_end();

	_delay_ms(1000);

	twi_mtx_begin(oled->twi_addr);
	twi_mtx_write_byte(SSD1306_Command);
	twi_mtx_write_byte(SSD1306_DisplayAllOn);
	twi_mtx_end();

	_delay_ms(1000);

	twi_mtx_begin(oled->twi_addr);
	twi_mtx_write_byte(SSD1306_Command);
	twi_mtx_write_byte(SSD1306_DisplayRamResume);
	twi_mtx_end();

	_delay_ms(1000);
}

