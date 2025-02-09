#include "../inc/font.h"
#include "../inc/num_types.h"
#include <avr/io.h>
#include <avr/pgmspace.h>

#define FONT_BITMAP_OFFSET (' ') // Start bitmap at Space, ignore control codes

const u8 font_6x8[][SMALL_FONT_WIDTH] PROGMEM = {
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // Space (0x20)
		{0x00, 0x00, 0x5F, 0x00, 0x00, 0x00}, // ! (0x21)
		{0x00, 0x07, 0x00, 0x07, 0x00, 0x00}, // " (0x22)
		{0x14, 0x7F, 0x14, 0x7F, 0x14, 0x00}, // # (0x23)
		{0x24, 0x2A, 0x7F, 0x2A, 0x12, 0x00}, // $ (0x24)
		{0x23, 0x13, 0x08, 0x64, 0x62, 0x00}, // % (0x25)
		{0x36, 0x49, 0x55, 0x22, 0x50, 0x00}, // & (0x26)
		{0x00, 0x05, 0x03, 0x00, 0x00, 0x00}, // ' (0x27)
		{0x00, 0x1C, 0x22, 0x41, 0x00, 0x00}, // ( (0x28)
		{0x00, 0x41, 0x22, 0x1C, 0x00, 0x00}, // ) (0x29)
		{0x14, 0x08, 0x3E, 0x08, 0x14, 0x00}, // * (0x2A)
		{0x08, 0x08, 0x3E, 0x08, 0x08, 0x00}, // + (0x2B)
		{0x00, 0x50, 0x30, 0x00, 0x00, 0x00}, // , (0x2C)
		{0x08, 0x08, 0x08, 0x08, 0x08, 0x00}, // - (0x2D)
		{0x00, 0x60, 0x60, 0x00, 0x00, 0x00}, // . (0x2E)
		{0x20, 0x10, 0x08, 0x04, 0x02, 0x00}, // / (0x2F)
		{0x3E, 0x51, 0x49, 0x45, 0x3E, 0x00}, // 0 (0x30)
		{0x00, 0x42, 0x7F, 0x40, 0x00, 0x00}, // 1 (0x31)
		{0x42, 0x61, 0x51, 0x49, 0x46, 0x00}, // 2 (0x32)
		{0x21, 0x41, 0x45, 0x4B, 0x31, 0x00}, // 3 (0x33)
		{0x18, 0x14, 0x12, 0x7F, 0x10, 0x00}, // 4 (0x34)
		{0x27, 0x45, 0x45, 0x45, 0x39, 0x00}, // 5 (0x35)
		{0x3C, 0x4A, 0x49, 0x49, 0x30, 0x00}, // 6 (0x36)
		{0x01, 0x71, 0x09, 0x05, 0x03, 0x00}, // 7 (0x37)
		{0x36, 0x49, 0x49, 0x49, 0x36, 0x00}, // 8 (0x38)
		{0x06, 0x49, 0x49, 0x29, 0x1E, 0x00}, // 9 (0x39)
		{0x00, 0x36, 0x36, 0x00, 0x00, 0x00}, // : (0x3A)
		{0x00, 0x56, 0x36, 0x00, 0x00, 0x00}, // ; (0x3B)
		{0x08, 0x14, 0x22, 0x41, 0x00, 0x00}, // < (0x3C)
		{0x14, 0x14, 0x14, 0x14, 0x14, 0x00}, // = (0x3D)
		{0x00, 0x41, 0x22, 0x14, 0x08, 0x00}, // > (0x3E)
		{0x02, 0x01, 0x51, 0x09, 0x06, 0x00}, // ? (0x3F)
		{0x32, 0x49, 0x79, 0x41, 0x3E, 0x00}, // @ (0x40)
		{0x7E, 0x11, 0x11, 0x11, 0x7E, 0x00}, // A (0x41)
		{0x7F, 0x49, 0x49, 0x49, 0x36, 0x00}, // B (0x42)
		{0x3E, 0x41, 0x41, 0x41, 0x22, 0x00}, // C (0x43)
		{0x7F, 0x41, 0x41, 0x22, 0x1C, 0x00}, // D (0x44)
		{0x7F, 0x49, 0x49, 0x49, 0x41, 0x00}, // E (0x45)
		{0x7F, 0x09, 0x09, 0x09, 0x01, 0x00}, // F (0x46)
		{0x3E, 0x41, 0x49, 0x49, 0x7A, 0x00}, // G (0x47)
		{0x7F, 0x08, 0x08, 0x08, 0x7F, 0x00}, // H (0x48)
		{0x00, 0x41, 0x7F, 0x41, 0x00, 0x00}, // I (0x49)
		{0x20, 0x40, 0x41, 0x3F, 0x01, 0x00}, // J (0x4A)
		{0x7F, 0x08, 0x14, 0x22, 0x41, 0x00}, // K (0x4B)
		{0x7F, 0x40, 0x40, 0x40, 0x40, 0x00}, // L (0x4C)
		{0x7F, 0x02, 0x0C, 0x02, 0x7F, 0x00}, // M (0x4D)
		{0x7F, 0x04, 0x08, 0x10, 0x7F, 0x00}, // N (0x4E)
		{0x3E, 0x41, 0x41, 0x41, 0x3E, 0x00}, // O (0x4F)
		{0x7F, 0x09, 0x09, 0x09, 0x06, 0x00}, // P (0x50)
		{0x3E, 0x41, 0x51, 0x21, 0x5E, 0x00}, // Q (0x51)
		{0x7F, 0x09, 0x19, 0x29, 0x46, 0x00}, // R (0x52)
		{0x46, 0x49, 0x49, 0x49, 0x31, 0x00}, // S (0x53)
		{0x01, 0x01, 0x7F, 0x01, 0x01, 0x00}, // T (0x54)
		{0x3F, 0x40, 0x40, 0x40, 0x3F, 0x00}, // U (0x55)
		{0x1F, 0x20, 0x40, 0x20, 0x1F, 0x00}, // V (0x56)
		{0x3F, 0x40, 0x38, 0x40, 0x3F, 0x00}, // W (0x57)
		{0x63, 0x14, 0x08, 0x14, 0x63, 0x00}, // X (0x58)
		{0x07, 0x08, 0x70, 0x08, 0x07, 0x00}, // Y (0x59)
		{0x61, 0x51, 0x49, 0x45, 0x43, 0x00}, // Z (0x5A)
		{0x00, 0x7F, 0x41, 0x41, 0x00, 0x00}, // [ (0x5B)
		{0x02, 0x04, 0x08, 0x10, 0x20, 0x00}, // \ (0x5C)
		{0x00, 0x41, 0x41, 0x7F, 0x00, 0x00}, // ] (0x5D)
		{0x04, 0x02, 0x01, 0x02, 0x04, 0x00}, // ^ (0x5E)
		{0x40, 0x40, 0x40, 0x40, 0x40, 0x00}, // _ (0x5F)
		{0x00, 0x01, 0x02, 0x04, 0x00, 0x00}, // ` (0x60)
		{0x20, 0x54, 0x54, 0x54, 0x78, 0x00}, // a (0x61)
		{0x7F, 0x48, 0x44, 0x44, 0x38, 0x00}, // b (0x62)
		{0x38, 0x44, 0x44, 0x44, 0x20, 0x00}, // c (0x63)
		{0x38, 0x44, 0x44, 0x48, 0x7F, 0x00}, // d (0x64)
		{0x38, 0x54, 0x54, 0x54, 0x18, 0x00}, // e (0x65)
		{0x08, 0x7E, 0x09, 0x01, 0x02, 0x00}, // f (0x66)
		{0x0C, 0x52, 0x52, 0x52, 0x3E, 0x00}, // g (0x67)
		{0x7F, 0x08, 0x04, 0x04, 0x78, 0x00}, // h (0x68)
		{0x00, 0x44, 0x7D, 0x40, 0x00, 0x00}, // i (0x69)
		{0x20, 0x40, 0x44, 0x3D, 0x00, 0x00}, // j (0x6A)
		{0x7F, 0x10, 0x28, 0x44, 0x00, 0x00}, // k (0x6B)
		{0x00, 0x41, 0x7F, 0x40, 0x00, 0x00}, // l (0x6C)
		{0x7C, 0x04, 0x18, 0x04, 0x78, 0x00}, // m (0x6D)
		{0x7C, 0x08, 0x04, 0x04, 0x78, 0x00}, // n (0x6E)
		{0x38, 0x44, 0x44, 0x44, 0x38, 0x00}, // o (0x6F)
		{0x7C, 0x14, 0x14, 0x14, 0x08, 0x00}, // p (0x70)
		{0x08, 0x14, 0x14, 0x18, 0x7C, 0x00}, // q (0x71)
		{0x7C, 0x08, 0x04, 0x04, 0x08, 0x00}, // r (0x72)
		{0x48, 0x54, 0x54, 0x54, 0x20, 0x00}, // s (0x73)
		{0x04, 0x3F, 0x44, 0x40, 0x20, 0x00}, // t (0x74)
		{0x3C, 0x40, 0x40, 0x20, 0x7C, 0x00}, // u (0x75)
		{0x1C, 0x20, 0x40, 0x20, 0x1C, 0x00}, // v (0x76)
		{0x3C, 0x40, 0x30, 0x40, 0x3C, 0x00}, // w (0x77)
		{0x44, 0x28, 0x10, 0x28, 0x44, 0x00}, // x (0x78)
		{0x0C, 0x50, 0x50, 0x50, 0x3C, 0x00}, // y (0x79)
		{0x44, 0x64, 0x54, 0x4C, 0x44, 0x00}, // z (0x7A)
		{0x00, 0x08, 0x36, 0x41, 0x00, 0x00}, // { (0x7B)
		{0x00, 0x00, 0x7F, 0x00, 0x00, 0x00}, // | (0x7C)
		{0x00, 0x41, 0x36, 0x08, 0x00, 0x00}, // } (0x7D)
		{0x10, 0x08, 0x08, 0x10, 0x08, 0x00}, // ~ (0x7E)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // DEL (0x7F)
};

