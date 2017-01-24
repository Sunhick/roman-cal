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

#include "headers/rmresult.h"

void verify(char* first, char* second, char* expected) {
    struct rm_result* result = rm_add(first, second);
    ck_assert_msg( strcmp(expected, result->value) == 0,
        "%s + %s = %s, but got %s", first, second, expected, actual);
    free(result);
}

extern TCase *tc_adds();
extern TCase *tc_subs();

#endif