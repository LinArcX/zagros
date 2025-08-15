#ifndef UTIL_HEX_H
#define UTIL_HEX_H

#include "globals.h"

/**
 * @brief check if number is hex or no
 *
 * @param number 
 * @return
 */
Bool isHex(int32_t number);

/**
 * @brief convert a decimal number to hex.
 *
 * @param decimal number 
 * @return hex value
 */
int decimalToHex(int32_t number);

#endif
