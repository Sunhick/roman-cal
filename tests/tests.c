/* tests.h -- header file for unit testcases
 *
 * Copyright (C) 2017 Sunil <sunhick@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include <stdlib.h>

#include "tests.h"

void verify(rm_func func, char* first, char* second, \
    char* expected, char opr) {
    struct rm_result* result = func(first, second);

#warning "only for testing! In real it will never be null"
    char *val;
    if (result) {
        val = result->value;
    }

    ck_assert_msg( strcmp(expected, val) == 0,
        "%s %c %s = %s, but got %s", first, opr, second, expected, val);
    if (result) 
        free(result);
}