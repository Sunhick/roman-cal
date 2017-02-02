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
    
    long long fnumber = rm_conv_llong(first);
    if(fnumber == INVALID) {
        result->errcode = ERROR;
        result->err_message = (char*)malloc(sizeof(char)*20);
        sprintf(result->err_message, "%s is invalid roman!", first);
        return result;
    }

    long long snumber = rm_conv_llong(second);
    if(snumber == INVALID) {
        result->errcode = ERROR;
        result->err_message = (char*)malloc(sizeof(char)*20);
        sprintf(result->err_message, "%s is invalid roman!", second);
        return result;
    }

    long long answer = fnumber + snumber;
    result->value = rm_llong_conv(answer);
    return result;
}

/* rm_sub() returns rm_result that holds absolute difference of two numbers
    or error description with code.*/
struct rm_result* rm_sub(char* first, char* second) {
    struct rm_result* result = malloc(sizeof(struct rm_result));
    
    long long fnumber = rm_conv_llong(first);
    if(fnumber == INVALID) {
        result->errcode = ERROR;
        result->err_message = (char*)malloc(sizeof(char)*20);
         sprintf(result->err_message, "%s is invalid roman!", first);
        return result;
    }

    long long snumber = rm_conv_llong(second);
    if(snumber == INVALID) {
        result->errcode = ERROR;
        result->err_message = (char*)malloc(sizeof(char)*20);
        sprintf(result->err_message, "%s is invalid roman!", second);
        return result;
    }

    long long answer = llabs(fnumber - snumber);
    result->value = rm_llong_conv(answer);
    return result;
}