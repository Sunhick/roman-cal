/* tests.h -- header file for unit testcases
 *
 * Copyright (C) 2017 Sunil <sunhick@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef TESTS_H
#define TESTS_H

#include <check.h>

#include "rmconv.h"
#include "rmcalc.h"

/* shorthand function pointers */
typedef struct rm_result*(rm_func)(char*, char*);
typedef char*(addascii)(char*, char*);
typedef long long (rmconv)(char*);
typedef char* (rmllconv)(long long);

#define CHECK_ADD(first, second, expectation) {                 \
    verify(rm_add, first, second, expectation, '+');            \
}

#define CHECK_SUB(first, second, expectation) {                 \
    verify(rm_sub, first, second, expectation, '-');            \
}

#define CHECK_ADD_ASCII(first, second, expectation) {           \
    __verify(add_ascii, first, second, expectation, '+');       \
}

#define CHECK_RM_NUMERAL(first, expectation) {                  \
    __verifyconv(rm_conv_llong, first, expectation);            \
}

#define CHECK_NUMERAL(first, expectation) {                       \
    __verifyllconv(rm_llong_conv, first, expectation);            \
}

/* verification function wrappers */
extern void verify(rm_func func, char* first, char* second, char* expected, char opr);
extern void __verify(addascii func, char* first, char* second, char* expected, char opr);
extern void __verifyconv(rmconv func, char* first, long long expected);
extern void __verifyllconv(rmllconv func, long long first, char* expected);

extern TCase* tc_adds();
extern TCase* tc_subs();
extern TCase* tc_utils();

#endif