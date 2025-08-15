/**
 * @file
 * @brief contains global variables, structs, typedefs.\n
 * more details about colors: https://wiki.osdev.org/Printing_To_Screen
 */

#ifndef ZAGROS_UTIL_GLOBALS_H
#define ZAGROS_UTIL_GLOBALS_H

#define NULL 0
typedef int Bool;
#define true 1
#define false 0

typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef signed short int int16_t;
typedef unsigned short int uint16_t;
typedef signed int int32_t;
typedef unsigned int uint32_t;

enum GlobalErrors
{
  PARAMETER_SHOULD_BE_INT     = -1,
  PARAMETER_SHOULD_BE_HEX     = -2,
  PARAMETER_IS_HEX     = -3,
};

/// number of screen columns
extern uint8_t SCREEN_WIDTH;

/// number of screen rows
extern uint8_t SCREEN_HEIGHT;

/**
 * @brief address of memory mapped area (VGA text mode memory)\n
 *  \c 0xb8000 --> beginning of video memory address. everything you write here, you'll see it on the screen by the graphics card.\n
 *  +---------+---------+---------+----------+---------+----------+\n
 *  |  COLOR  |  ASCII  |  COLOR  |  ASCII   |  COLOR  |  ASCII   |\n
 *  +---------+---------+---------+----------+---------+----------+\n
 *
 *  \b ASCII:             1 byte.\n
 *  \b COLOR (attribute): 1 byte. highest 3 bits: bg, lowest 4 bits: fg\n
 *  - The interpretation of bit #7 depends on how you (or the BIOS) configured the hardware\n
 */
extern int VIDEO_MEMORY;

/// white text on gray  background
extern int WHITE_ON_GRAY;

/// gray  text on black background (DOS default)
extern int GRAY_ON_BLACK;

/// white text on black background
extern int WHITE_ON_BLACK;

/// green text on black background
extern int GREEN_ON_BLACK;

/// green text on gray  background
extern int GREEN_ON_GRAY;

/// white text on blue  background (Win9x's blue-screen-of-death)
extern int WHITE_ON_BLUE;

/// light green text on green  background (green-monochrome nostalgics)
extern int LIGHT_GREEN_ON_GREEN;

#endif
