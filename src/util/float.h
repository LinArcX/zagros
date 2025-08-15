#ifndef UTIL_FLOAT_H
#define UTIL_FLOAT_H

#include "globals.h"

/**
 * @brief
 *
 * @param number 
 * @param numeratorLength
 * @param denominatorLength
 * @return length of float by 2 numbers:\n
 * - \b numeratorLength
 * - \b denominatorLength*
 */
void lengthFloat(const float number, uint32_t *numeratorLength, uint32_t *denominatorLength);

/**
 * @brief convert a string to float.
 *
 * @param str 
 * @return float
 */
float stringToFloat(char* str);

#endif
