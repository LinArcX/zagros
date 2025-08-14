#ifndef ZAGROS_UTIL_GLOBALS_H
#define ZAGROS_UTIL_GLOBALS_H

typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef signed short int int16_t;
typedef unsigned short int uint16_t;
typedef signed int int32_t;
typedef unsigned int uint32_t;

extern uint8_t SCREEN_WIDTH;  // columns
extern uint8_t SCREEN_HEIGHT; // rows

// memory mapped
extern int VIDEO_MEMORY;   // Start of VGA text mode memory

// 0xb8000 --> beginning of video memory address. everything you write here, you'll see it on the screen by the graphics card.
// +---------+---------+---------+----------+---------+----------+
// |  COLOR  |  ASCII  |  COLOR  |  ASCII   |  COLOR  |  ASCII   |
// +---------+---------+---------+----------+---------+----------+
// ASCII:             1 byte.
// COLOR (attribute): 1 byte. highest 3 bits: bg, lowest 4 bits: fg
//                            The interpretation of bit #7 depends on how you (or the BIOS) configured the hardware

// colors: https://wiki.osdev.org/Printing_To_Screen
extern int WHITE_ON_GRAY;               // white text on gray  background
extern int GRAY_ON_BLACK;               // gray  text on black background (DOS default)
extern int WHITE_ON_BLACK;              // white text on black background
extern int GREEN_ON_BLACK;              // green text on black background
extern int GREEN_ON_GRAY;               // green text on gray  background
extern int WHITE_ON_BLUE;               // white text on blue  background (Win9x's blue-screen-of-death)
extern int LIGHT_GREEN_ON_GREEN;        // light green text on green  background (green-monochrome nostalgics)

#endif
