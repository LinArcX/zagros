#ifndef ZAGROS_UTIL_VIDEO_MMIO_H
#define ZAGROS_UTIL_VIDEO_MMIO_H

#include "globals.h"

void clearScreen(const uint16_t color);

// since we're in our own world, there's no printf, there's no glibc, there's no <stdio.h>
// so we should implement our own print function.
void print(const uint16_t color, const uint16_t x, const uint16_t y, const char* string);

#endif
