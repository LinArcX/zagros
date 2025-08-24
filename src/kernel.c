#include "util/globals.h"
#include "util/video_mmio.h"
 
/**
 * @brief This is the entry point of zagros. kmain will call by bootloader.
 * up until this point, the only things in the memory are:
 * - BIOS,
 * - GRUB
 * - some memory-mapped I/O, ex: framebuffer.
 *
 * @param multiboot_structor 
 * @param magic_number 
 */
// cppcheck-suppress unusedFunction
void kmain(void* multiboot_structor, unsigned int magic_number)
{
  const uint16_t x = 5;
  const uint16_t y = 10;

  clearScreen(WHITE_ON_GRAY);
  print(GRAY_ON_BLACK, x, y, "Hello zagros. magic number: 7");

  while(1) {}
}
