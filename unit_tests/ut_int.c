#define CLOVE_SUITE_NAME UtilSuite

#include "clove-unit.h"

#include "../src/util/globals.h"
#include "../src/util/int.h"
#include "../src/util/strings.h"

// ====================== lengthInt() ========================//
CLOVE_TEST(lengthIntZero)
{
  uint32_t length = lengthInt(0);
  CLOVE_UINT_EQ(1, length);
}

CLOVE_TEST(lengthIntPositive)
{
  uint32_t length = lengthInt(12890);
  CLOVE_UINT_EQ(5, length);
}

CLOVE_TEST(lengthIntNegative)
{
  uint32_t length = lengthInt(-870);
  CLOVE_UINT_EQ(3, length);
}

CLOVE_TEST(lengthIntNonIntParameter)
{
  uint32_t length4 = lengthInt(0.0);
  CLOVE_INT_EQ(1, length4);

  uint32_t length5 = lengthInt(12.1099);
  CLOVE_INT_EQ(2, length5);

  uint32_t length6 = lengthInt(-780.001);
  CLOVE_INT_EQ(3, length6);

  uint32_t length7 = lengthInt(.012);
  CLOVE_INT_EQ(1, length7);

  uint32_t length = lengthInt(0x0);
  CLOVE_INT_EQ(PARAMETER_IS_HEX, length);

  uint32_t length2 = lengthInt(0xF12);
  CLOVE_INT_EQ(PARAMETER_IS_HEX, length2);

  uint32_t length3 = lengthInt(0X109);
  CLOVE_INT_EQ(PARAMETER_IS_HEX, length3);
}

// ====================== abs() ========================//
CLOVE_TEST(absZero)
{
  uint32_t value = abs(0);
  CLOVE_UINT_EQ(0, value);
}

CLOVE_TEST(absNegative)
{
  uint32_t value = abs(-872);
  CLOVE_UINT_EQ(872, value);
}

CLOVE_TEST(absPositive)
{
  uint32_t value = abs(103);
  CLOVE_UINT_EQ(103, value);
}

CLOVE_TEST(absNonIntParameter)
{
  uint32_t value1= abs(0x0);
  CLOVE_UINT_EQ(PARAMETER_IS_HEX, value1);

  uint32_t value2 = abs(0xF1);
  CLOVE_UINT_EQ(PARAMETER_IS_HEX, value2);

  uint32_t value3 = abs(12.1);
  CLOVE_UINT_EQ(PARAMETER_IS_HEX, value3);
}

// ====================== stringToInt() ========================//
CLOVE_TEST(stringToIntNULL)
{
  int32_t value1 = stringToInt(NULL);
  CLOVE_UINT_EQ(STRING_IS_NULL, value1);

  int32_t value2 = stringToInt("");
  CLOVE_UINT_EQ(STRING_IS_NULL, value2);

  int32_t value3 = stringToInt("  ");
  CLOVE_UINT_EQ(STRING_IS_NULL, value3);
}

CLOVE_TEST(stringToIntContainsNonDigits)
{
  uint32_t value1 = stringToInt("str1ng");
  CLOVE_UINT_EQ(STRING_CONTAINS_NON_DIGITS, value1);

  uint32_t value2 = stringToInt("12test");
  CLOVE_UINT_EQ(STRING_CONTAINS_NON_DIGITS, value2);

  uint32_t value3 = stringToInt("!86:_");
  CLOVE_UINT_EQ(STRING_CONTAINS_NON_DIGITS, value3);

  uint32_t value4 = stringToInt("0.1");
  CLOVE_UINT_EQ(STRING_IS_FLOAT, value4);

  uint32_t value5 = stringToInt("12.07");
  CLOVE_UINT_EQ(STRING_IS_FLOAT, value5);

  uint32_t value6 = stringToInt(".0");
  CLOVE_UINT_EQ(STRING_IS_FLOAT, value6);

  uint32_t value7 = stringToInt("0xF1");
  CLOVE_UINT_EQ(STRING_IS_HEX, value7);

  uint32_t value8 = stringToInt("0x23");
  CLOVE_UINT_EQ(STRING_IS_HEX, value8);
}

CLOVE_TEST(stringToIntAllDigits)
{
  uint32_t value1 = stringToInt("0");
  CLOVE_UINT_EQ(0, value1);

  uint32_t value2 = stringToInt("123");
  CLOVE_UINT_EQ(123, value2);

  uint32_t value3 = stringToInt("0078900");
  CLOVE_UINT_EQ(78900, value3);
}

// ====================== hexToDecimal() ========================//
CLOVE_TEST(hexToDecimalNULL)
{
  uint32_t value = hexToDecimal(NULL);
  CLOVE_UINT_EQ(0, value);
}

CLOVE_TEST(hexToDecimalInputHex)
{
  uint32_t value1 = hexToDecimal(0xFF);
  CLOVE_UINT_EQ(255, value1);

  uint32_t value2 = hexToDecimal(0x0);
  CLOVE_UINT_EQ(0, value2);

  uint32_t value3 = hexToDecimal(0XA12);
  CLOVE_UINT_EQ(2578, value3);
}

CLOVE_TEST(hexToDecimalInputNonHex)
{
  uint32_t value1 = hexToDecimal(0);
  CLOVE_UINT_EQ(PARAMETER_SHOULD_BE_HEX, value1);

  uint32_t value2 = hexToDecimal(12);
  CLOVE_UINT_EQ(PARAMETER_SHOULD_BE_HEX, value2);

  uint32_t value3 = hexToDecimal(13.1);
  CLOVE_UINT_EQ(PARAMETER_SHOULD_BE_HEX, value3);

  uint32_t value4 = hexToDecimal(.1);
  CLOVE_UINT_EQ(PARAMETER_SHOULD_BE_HEX, value3);

  uint32_t value5 = hexToDecimal(-0.012);
  CLOVE_UINT_EQ(PARAMETER_SHOULD_BE_HEX, value5);

  uint32_t value6 = hexToDecimal(-0.0);
  CLOVE_UINT_EQ(PARAMETER_SHOULD_BE_HEX, value6);
}
