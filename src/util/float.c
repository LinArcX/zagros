#include "float.h"
#include "int.h"
#include "strings.h"

void lengthFloat(const float number, uint32_t *numeratorLength, uint32_t *denominatorLength)
{
  uint32_t numerator = (uint32_t)number;
  float denominator = number - (float)numerator ;

  *numeratorLength = lengthInt(numerator);

  char str[10] = {0};
  floatToString(denominator, str);
  *denominatorLength = lengthString(str) - 2;
}

float stringToFloat(char* str)
{
  float value = 0.0;
  return value;
}
