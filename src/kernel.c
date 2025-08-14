#include "util/globals.h"
#include "util/video_mmio.h"

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
