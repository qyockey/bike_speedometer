#ifndef __FONT_H
#define __FONT_H

#include "num_types.h"

#define BLOCK_WIDTH        (6)
#define BLOCK_HEIGHT       (8)

#define SMALL_FONT_WIDTH   (FontSize_6x8 * BLOCK_WIDTH)
#define SMALL_FONT_HEIGHT  (FontSize_6x8 * BLOCK_HEIGHT)

#define MEDIUM_FONT_WIDTH  (FontSize_12x16 * BLOCK_WIDTH)
#define MEDIUM_FONT_HEIGHT (FontSize_12x16 * BLOCK_HEIGHT)

#define LARGE_FONT_WIDTH   (FontSize_18x24 * BLOCK_WIDTH)
#define LARGE_FONT_HEIGHT  (FontSize_18x24 * BLOCK_HEIGHT)

enum FontSize {
	FontSize_6x8   = 1,
	FontSize_12x16 = 2,
	FontSize_18x24 = 3,
};

const u8* get_glyph(enum FontSize font_size, char c);

#endif // __FONT_H

