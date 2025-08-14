#include "video_mmio.h"

void print(const uint16_t color, const uint16_t x, const uint16_t y, const char* string)
{
  volatile char* vMem = (volatile char*)VIDEO_MEMORY;

  for(uint16_t i = 0; i < x; i++) {
    for(uint16_t j = 0; j < y; j++) {
      *vMem++;         // ASCII code byte: we just skip it!
      *vMem++;         // Attribute byte: we just skip it!
    }
  }

  while(*string != 0) {
    *vMem++ = *string++;
    *vMem++ = color;
  }
}

void clearScreen(const uint16_t color)
{
  volatile char* vMem = (volatile char*)VIDEO_MEMORY;
 
  for(uint16_t i = 0; i < SCREEN_WIDTH; i++) {
    for(uint16_t j = 0; j < SCREEN_HEIGHT; j++) {
      *vMem++ = ' ';   // ASCII code byte: we just skip it!
      *vMem++ = color; // Attribute byte
    }
  }
}