const u8 font_12x16[][FontSize_12x16 * FontSize_12x16 * BLOCK_WIDTH] PROGMEM = {
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ␣ (0x20)
		{0x00, 0x00, 0x00, 0x7C, 0xFF, 0xFF, 0x7C, 0x00,
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                 0x33, 0x33, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ! (0x21)
		{0x00, 0x00, 0x3C, 0x3C, 0x00, 0x00, 0x3C, 0x3C,
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // " (0x22)
		{0x00, 0x10, 0x90, 0xF0, 0x7E, 0x1E, 0x90, 0xF0,
                 0x7E, 0x1E, 0x10, 0x00, 0x02, 0x1E, 0x1F, 0x03,
                 0x02, 0x1E, 0x1F, 0x03, 0x02, 0x00, 0x00, 0x00}, // # (0x23)
		{0x00, 0x78, 0xFC, 0xCC, 0xFF, 0xFF, 0xCC, 0xCC,
                 0x88, 0x00, 0x00, 0x00, 0x00, 0x04, 0x0C, 0x0C,
                 0x3F, 0x3F, 0x0C, 0x0F, 0x07, 0x00, 0x00, 0x00}, // $ (0x24)
		{0x00, 0x38, 0x38, 0x38, 0x00, 0x80, 0xC0, 0xE0,
                 0x70, 0x38, 0x1C, 0x00, 0x30, 0x38, 0x1C, 0x0E,
                 0x07, 0x03, 0x01, 0x38, 0x38, 0x38, 0x00, 0x00}, // % (0x25)
		{0x00, 0x00, 0xB8, 0xFC, 0xC6, 0xE2, 0x3E, 0x1C,
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x3F, 0x31,
                 0x21, 0x37, 0x1E, 0x1C, 0x36, 0x22, 0x00, 0x00}, // & (0x26)
		{0x00, 0x00, 0x00, 0x27, 0x3F, 0x1F, 0x00, 0x00,
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ' (0x27)
		{0x00, 0x00, 0xF0, 0xFC, 0xFE, 0x07, 0x01, 0x01,
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0F,
                 0x1F, 0x38, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00}, // ( (0x28)
		{0x00, 0x00, 0x01, 0x01, 0x07, 0xFE, 0xFC, 0xF0,
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20,
                 0x38, 0x1F, 0x0F, 0x03, 0x00, 0x00, 0x00, 0x00}, // ) (0x29)
		{0x00, 0x98, 0xB8, 0xE0, 0xF8, 0xF8, 0xE0, 0xB8,
                 0x98, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x0E, 0x03,
                 0x0F, 0x0F, 0x03, 0x0E, 0x0C, 0x00, 0x00, 0x00}, // * (0x2A)
		{0x00, 0x80, 0x80, 0x80, 0xF0, 0xF0, 0x80, 0x80,
                 0x80, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01,
                 0x0F, 0x0F, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00}, // + (0x2B)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB8,
                 0xF8, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // , (0x2C)
		{0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
                 0x80, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01,
                 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00}, // - (0x2D)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38,
                 0x38, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // . (0x2E)
		{0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0x70,
                 0x38, 0x1C, 0x0E, 0x00, 0x18, 0x1C, 0x0E, 0x07,
                 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // / (0x2F)
		{0xE0, 0xF8, 0x3C, 0x0E, 0x06, 0x86, 0xC6, 0x66,
                 0x3C, 0xFC, 0xF0, 0x00, 0x0F, 0x3F, 0x3C, 0x66,
                 0x63, 0x61, 0x60, 0x70, 0x3C, 0x0F, 0x03, 0x00}, // 0 (0x30)
		{0x00, 0x00, 0x30, 0x18, 0x0C, 0xFE, 0xFE, 0x02,
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x60,
                 0x60, 0x7F, 0x7F, 0x60, 0x60, 0x20, 0x00, 0x00}, // 1 (0x31)
		{0x30, 0x1C, 0x0E, 0x06, 0x06, 0x06, 0x06, 0x86,
                 0xCE, 0xFC, 0x78, 0x00, 0x30, 0x78, 0x7C, 0x6E,
                 0x66, 0x63, 0x63, 0x61, 0x61, 0x20, 0x10, 0x00}, // 2 (0x32)
		{0x18, 0x0C, 0x0C, 0x06, 0x86, 0x86, 0x86, 0xC6,
                 0xEC, 0x7C, 0x38, 0x00, 0x18, 0x30, 0x60, 0x60,
                 0x60, 0x60, 0x61, 0x61, 0x73, 0x3F, 0x1E, 0x00}, // 3 (0x33)
		{0x80, 0xC0, 0xE0, 0x70, 0x38, 0x0C, 0x06, 0xF2,
                 0xF8, 0x00, 0x00, 0x00, 0x03, 0x07, 0x06, 0x06,
                 0x06, 0x06, 0x06, 0x3F, 0x7F, 0x06, 0x02, 0x00}, // 4 (0x34)
		{0x7C, 0xFE, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6,
                 0xC6, 0x82, 0x02, 0x00, 0x1C, 0x30, 0x70, 0x60,
                 0x60, 0x60, 0x60, 0x60, 0x71, 0x3F, 0x1F, 0x00}, // 5 (0x35)
		{0x80, 0xE0, 0xF8, 0x9C, 0x86, 0x86, 0x82, 0x82,
                 0x80, 0x00, 0x00, 0x00, 0x1F, 0x3F, 0x73, 0x61,
                 0x61, 0x61, 0x61, 0x61, 0x73, 0x3F, 0x1E, 0x00}, // 6 (0x36)
		{0x02, 0x02, 0x06, 0x06, 0x06, 0x06, 0x86, 0xE6,
                 0x7E, 0x1E, 0x04, 0x00, 0x00, 0x00, 0x00, 0x60,
                 0x38, 0x1E, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00}, // 7 (0x37)
		{0x00, 0x70, 0xFC, 0xCE, 0x86, 0x86, 0x86, 0xCE,
                 0xFC, 0x70, 0x00, 0x00, 0x1C, 0x3F, 0x73, 0x61,
                 0x61, 0x61, 0x61, 0x61, 0x73, 0x3F, 0x0E, 0x00}, // 8 (0x38)
		{0x78, 0xFC, 0xCE, 0x86, 0x86, 0x86, 0x86, 0x86,
                 0xCE, 0xFC, 0xF8, 0x00, 0x00, 0x00, 0x01, 0x41,
                 0x41, 0x61, 0x61, 0x39, 0x1F, 0x07, 0x01, 0x00}, // 9 (0x39)
		{0x00, 0x00, 0x00, 0x70, 0x70, 0x70, 0x00, 0x00,
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1C,
                 0x1C, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // : (0x3A)
		{0x00, 0x00, 0x00, 0x70, 0x70, 0x70, 0x00, 0x00,
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9C,
                 0xFC, 0x7C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ; (0x3B)
		{0x00, 0xC0, 0xE0, 0xF0, 0x38, 0x1C, 0x0E, 0x07,
                 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03,
                 0x07, 0x0E, 0x1C, 0x38, 0x30, 0x00, 0x00, 0x00}, // < (0x3C)
		{0x00, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60,
                 0x60, 0x60, 0x00, 0x00, 0x00, 0x06, 0x06, 0x06,
                 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x00, 0x00}, // = (0x3D)
		{0x00, 0x03, 0x07, 0x0E, 0x1C, 0x38, 0xF0, 0xE0,
                 0xC0, 0x00, 0x00, 0x00, 0x00, 0x30, 0x38, 0x1C,
                 0x0E, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00}, // > (0x3E)
		{0x1C, 0x1E, 0x07, 0x03, 0x83, 0xC3, 0xE3, 0x77,
                 0x3E, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                 0x37, 0x37, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ? (0x3F)
		{0xF8, 0xFE, 0x07, 0xF3, 0xFB, 0x1B, 0xFB, 0xFB,
                 0x07, 0xFE, 0xF8, 0x00, 0x0F, 0x1F, 0x18, 0x33,
                 0x37, 0x36, 0x37, 0x37, 0x36, 0x03, 0x01, 0x00}, // @ (0x40)
		{0x00, 0x00, 0xE0, 0xFC, 0x1F, 0x1F, 0xFC, 0xE0,
                 0x00, 0x00, 0x00, 0x00, 0x38, 0x3F, 0x07, 0x06,
                 0x06, 0x06, 0x06, 0x07, 0x3F, 0x38, 0x00, 0x00}, // A (0x41)
		{0xFF, 0xFF, 0xC3, 0xC3, 0xC3, 0xC3, 0xE7, 0xFE,
                 0xBC, 0x00, 0x00, 0x00, 0x3F, 0x3F, 0x30, 0x30,
                 0x30, 0x30, 0x30, 0x39, 0x1F, 0x0F, 0x00, 0x00}, // B (0x42)
		{0xF0, 0xFC, 0x0E, 0x07, 0x03, 0x03, 0x03, 0x07,
                 0x0E, 0x0C, 0x00, 0x00, 0x03, 0x0F, 0x1C, 0x38,
                 0x30, 0x30, 0x30, 0x38, 0x1C, 0x0C, 0x00, 0x00}, // C (0x43)
		{0xFF, 0xFF, 0x03, 0x03, 0x03, 0x03, 0x07, 0x0E,
                 0xFC, 0xF0, 0x00, 0x00, 0x3F, 0x3F, 0x30, 0x30,
                 0x30, 0x30, 0x38, 0x1C, 0x0F, 0x03, 0x00, 0x00}, // D (0x44)
		{0xFF, 0xFF, 0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 0xC3,
                 0x03, 0x03, 0x00, 0x00, 0x3F, 0x3F, 0x30, 0x30,
                 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x00, 0x00}, // E (0x45)
		{0xFF, 0xFF, 0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 0xC3,
                 0x03, 0x03, 0x00, 0x00, 0x3F, 0x3F, 0x00, 0x00,
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // F (0x46)
		{0xF0, 0xFC, 0x0E, 0x07, 0x03, 0xC3, 0xC3, 0xC3,
                 0xC7, 0xC6, 0x00, 0x00, 0x03, 0x0F, 0x1C, 0x38,
                 0x30, 0x30, 0x30, 0x30, 0x3F, 0x3F, 0x00, 0x00}, // G (0x47)
		{0xFF, 0xFF, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0,
                 0xFF, 0xFF, 0x00, 0x00, 0x3F, 0x3F, 0x00, 0x00,
                 0x00, 0x00, 0x00, 0x00, 0x3F, 0x3F, 0x00, 0x00}, // H (0x48)
		{0x00, 0x00, 0x03, 0x03, 0xFF, 0xFF, 0x03, 0x03,
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30,
                 0x3F, 0x3F, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00}, // I (0x49)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                 0xFF, 0xFF, 0x00, 0x00, 0x0E, 0x1E, 0x38, 0x30,
                 0x30, 0x30, 0x30, 0x38, 0x1F, 0x07, 0x00, 0x00}, // J (0x4A)
		{0xFF, 0xFF, 0xC0, 0xE0, 0xF0, 0x38, 0x1C, 0x0E,
                 0x07, 0x03, 0x00, 0x00, 0x3F, 0x3F, 0x00, 0x01,
                 0x03, 0x07, 0x0E, 0x1C, 0x38, 0x30, 0x00, 0x00}, // K (0x4B)
		{0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                 0x00, 0x00, 0x00, 0x00, 0x3F, 0x3F, 0x30, 0x30,
                 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x00, 0x00}, // L (0x4C)
		{0xFF, 0xFF, 0x1E, 0x78, 0xE0, 0xE0, 0x78, 0x1E,
                 0xFF, 0xFF, 0x00, 0x00, 0x3F, 0x3F, 0x00, 0x00,
                 0x01, 0x01, 0x00, 0x00, 0x3F, 0x3F, 0x00, 0x00}, // M (0x4D)
		{0xFF, 0xFF, 0x0E, 0x38, 0xF0, 0xC0, 0x00, 0x00,
                 0xFF, 0xFF, 0x00, 0x00, 0x3F, 0x3F, 0x00, 0x00,
                 0x00, 0x03, 0x07, 0x1C, 0x3F, 0x3F, 0x00, 0x00}, // N (0x4E)
		{0xF0, 0xFC, 0x0E, 0x07, 0x03, 0x03, 0x07, 0x0E,
                 0xFC, 0xF0, 0x00, 0x00, 0x03, 0x0F, 0x1C, 0x38,
                 0x30, 0x30, 0x38, 0x1C, 0x0F, 0x03, 0x00, 0x00}, // O (0x4F)
		{0xFF, 0xFF, 0x83, 0x83, 0x83, 0x83, 0x83, 0xC7,
                 0xFE, 0x7C, 0x00, 0x00, 0x3F, 0x3F, 0x01, 0x01,
                 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00}, // P (0x50)
		{0xF0, 0xFC, 0x0E, 0x07, 0x03, 0x03, 0x07, 0x0E,
                 0xFC, 0xF0, 0x00, 0x00, 0x03, 0x0F, 0x1C, 0x38,
                 0x30, 0x36, 0x3E, 0x1C, 0x3F, 0x33, 0x00, 0x00}, // Q (0x51)
		{0xFF, 0xFF, 0x83, 0x83, 0x83, 0x83, 0x83, 0xC7,
                 0xFE, 0x7C, 0x00, 0x00, 0x3F, 0x3F, 0x01, 0x01,
                 0x03, 0x07, 0x0F, 0x1D, 0x38, 0x30, 0x00, 0x00}, // R (0x52)
		{0x3C, 0x7E, 0xE7, 0xC3, 0xC3, 0xC3, 0xC3, 0xC7,
                 0x8E, 0x0C, 0x00, 0x00, 0x0C, 0x1C, 0x38, 0x30,
                 0x30, 0x30, 0x30, 0x39, 0x1F, 0x0F, 0x00, 0x00}, // S (0x53)
		{0x00, 0x03, 0x03, 0x03, 0xFF, 0xFF, 0x03, 0x03,
                 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // T (0x54)
		{0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                 0xFF, 0xFF, 0x00, 0x00, 0x07, 0x1F, 0x38, 0x30,
                 0x30, 0x30, 0x30, 0x38, 0x1F, 0x07, 0x00, 0x00}, // U (0x55)
		{0x07, 0x3F, 0xF8, 0xC0, 0x00, 0x00, 0xC0, 0xF8,
                 0x3F, 0x07, 0x00, 0x00, 0x00, 0x00, 0x01, 0x0F,
                 0x3E, 0x3E, 0x0F, 0x01, 0x00, 0x00, 0x00, 0x00}, // V (0x56)
		{0xFF, 0xFF, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00,
                 0xFF, 0xFF, 0x00, 0x00, 0x3F, 0x3F, 0x1C, 0x06,
                 0x03, 0x03, 0x06, 0x1C, 0x3F, 0x3F, 0x00, 0x00}, // W (0x57)
		{0x03, 0x0F, 0x1C, 0x30, 0xE0, 0xE0, 0x30, 0x1C,
                 0x0F, 0x03, 0x00, 0x00, 0x30, 0x3C, 0x0E, 0x03,
                 0x01, 0x01, 0x03, 0x0E, 0x3C, 0x30, 0x00, 0x00}, // X (0x58)
		{0x03, 0x0F, 0x3C, 0xF0, 0xC0, 0xC0, 0xF0, 0x3C,
                 0x0F, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // Y (0x59)
		{0x03, 0x03, 0x03, 0x03, 0xC3, 0xE3, 0x33, 0x1F,
                 0x0F, 0x03, 0x00, 0x00, 0x30, 0x3C, 0x3E, 0x33,
                 0x31, 0x30, 0x30, 0x30, 0x30, 0x30, 0x00, 0x00}, // Z (0x5A)
		{0x00, 0x00, 0xFF, 0xFF, 0x03, 0x03, 0x03, 0x03,
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x3F,
                 0x30, 0x30, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00}, // [ (0x5B)
		{0x0E, 0x1C, 0x38, 0x70, 0xE0, 0xC0, 0x80, 0x00,
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                 0x00, 0x01, 0x03, 0x07, 0x0E, 0x1C, 0x18, 0x00}, // \ (0x5C)
		{0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0xFF, 0xFF,
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30,
                 0x30, 0x30, 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x00}, // ] (0x5D)
		{0x60, 0x70, 0x38, 0x1C, 0x0E, 0x07, 0x0E, 0x1C,
                 0x38, 0x70, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00,
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ^ (0x5E)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                 0x00, 0x00, 0x00, 0x00, 0xC0, 0xC0, 0xC0, 0xC0,
                 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x00}, // _ (0x5F)
		{0x00, 0x00, 0x00, 0x00, 0x3E, 0x7E, 0x4E, 0x00,
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ` (0x60)
		{0x00, 0x40, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60,
                 0xE0, 0xC0, 0x00, 0x00, 0x1C, 0x3E, 0x33, 0x33,
                 0x33, 0x33, 0x33, 0x33, 0x3F, 0x3F, 0x00, 0x00}, // a (0x61)
		{0xFF, 0xFF, 0xC0, 0x60, 0x60, 0x60, 0x60, 0xE0,
                 0xC0, 0x80, 0x00, 0x00, 0x3F, 0x3F, 0x30, 0x30,
                 0x30, 0x30, 0x30, 0x38, 0x1F, 0x0F, 0x00, 0x00}, // b (0x62)
		{0x80, 0xC0, 0xE0, 0x60, 0x60, 0x60, 0x60, 0x60,
                 0xC0, 0x80, 0x00, 0x00, 0x0F, 0x1F, 0x38, 0x30,
                 0x30, 0x30, 0x30, 0x30, 0x18, 0x08, 0x00, 0x00}, // c (0x63)
		{0x80, 0xC0, 0xE0, 0x60, 0x60, 0x60, 0xE0, 0xC0,
                 0xFF, 0xFF, 0x00, 0x00, 0x0F, 0x1F, 0x38, 0x30,
                 0x30, 0x30, 0x30, 0x30, 0x3F, 0x3F, 0x00, 0x00}, // d (0x64)
		{0x80, 0xC0, 0xE0, 0x60, 0x60, 0x60, 0x60, 0x60,
                 0xC0, 0x80, 0x00, 0x00, 0x0F, 0x1F, 0x3B, 0x33,
                 0x33, 0x33, 0x33, 0x33, 0x13, 0x01, 0x00, 0x00}, // e (0x65)
		{0xC0, 0xC0, 0xFC, 0xFE, 0xC7, 0xC3, 0xC3, 0x03,
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x3F,
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // f (0x66)
		{0x80, 0xC0, 0xE0, 0x60, 0x60, 0x60, 0x60, 0x60,
                 0xE0, 0xE0, 0x00, 0x00, 0x03, 0xC7, 0xCE, 0xCC,
                 0xCC, 0xCC, 0xCC, 0xE6, 0x7F, 0x3F, 0x00, 0x00}, // g (0x67)
		{0xFF, 0xFF, 0xC0, 0x60, 0x60, 0x60, 0xE0, 0xC0,
                 0x80, 0x00, 0x00, 0x00, 0x3F, 0x3F, 0x00, 0x00,
                 0x00, 0x00, 0x00, 0x3F, 0x3F, 0x00, 0x00, 0x00}, // h (0x68)
		{0x00, 0x00, 0x00, 0x60, 0xEC, 0xEC, 0x00, 0x00,
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30,
                 0x3F, 0x3F, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00}, // i (0x69)
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0xEC, 0xEC,
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0xE0,
                 0xC0, 0xC0, 0xFF, 0x7F, 0x00, 0x00, 0x00, 0x00}, // j (0x6A)
		{0x00, 0xFF, 0xFF, 0x00, 0x80, 0xC0, 0xE0, 0x60,
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x3F, 0x03,
                 0x07, 0x0F, 0x1C, 0x38, 0x30, 0x00, 0x00, 0x00}, // k (0x6B)
		{0x00, 0x00, 0x00, 0x03, 0xFF, 0xFF, 0x00, 0x00,
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30,
                 0x3F, 0x3F, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00}, // l (0x6C)
		{0xE0, 0xC0, 0xE0, 0xE0, 0xC0, 0xC0, 0xE0, 0xE0,
                 0xC0, 0x80, 0x00, 0x00, 0x3F, 0x3F, 0x00, 0x00,
                 0x3F, 0x3F, 0x00, 0x00, 0x3F, 0x3F, 0x00, 0x00}, // m (0x6D)
		{0x00, 0xE0, 0xE0, 0x60, 0x60, 0x60, 0x60, 0xE0,
                 0xC0, 0x80, 0x00, 0x00, 0x00, 0x3F, 0x3F, 0x00,
                 0x00, 0x00, 0x00, 0x00, 0x3F, 0x3F, 0x00, 0x00}, // n (0x6E)
		{0x80, 0xC0, 0xE0, 0x60, 0x60, 0x60, 0x60, 0xE0,
                 0xC0, 0x80, 0x00, 0x00, 0x0F, 0x1F, 0x38, 0x30,
                 0x30, 0x30, 0x30, 0x38, 0x1F, 0x0F, 0x00, 0x00}, // o (0x6F)
		{0xE0, 0xE0, 0x60, 0x60, 0x60, 0x60, 0x60, 0xE0,
                 0xC0, 0x80, 0x00, 0x00, 0xFF, 0xFF, 0x0C, 0x18,
                 0x18, 0x18, 0x18, 0x1C, 0x0F, 0x07, 0x00, 0x00}, // p (0x70)
		{0x80, 0xC0, 0xE0, 0x60, 0x60, 0x60, 0x60, 0x60,
                 0xE0, 0xE0, 0x00, 0x00, 0x07, 0x0F, 0x1C, 0x18,
                 0x18, 0x18, 0x18, 0x0C, 0xFF, 0xFF, 0x00, 0x00}, // q (0x71)
		{0x00, 0xE0, 0xE0, 0xC0, 0x60, 0x60, 0x60, 0x60,
                 0xE0, 0xC0, 0x00, 0x00, 0x00, 0x3F, 0x3F, 0x00,
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // r (0x72)
		{0xC0, 0xE0, 0x60, 0x60, 0x60, 0x60, 0x60, 0x40,
                 0x00, 0x00, 0x00, 0x00, 0x11, 0x33, 0x33, 0x33,
                 0x33, 0x33, 0x3F, 0x1E, 0x00, 0x00, 0x00, 0x00}, // s (0x73)
		{0x60, 0x60, 0xFE, 0xFE, 0x60, 0x60, 0x60, 0x00,
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x3F,
                 0x30, 0x30, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00}, // t (0x74)
		{0xE0, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                 0xE0, 0xE0, 0x00, 0x00, 0x0F, 0x1F, 0x38, 0x30,
                 0x30, 0x30, 0x30, 0x18, 0x3F, 0x3F, 0x00, 0x00}, // u (0x75)
		{0x60, 0xE0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x80,
                 0xE0, 0x60, 0x00, 0x00, 0x00, 0x01, 0x07, 0x1E,
                 0x38, 0x38, 0x1E, 0x07, 0x01, 0x00, 0x00, 0x00}, // v (0x76)
		{0xE0, 0xE0, 0x00, 0x00, 0xE0, 0xE0, 0x00, 0x00,
                 0xE0, 0xE0, 0x00, 0x00, 0x07, 0x1F, 0x38, 0x1C,
                 0x0F, 0x0F, 0x1C, 0x38, 0x1F, 0x07, 0x00, 0x00}, // w (0x77)
		{0x60, 0xE0, 0xC0, 0x80, 0x00, 0x80, 0xC0, 0xE0,
                 0x60, 0x00, 0x00, 0x00, 0x30, 0x38, 0x1D, 0x0F,
                 0x07, 0x0F, 0x1D, 0x38, 0x30, 0x00, 0x00, 0x00}, // x (0x78)
		{0x00, 0x60, 0xE0, 0x80, 0x00, 0x00, 0x80, 0xE0,
                 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x81, 0xE7,
                 0x7E, 0x1E, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00}, // y (0x79)
		{0x60, 0x60, 0x60, 0x60, 0x60, 0xE0, 0xE0, 0x60,
                 0x20, 0x00, 0x00, 0x00, 0x30, 0x38, 0x3C, 0x36,
                 0x33, 0x31, 0x30, 0x30, 0x30, 0x00, 0x00, 0x00}, // z (0x7A)
		{0x00, 0x80, 0xC0, 0xFC, 0x7E, 0x07, 0x03, 0x03,
                 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x1F,
                 0x3F, 0x70, 0x60, 0x60, 0x60, 0x00, 0x00, 0x00}, // { (0x7B)
		{0x00, 0x00, 0x00, 0x00, 0xBF, 0xBF, 0x00, 0x00,
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // | (0x7C)
		{0x00, 0x03, 0x03, 0x03, 0x07, 0x7E, 0xFC, 0xC0,
                 0x80, 0x00, 0x00, 0x00, 0x00, 0x60, 0x60, 0x60,
                 0x70, 0x3F, 0x1F, 0x01, 0x00, 0x00, 0x00, 0x00}, // } (0x7D)
		{0x10, 0x18, 0x0C, 0x04, 0x0C, 0x18, 0x10, 0x18,
                 0x0C, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ~ (0x7E)
		{0x00, 0x80, 0xC0, 0x60, 0x30, 0x30, 0x60, 0xC0,
                 0x80, 0x00, 0x00, 0x00, 0x0F, 0x0F, 0x0C, 0x0C,
                 0x0C, 0x0C, 0x0C, 0x0C, 0x0F, 0x0F, 0x00, 0x00}, // DEL (0x7F)
};

const u8 font_18x24[][FontSize_18x24 * FontSize_18x24 * BLOCK_WIDTH] PROGMEM = {
		{0x00, 0xE0, 0xF8, 0xFC, 0x3C, 0x1E, 0x0E, 0x0E, 0x0E, 0x0E,
                 0x9E, 0xFC, 0xFC, 0xF8, 0xE0, 0x00, 0x00, 0x00, 0xFF, 0xFF,
                 0xFF, 0xC0, 0xE0, 0x70, 0x38, 0x1C, 0x0E, 0x07, 0x03, 0x81,
                 0xFF, 0xFF, 0x7F, 0x00, 0x00, 0x00, 0x03, 0x0F, 0x1F, 0x1F,
                 0x3C, 0x38, 0x38, 0x38, 0x38, 0x3C, 0x1E, 0x1F, 0x0F, 0x03,
                 0x00, 0x00, 0x00, 0x00}, // 0 (0x30)
		{0x00, 0xC0, 0xE0, 0x70, 0x78, 0x38, 0xFC, 0xFE, 0xFE, 0x02,
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
                 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00,
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x30, 0x38,
                 0x38, 0x38, 0x3F, 0x3F, 0x3F, 0x38, 0x38, 0x38, 0x18, 0x18,
                 0x08, 0x00, 0x00, 0x00}, // 1 (0x31)
		{0xE0, 0x78, 0x3C, 0x1C, 0x1E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E,
                 0x0E, 0x1E, 0x3C, 0xFC, 0xF8, 0xE0, 0x00, 0x00, 0x00, 0x00,
                 0x80, 0xC0, 0xE0, 0xE0, 0xF0, 0x70, 0x78, 0x3C, 0x1C, 0x1E,
                 0x0F, 0x0F, 0x07, 0x03, 0x00, 0x00, 0x1C, 0x3F, 0x3F, 0x3F,
                 0x3B, 0x39, 0x38, 0x38, 0x18, 0x18, 0x18, 0x1C, 0x1C, 0x1C,
                 0x1C, 0x0E, 0x00, 0x00}, // 2 (0x32)
		{0x60, 0x38, 0x1C, 0x1C, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E,
                 0x8E, 0xDE, 0xFC, 0xF8, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00,
                 0x00, 0x00, 0x00, 0x02, 0x06, 0x06, 0x0F, 0x1F, 0x1F, 0x3D,
                 0xF9, 0xF8, 0xF0, 0x00, 0x00, 0x00, 0x07, 0x0E, 0x1C, 0x1C,
                 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x1C, 0x1F, 0x0F, 0x07,
                 0x01, 0x00, 0x00, 0x00}, // 3 (0x33)
		{0x00, 0x00, 0x00, 0xC0, 0xE0, 0xF8, 0x7C, 0x1E, 0x06, 0xC2,
                 0xF0, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0xFE,
                 0xFF, 0xEF, 0xE7, 0xE1, 0xE0, 0xE0, 0xE0, 0xFF, 0xFF, 0xFF,
                 0xE0, 0x60, 0x60, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x1F, 0x3F, 0x00, 0x00,
                 0x00, 0x00, 0x00, 0x00}, // 4 (0x34)
		{0xF8, 0xFC, 0xFC, 0x3C, 0x1C, 0x1C, 0x0E, 0x0E, 0x0E, 0x0E,
                 0x0E, 0x06, 0x06, 0x06, 0x06, 0x02, 0x00, 0x00, 0x01, 0x07,
                 0x0F, 0x1F, 0x1C, 0x1C, 0x1C, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E,
                 0x1E, 0xFC, 0xFC, 0xF0, 0x00, 0x00, 0x07, 0x1E, 0x1E, 0x3C,
                 0x38, 0x38, 0x38, 0x38, 0x38, 0x3C, 0x1C, 0x1C, 0x1E, 0x0F,
                 0x07, 0x07, 0x00, 0x00}, // 5 (0x35)
		{0x00, 0x80, 0xF0, 0xF8, 0x7C, 0x1C, 0x0E, 0x0E, 0x06, 0x06,
                 0x06, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xFF,
                 0xFF, 0x3F, 0x1C, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E,
                 0x1C, 0xFC, 0xF8, 0xE0, 0x00, 0x00, 0x03, 0x0F, 0x1F, 0x1C,
                 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x1C, 0x1F, 0x0F,
                 0x07, 0x01, 0x00, 0x00}, // 6 (0x36)
		{0x10, 0x10, 0x18, 0x18, 0x1C, 0x1C, 0x0C, 0x0C, 0x0E, 0x0E,
                 0x8E, 0xEE, 0xFE, 0xFE, 0x3E, 0x0C, 0x00, 0x00, 0x00, 0x00,
                 0x00, 0x00, 0x10, 0x30, 0xB0, 0xF0, 0xF8, 0xFE, 0x3F, 0x1F,
                 0x1B, 0x18, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                 0x38, 0x1E, 0x0F, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
                 0x00, 0x00, 0x00, 0x00}, // 7 (0x37)
		{0x00, 0xE0, 0xF8, 0xFC, 0x7C, 0x1E, 0x0E, 0x0E, 0x0E, 0x0E,
                 0x0E, 0x9E, 0xFC, 0xFC, 0xF0, 0x00, 0x00, 0x00, 0x80, 0xE3,
                 0xF7, 0xFF, 0x3E, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1E, 0x1F,
                 0x3F, 0xF7, 0xF1, 0xE0, 0x00, 0x00, 0x07, 0x1F, 0x1F, 0x3C,
                 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x3C, 0x1F, 0x1F,
                 0x07, 0x03, 0x00, 0x00}, // 8 (0x38)
		{0xC0, 0xF0, 0xF8, 0x7C, 0x1C, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E,
                 0x0E, 0x0E, 0x1C, 0xFC, 0xF8, 0xE0, 0x00, 0x00, 0x03, 0x0F,
                 0x1F, 0x1C, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x1C,
                 0xFE, 0xFF, 0xFF, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20,
                 0x20, 0x30, 0x30, 0x30, 0x38, 0x38, 0x1C, 0x1F, 0x0F, 0x07,
                 0x00, 0x00, 0x00, 0x00}, // 9 (0x39)
};

const u8* get_glyph(enum FontSize font_size, char c)
{
	switch (font_size) {
	case FontSize_6x8:
		if (c < FONT_BITMAP_OFFSET) {
			return font_6x8[0];
		}

		return font_6x8[c - FONT_BITMAP_OFFSET];
	case FontSize_12x16:
		if (c < FONT_BITMAP_OFFSET) {
			return font_6x8[0];
		}

		return font_12x16[c - FONT_BITMAP_OFFSET];
	case FontSize_18x24:
		if (c < '0' || c > '9') {
			return font_6x8[0];
		}

		return font_18x24[c - '0'];
	default:
		return font_6x8[c - FONT_BITMAP_OFFSET];
	}
}

