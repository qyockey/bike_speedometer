#ifndef __SSD1306_H
#define __SSD1306_H

#include "num_types.h"

#define BITS_PER_U8		(8)
#define SSD1306_COLUMNS		(128)
#define SSD1306_ROWS		(64)
#define SSD1306_PAGES		((SSD1306_ROWS + BITS_PER_U8 - 1) / BITS_PER_U8)
#define SSD1306_BUFFER_SIZE	(SSD1306_COLUMNS * SSD1306_PAGES)

enum SSD1306_Font {
	SSD1306_Font6x8		= 1,
	SSD1306_Font12x16	= 2,
};

struct SSD1306 {
	u8	twi_addr;
        u8	buffer[SSD1306_COLUMNS][SSD1306_PAGES];
	u8	cursor_x;
	u8	cursor_y;
	enum	SSD1306_Font font_size;
};

void ssd1306_init(struct SSD1306* oled, u8 twi_addr);
void ssd1306_set_cursor(struct SSD1306* oled, u8 row, u8 col);
void ssd1306_set_font(struct SSD1306* oled, enum SSD1306_Font font);
void ssd1306_clear(const struct SSD1306* oled);
void ssd1306_putc(struct SSD1306* oled, char c);
void ssd1306_puts(struct SSD1306* oled, const char *s);
void ssd1306_display(const struct SSD1306* oled);

#endif // __SSD1306_H

