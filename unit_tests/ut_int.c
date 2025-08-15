#define CLOVE_SUITE_NAME UtilSuite

#include "clove-unit.h"
#include "../src/util/int.h"

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
