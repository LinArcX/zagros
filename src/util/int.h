#ifndef ZAGROS_INT_H
#define ZAGROS_INT_H

#include "globals.h"

/**
 * @brief 
 *
 * @param number 
 * @return length of int
 */
uint32_t lengthInt(int number);

/**
 * @brief 
 *
 * @param number 
 * @return absolute value of number
 */
uint32_t abs(int32_t number);

/**
 * @brief accept a string and convert it to int.
 *
 * @param str 
 * @return int
 */
int stringToInt(char* str);

/**
 * @brief accept an hex number and convert to decimal.
 *
 * @param number 
 * @return int32_t
 */
int32_t hexToDecimal(int number);

#endif
