#define CLOVE_SUITE_NAME UtilSuite

#include "clove-unit.h"
#include "../src/util/float.h"

// ====================== lengthFloat() ========================//
CLOVE_TEST(lengthFloatZero)
{
  uint32_t numeratorLength = 0;
  uint32_t denominatorLength = 0;
  lengthFloat(0, &numeratorLength, &denominatorLength);

  CLOVE_UINT_EQ(1, numeratorLength);
  CLOVE_UINT_EQ(0, denominatorLength);
}

CLOVE_TEST(lengthFloatPositive)
{
  uint32_t numeratorLength = 0;
  uint32_t denominatorLength = 0;
  lengthFloat(34.1, &numeratorLength, &denominatorLength);

  CLOVE_UINT_EQ(2, numeratorLength);
  CLOVE_UINT_EQ(1, denominatorLength);
}

CLOVE_TEST(lengthFloatNegative)
{
  uint32_t numeratorLength = 0;
  uint32_t denominatorLength = 0;
  lengthFloat(-4.1345, &numeratorLength, &denominatorLength);

  CLOVE_UINT_EQ(1, numeratorLength);
  CLOVE_UINT_EQ(4, denominatorLength);
}

CLOVE_TEST(lengthFloatJustFraction)
{
  uint32_t numeratorLength = 0;
  uint32_t denominatorLength = 0;
  lengthFloat(0.981, &numeratorLength, &denominatorLength);

  CLOVE_UINT_EQ(0, numeratorLength);
  CLOVE_UINT_EQ(3, denominatorLength);
}

CLOVE_TEST(lengthFloatJustFractionWithout0)
{
  uint32_t numeratorLength = 0;
  uint32_t denominatorLength = 0;
  lengthFloat(.981, &numeratorLength, &denominatorLength);

  CLOVE_UINT_EQ(0, numeratorLength);
  CLOVE_UINT_EQ(3, denominatorLength);
}

CLOVE_TEST(lengthFloatJustNumerator)
{
  uint32_t numeratorLength = 0;
  uint32_t denominatorLength = 0;
  lengthFloat(981, &numeratorLength, &denominatorLength);

  CLOVE_UINT_EQ(3, numeratorLength);
  CLOVE_UINT_EQ(0, denominatorLength);
}
