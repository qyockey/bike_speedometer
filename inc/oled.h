#ifndef __OLED_H
#define __OLED_H

#include "num_types.h"

#define DELAY_OLED_POWER_UP	(200)	// ms
#define BITS_PER_U8		(8)

#define OLED_BUFFER_SIZE(width, height)	\
	((((width) + BITS_PER_U8 - 1) / BITS_PER_U8) * (height))

struct SSD1306 {
	u8	twi_addr;
        u8	width;
        u8	height;
        u8*	buffer;
        u16	buffer_size;
	u8	buffer_index;
	u8	cursor_x;
	u8	cursor_y;
	u8	font_size;
};

u16 oled_buffer_size(u8 width, u8 height);
void oled_init(
	struct	SSD1306* oled,
	u8	twi_addr,
	u8 	width,
	u8 	height,
	u8*	buf
);
void oled_set_cursor(struct SSD1306* oled, u8 row, u8 col);
void oled_set_font_size(struct SSD1306* oled, u8 size);
void oled_clear_display(struct SSD1306* oled);
void oled_putc(struct SSD1306* oled, char c);
void oled_puts(struct SSD1306* oled, const char *s);
void oled_display(const struct SSD1306* oled);

void oled_test(struct SSD1306* oled);

#endif // __OLED_H

