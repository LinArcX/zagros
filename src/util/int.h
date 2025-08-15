#ifndef ZAGROS_INT_H
#define ZAGROS_INT_H

#include "globals.h"

/**
 * @brief 
 *
 * @param number 
 * @return length of int
 */
int32_t lengthInt(int32_t number);

/**
 * @brief 
 *
 * @param number 
 * @return absolute value of number
 */
int32_t abs(int32_t number);

/**
 * @brief convert a string to int.
 *
 * @param str 
 * @return int
 */
int32_t stringToInt(char* str);

/**
 * @brief convert an hex number to decimal.
 *
 * @param hex number 
 * @return decimal number
 */
int32_t hexToDecimal(int number);

#endif
