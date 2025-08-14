short SCREEN_WIDTH = 80;  // columns
short SCREEN_HEIGHT = 25; // rows

typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef signed short int int16_t;
typedef unsigned short int uint16_t;
typedef signed int int32_t;
typedef unsigned int uint32_t;

// memory mapped
int VIDEO_MEMORY   = 0xB8000;   // Start of VGA text mode memory

// 0xb8000 --> beginning of video memory address. everything you write here, you'll see it on the screen by the graphics card.
// +---------+---------+---------+----------+---------+----------+
// |  COLOR  |  ASCII  |  COLOR  |  ASCII   |  COLOR  |  ASCII   |
// +---------+---------+---------+----------+---------+----------+
// ASCII:             1 byte.
// COLOR (attribute): 1 byte. highest 3 bits: bg, lowest 4 bits: fg
//                            The interpretation of bit #7 depends on how you (or the BIOS) configured the hardware

// colors: https://wiki.osdev.org/Printing_To_Screen
int WHITE_ON_GRAY         = 0x7F;      // white text on gray  background
int GRAY_ON_BLACK         = 0x07;      // gray  text on black background (DOS default)
int WHITE_ON_BLACK        = 0x0F;      // white text on black background
int GREEN_ON_BLACK        = 0x02;      // green text on black background
int GREEN_ON_GRAY         = 0x72;      // green text on gray  background
int WHITE_ON_BLUE         = 0x1F;      // white text on blue  background (Win9x's blue-screen-of-death)
int LIGHT_GREEN_ON_GREEN  = 0x2a;      // light green text on green  background (green-monochrome nostalgics)

char* numberToString(unsigned int number) 
{
  //char string[10] = {0};
  //while (0 != number % 10) {

  //}
}

// since we're in our own world, there's no printf, there's no glibc, there's no <stdio.h>
// so we should implement our own print function.
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

// NOTES:
//  - this is the entry point of our kernel. (comming from bootloader)
//  - until this point, the only things in the memory are:
//    GRUB, BIOS, the OS kernel and some memory-mapped I/O. (ex: framebuffer)
void kmain(void* multiboot_structor, unsigned int magic_number)
{
  const uint16_t x = 5;
  const uint16_t y = 10;

  clearScreen(WHITE_ON_GRAY);
  print(GRAY_ON_BLACK, x, y, "Hello zagros. magic number: 7");

  while(1);
}
