/**
 * @file
 * @brief global variables
 */

#ifndef ZAGROS_UTIL_VIDEO_MMIO_H
#define ZAGROS_UTIL_VIDEO_MMIO_H

#include "globals.h"

/**
 * @brief clear the screen
 *
 * @param color 
 */
void clearScreen(const uint16_t color);

/**
 * @brief since we're in our own world, there's no printf, there's no glibc, there's no <stdio.h>
 * this function is our own implementation that writes to video memory buffer directly.
 *
 * @param color 
 * @param x 
 * @param y 
 * @param string 
 */
void print(const uint16_t color, const uint16_t x, const uint16_t y, const char* string);

#endif
