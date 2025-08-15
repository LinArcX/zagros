#include "int.h"
#include "hex.h"

int32_t lengthInt(int32_t number)
{
  int32_t value = 0;
  if(isHex(number)) {
    value = PARAMETER_IS_HEX;
  }
  else {
    value++;
    int numerator = number / 10;
    while(0 != numerator) {
      numerator = numerator / 10;
      value++;
    }
  }
  return value;
}

int32_t abs(int32_t number)
{
  int32_t value = 0;
  if(isHex(number)) {
    value = PARAMETER_IS_HEX;
  }
  else {
    if(number < 0) {
      value = -number;
    }
    else {
      value = number;
    }
  }
  return value;
}

int32_t stringToInt(char* str)
{
  int value = 0;
  return value;
}

int32_t hexToDecimal(int number)
{
  int32_t value = 0;
  return value;
}
