#include "int.h"

uint32_t lengthInt(int number)
{
  uint32_t value = 1;
  int numerator = number / 10;
  while(0 != numerator) {
    numerator = numerator / 10;
    value++;
  }
  return value;
}

uint32_t abs(int32_t number)
{
  uint32_t value;
  return value;
}

int stringToInt(char* str)
{
  int value = 0;
  return value;
}

int32_t hexToDecimal(int number)
{
  int32_t value = 0;
  return value;
}
