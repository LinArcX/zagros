void printf(char* text)
{
  unsigned short* videoMemory = (unsigned short*)0xb8000;
  for(int i = 0; text[i]!='\0'; i++) {
      videoMemory[i] = (videoMemory[i] & 0xFF00) | text[i];
  }
}

void kernelMain(void* multiboot_structor, unsigned int magic_number)
{
  printf("Hello zagros..");
  while(1);
}
