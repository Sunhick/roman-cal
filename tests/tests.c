/* tests.h -- header file for unit testcases
 *
 * Copyright (C) 2017 Sunil <sunhick@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include <stdlib.h>
#include <stdio.h>

#include "tests.h"

void verify(rm_func func, char* first, char* second, \
    char* expected, char opr) {
    struct rm_result* result = func(first, second);

#warning "only for testing! In real it will never be null"
    char *val;
    if (result) {
        val = result->value;
    } else {
        printf("Error: %s", result->err_message);
    }
    ck_assert_msg( strcmp(expected, val) == 0,
        "%s %c %s = %s, but got %s", first, opr, second, expected, val);
    if (result) 
        free(result);
}

void __verify(addascii func, char* first, char* second, \
    char* expected, char opr) {
    char* val = func(first, second);
    ck_assert_msg( strcmp(expected, val) == 0,
        "%s %c %s = %s, but got %s", first, opr, second, expected, val);
    free(val);
}

void __verifyconv(rmconv func, char* first, long long expected) {
    long long val = func(first);
    ck_assert_msg( expected == val,
        "%s = %lld, but got %lld", first, expected, val);
}