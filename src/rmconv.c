/* rmconv.c -- impl file for converting roman to numeric. 
 *
 * Copyright (C) 2017 Sunil <sunhick@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "headers/rmconv.h"

#define INVALID     -999
#define CHR_LIMIT   10

int convert(char c) {
    switch(c) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return INVALID;
    }
}

/* reverse the given string and return a the reference */
char* strrev(const char *t) {
    int len = strlen(t);
    char* rev = (char*)malloc((len+1) * sizeof(char));
    for(int i=0;i<len;i++)
    {
        rev[(len-1)-i]=t[i];
    }
    rev[len] = '\0';
    return rev;
}

/* Given two numbers as string add them and return sum as a string */
char* add_ascii(char* first, char* second) {
    int fn = strlen(first);
    int sn = strlen(second);
    
    first = strrev(first);
    second = strrev(second);
    
    // add two because, +1 for addition and another +1 for null terminated string
    int res = 2 + (fn > sn ? fn : sn);
    char* rsum = (char*)malloc(sizeof(char)*res);
    char* sum = rsum;
    
    // Null terminate the string
    *(sum+res-1) = '\0';
    sum = sum+(res-2);
    int carry = 0;
    while(*first && *second) {
        int a = *first-'0';
        int b = *second-'0';
        int c = a+b+carry;
        
        if(c <= 9) {
            // append zero
            *sum = (char)(c+'0');
            carry = 0;
        } else {
            int r = c % 10;
            carry = (int)(c/10);
            *sum = (char)(r+'0');
        }
        
        first++;
        second++;
        if(*first || *second) sum--;
    }
    
    while(*first) {
        if(carry) {
            int n = *first-'0';
            int c = n+carry;
            
            if(c <= 9) {
                // append zero
                *sum = (char)(c+'0');
                carry = 0;
            } else {
                int r = c % 10;
                carry = (int)(c/10);
                *sum = (char)(r+'0');
            }
        } else {
            *sum = *first;
        }
        first++;
        if(*first) sum--;
    }
    
    while(*second) {
        if(carry) {
            int n = *first-'0';
            int c = n+carry;
            
            if(c <= 9) {
                // append zero
                *sum = (char)(c+'0');
                carry = 0;
            } else {
                int r = c % 10;
                carry = (int)(c/10);
                *sum = (char)(r+'0');
            }
        } else {
            *sum = *second;
        }
        second++;
        if(*second) sum--;
    }
    
    // fill the extra spaces with zeros
    while(sum != rsum) {
        *--sum = carry + '0';
    }
    
    
    return sum;
}

/* convert roman to integer */
int rm_conv_int(char* roman) {
    return (int)(rm_conv_llong(roman));
}

/* convert roman to long */
long rm_conv_long(char* roman) {
    return (long)(rm_conv_llong(roman));
}

/* convert roman to long long */
long long rm_conv_llong(char* roman) {
    char* ptr = roman;
    long long number  = 0L;
    
    while(*ptr) {
        int cur = convert(*ptr);
        int nxt = *(ptr+1) ? convert(*(ptr+1)) : 0;
        
        if(cur == INVALID) return INVALID;
        if(nxt == INVALID) number += cur;
        
        if(cur >= nxt) {
            number += cur;
            ptr++;
        } else {
            number += (nxt - cur);
            ptr += 2*sizeof(char);
        }
    }
    return number;
}

/* Generic function: use only if the conversion results in a overflow exception.
    This returns ASCII numeric number. eg: "45667678" */
char* rm_conv_numeric(char* roman) {
    char* ptr = roman;
    char* number = (char*)malloc(sizeof(char) * CHR_LIMIT);

    while(*ptr) {
        int cur = convert(*ptr);
        int nxt = *(ptr+1) ? convert(*(ptr+1)) : 0;

        if(cur == INVALID) return NULL;

        // if(nxt == INVALID) *number = 

        if(cur > nxt) {
            int ans = cur;
        }
    }
    return NULL;
}