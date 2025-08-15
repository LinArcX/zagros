/**
 * @file 
 * @brief strings.h contains utitlity functions to manipulate/generate strings.
 */

#ifndef ZAGROS_UTIL_STRIGNS_H
#define ZAGROS_UTIL_STRIGNS_H

#include "globals.h"

enum StringErrors
{
  STRING_IS_NULL              = -1,
  STRING_CONTAINS_NON_DIGITS  = -2,
  STRING_IS_FLOAT             = -3,
  STRING_IS_HEX               = -4
};

/**
 * @brief  
 *
 * @param str 
 * @return length of string
 */
uint32_t lengthString(char* str);

/**
 * @brief
 *
 * @param beg 
 * @param end 
 * @param str 
 * @return a slice of str from beg to end
 */
char* sliceOfString(uint16_t beg, uint16_t end, char* str);

/**
 * @brief convert an int number to string.
 *
 * @param number 
 * @param str 
 * @param length 
 * @return
 */
void intToString(int number, char* str, uint32_t length);

/**
 * @brief convert a float number to string.
 *
 * @param number 
 * @return
 */
void floatToString(float number, char* str);

/**
 * @brief convert an hex number to string.
 *
 * @param number
 * @param str
 * @return
 */
void hexToString(int number, char* str);

#endif
