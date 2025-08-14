char* numberToString(unsigned int number) 
{
  //char string[10] = {0};
  //while (0 != number % 10) {

  //}
}

// since we're in our own world, there's no printf, there's no glibc, there's no <stdio.h>
// so we should implement our own print function.
void print(unsigned int color, unsigned short x, unsigned short y, const char* string)
{
  // colors:
  // - 0x0F --> white on black
  // - 0x7F --> white on grey
  // - 0x07 --> grey on black
  // - 0x02 --> grey on black
  // 0xb8000 --> beginning of video memory address. everything you write here, you'll see it on the screen by the graphics card.
  // +---------+---------+---------+----------+---------+----------+
  // |  COLOR  |  ASCII  |  COLOR  |  ASCII   |  COLOR  |  ASCII   |
  // +---------+---------+---------+----------+---------+----------+
  // ASCII:             1 byte.
  // COLOR (attribute): 1 byte. highest 3 bits: bg, lowest 4 bits: fg
  //                            The interpretation of bit #7 depends on how you (or the BIOS) configured the hardware
  //                            Example: 0x00 --> black-on-black,
  //                                     0x07 --> lightgrey-on-black (DOS default),
  //                                     0x1F --> white-on-blue (Win9x's blue-screen-of-death),
  //                                     0x2a --> green-monochrome nostalgics

  volatile char* videoMemory = (volatile char*)0xB8000;

  for(short i = 0; i < y; i++) {
    for(short j = 0; j < x; j++) {
      *videoMemory++;         // ASCII code byte: we just skip it!
      *videoMemory++;         // Attribute byte: we just skip it!
    }
  }

  while(*string != 0) {
    *videoMemory++ = *string++;
    *videoMemory++ = color;
  }
}

void clearScreen(unsigned short color)
{
  // NOTE: screen is 80x25
  volatile char* videoMemory = (volatile char*)0xB8000;
 
  for(short i = 0; i < 80; i++) {
    for(short j = 0; j < 25; j++) {
      *videoMemory++;         // ASCII code byte: we just skip it!
      *videoMemory++ = color; // attribute byte
    }
  }
}

// NOTES:
//  - this is the entry point of our kernel. (comming from bootloader)
//  - until this point, the only things in the memory are:
//    GRUB, BIOS, the OS kernel and some memory-mapped I/O. (ex: framebuffer)
void kmain(void* multiboot_structor, unsigned int magic_number)
{
  clearScreen(0x7F);

  print(0x07, 10, 50, "Hello zagros. magic number: 7");
  while(1);
}
