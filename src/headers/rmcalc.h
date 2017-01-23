/* rmcalc.h -- header for roman calculator. 
 *  Defines the library interfaces
 *
 * Copyright (C) 2017 Sunil <sunhick@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef RM_CALC_H
#define RM_CALC_H

#include "rmresult.h"

/* Given two roman numerals, rm_add() adds them and returns the answer in numeric format.  
   Returning char* avoids integer overflows. */ 
struct rm_result* rm_add(char* first, char* second);

/* rm_sub() returns rm_result that holds absolute difference of two numbers
    or error description with code.*/
struct rm_result* rm_sub(char* first, char* second);

#endif