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

typedef struct rm_result*(rm_func)(char*, char*);

#define CHECK_ADD(first, second, expectation) {     \
    verify(rm_add, first, second, expectation, '+');     \
}

#define CHECK_SUB(first, second, expectation) {     \
    verify(rm_sub, first, second, expectation, '-');     \
}

extern void verify(rm_func func, char* first, char* second, \
    char* expected, char opr);
extern TCase* tc_adds();
extern TCase* tc_subs();

#endif