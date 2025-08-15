#define CLOVE_SUITE_NAME UtilSuite

#include "clove-unit.h"
#include "../src/util/strings.h"

// ========================== globals ========================//
char str[100] = {0};
int setup_once_count = 0;
int teardown_once_count = 0;
int setup_count = 0;
int teardown_count = 0;

// ====================== setup(), teardown() ========================//
CLOVE_SUITE_SETUP_ONCE()
{
  setup_once_count++;
}

CLOVE_SUITE_TEARDOWN_ONCE()
{
  teardown_once_count++;
}

CLOVE_SUITE_SETUP()
{
  setup_count++;
}

CLOVE_SUITE_TEARDOWN()
{
  teardown_count++;
}

// ====================== lengthString() ========================//
CLOVE_TEST(lengthStringNULL)
{
  char* string = NULL;
  uint32_t length = lengthString(string);
  CLOVE_UINT_EQ(0, length);
}

CLOVE_TEST(lengthStringCharPointer)
{
  char* string = "test";
  uint32_t length = lengthString(string);
  CLOVE_UINT_EQ(4, length);
}

CLOVE_TEST(lengthStringArray)
{
  char string[2] = "ha";
  uint32_t length = lengthString(string);
  CLOVE_UINT_EQ(2, length);
}

// ====================== sliceOfString() ========================//
CLOVE_TEST(sliceOfStringEmpty)
{
}

CLOVE_TEST(sliceOfStringCharPointr)
{
}

CLOVE_TEST(sliceOfStringArray)
{
}

CLOVE_TEST(sliceOfStringOrdinaryString)
{
}

// ====================== intToString() ========================//
CLOVE_TEST(intToStringZero)
{
}

CLOVE_TEST(intToStringNegative)
{
}

CLOVE_TEST(intToStringPositive)
{
}

// ====================== floatToString() ========================//
CLOVE_TEST(floatToString1Digit1Fraction)
{
  floatToString(1.1, str);
  CLOVE_NOT_NULL(str);
  CLOVE_STRING_EQ("1.1", str);
}

CLOVE_TEST(floatToString2Digit2Fraction)
{
  floatToString(23.67, str);
  CLOVE_NOT_NULL(str);
  CLOVE_STRING_EQ("23.67", str);
}

CLOVE_TEST(floatToString3Digit2Fractions)
{
  floatToString(927.12, str);
  CLOVE_NOT_NULL(str);
  CLOVE_STRING_EQ("927.12", str);
}

CLOVE_TEST(floatToString3DigitNegative)
{
  floatToString(-261, str);
  CLOVE_NOT_NULL(str);
  CLOVE_STRING_EQ("-261", str);
}

CLOVE_TEST(floatToString3Digit4FractionNegative)
{
  floatToString(-927.1201, str);
  CLOVE_NOT_NULL(str);
  CLOVE_STRING_EQ("-927.1201", str);
}

CLOVE_TEST(floatToString0Digit2Fractional)
{
  floatToString(0.08, str);
  CLOVE_NOT_NULL(str);
  CLOVE_STRING_EQ("0.08", str);
}

CLOVE_TEST(floatToString0Digit2FractionalNegative)
{
  floatToString(-0.08, str);
  CLOVE_NOT_NULL(str);
  CLOVE_STRING_EQ("0.08", str);
}

// ====================== hexToString() ========================//
CLOVE_TEST(hexToString1Digit)
{
  hexToString(0x1, str);
  CLOVE_NOT_NULL(str);
  CLOVE_STRING_EQ("0x1", str);
}

CLOVE_TEST(hexToString2Digit)
{
  hexToString(0x89, str);
  CLOVE_NOT_NULL(str);
  CLOVE_STRING_EQ("0x89", str);
}

CLOVE_TEST(hexToString3Digit)
{
  hexToString(0x8AF, str);
  CLOVE_NOT_NULL(str);
  CLOVE_STRING_EQ("0x8AF", str);
}

CLOVE_TEST(hexToString4DigitPlusA)
{
  hexToString(0xFFAC, str);
  CLOVE_NOT_NULL(str);
  CLOVE_STRING_EQ("0xFFAC", str);
}
