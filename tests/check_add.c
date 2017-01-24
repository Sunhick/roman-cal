/* check_add.c -- unit testcases for addition of roman numerals
 *
 * Copyright (C) 2017 Sunil <sunhick@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include <check.h>
#include <stddef.h>
#include <stdio.h>

#include "tests.h"

START_TEST (test0) {
    CHECK_ADD("I", "V", "VI");
    CHECK_ADD("I", "IV", "V");
    CHECK_ADD("I", "", "I");
}
END_TEST

START_TEST (test1) {
    CHECK_ADD("I", "V", "VI");
    CHECK_ADD("I", "IV", "V");
    CHECK_ADD("I", "", "I");
}
END_TEST

START_TEST (test2) {
    CHECK_ADD("I", "V", "VI");
    CHECK_ADD("I", "IV", "V");
    CHECK_ADD("I", "", "I");
}
END_TEST


TCase* tc_adds() {
    TCase *addtc = tcase_create("rm-add");
    tcase_add_test(addtc, test0);
    tcase_add_test(addtc, test1);
    tcase_add_test(addtc, test2);
    return addtc;
}