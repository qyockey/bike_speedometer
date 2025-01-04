#ifndef __FONT_H
#define __FONT_H

#include "num_types.h"

#define SMALL_FONT_WIDTH  (6)
#define SMALL_FONT_HEIGHT (8)

#define LARGE_FONT_WIDTH  (12)
#define LARGE_FONT_HEIGHT (16)

#define TEXT_WIDTH        (SMALL_FONT_WIDTH)
#define TEXT_HEIGHT       (SMALL_FONT_HEIGHT)

enum FontSize {
	FontSize_6x8   = 1,
	FontSize_12x16 = 2,
};

const u8* get_glyph(enum FontSize font_size, char c);

#endif // __FONT_H

