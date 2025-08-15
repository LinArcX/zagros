#include "strings.h"

uint32_t lengthString(char* str)
{
  uint32_t value = 0;
  if(NULL != str) {
    while('\0' != *str) {
      str++;
      value++;
    }
  }
  return value;
}

char* sliceOfString(uint16_t beg, uint16_t end, char* str)
{
  char* value = NULL;
  return value;
}

void intToString(int number, char* str, uint32_t length)
{
  //uint32_t base = number / 10;
  //uint32_t reminder = number % 10;

  //while(0 != reminder) {
  //  base = reminder / 10;
  //  base = reminder / 10;
  //}
}

void floatToString(float number, char* str) 
{
  // example:    4.3
  // numerator:   4
  // denominator: 3
  uint32_t numerator = (uint32_t)number;
  float denominator = number - (float)numerator ;

  //char* value = NULL;
  //while() {
  //}
  //char string[10] = {0};
  //while (0 != number % 10) {
  //}
}

void hexToString(int number, char* str)
{
}
