char* numberToString(unsigned int number) 
{
  //char string[10] = {0};
  //while (0 != number % 10) {

  //}
}

// since we're in our own world, there's no printf, there's no glibc, there's no <stdio.h>
// so we should implement our own print function.
void print(char* text, unsigned int number)
{
  int i = 0;
  // 0xb8000 --> beginning of video memory address. everything you write here, you'll see it on the screen by the graphics card.
  // +---------+---------+---------+----------+---------+
  // |  COLOR  |  CHAR   |  COLOR  |  COLOR   |  CHAR   |
  // +---------+---------+---------+----------+---------+
  // we chose short, since it's 2 byte. first byte is for bg/fg and second one is for real data.
  unsigned short* videoMemory = (unsigned short*)0xb8000;

  for(i = 0; text[i]!='\0'; i++) {
    // we want to keep COLOR byte untouched, so we do: videoMemory[i] & 0xFF00
    videoMemory[i] = (videoMemory[i] & 0xFF00) | text[i];
  }
  i++;

  videoMemory[i] = (videoMemory[i] & 0xFF00) | 7;
}

void kernelMain(void* multiboot_structor, unsigned int magic_number)
{
  print("Hello zagros. magic number: ", magic_number);
  while(1);
}
