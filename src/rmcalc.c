/* rmcalc.c -- implementation file for roman calculator. 
 *
 * Copyright (C) 2017 Sunil <sunhick@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include <stddef.h>
#include <stdlib.h>

#include "headers/rmcalc.h"
#include "headers/rmconv.h"

/* Given two roman numerals, rm_add() adds them and returns the answer in numeric format.  
   Returning char* avoids integer overflows. */ 
struct rm_result* rm_add(char* first, char* second) {
    struct rm_result* result = malloc(sizeof(struct rm_result));
    
    char* fnumber = rm_conv_numeric(first);
    if(!fnumber) {
        result->errcode = ERROR;
        result->err_message = "First number is invalid roman!";
        return result;
    }

    char* snumber = rm_conv_numeric(second);
    if(!snumber) {
        result->errcode = ERROR;
        result->err_message = "Second number is invalid roman!";
        return result;
    }

    // char* answer = rm_add_ascii(first, second);
    // result->value = answer;
    return result;
}

/* rm_sub() returns rm_result that holds absolute difference of two numbers
    or error description with code.*/
struct rm_result* rm_sub(char* first, char* second) {
    return NULL;
}