/* check_add_ascii.c -- unit testcases for addition of ascii numerals
 *
 * Copyright (C) 2017 Sunil <sunhick@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include <check.h>
#include <stddef.h>
#include <stdio.h>

#include "rmconv.h"
#include "tests.h"

START_TEST (test0) {
    CHECK_ADD_ASCII("1", "1", "02");
    CHECK_ADD_ASCII("1", "1", "02");
    CHECK_ADD_ASCII("1", "1", "02");
}
END_TEST

START_TEST (test1) {
    CHECK_ADD_ASCII("1", "1", "02");
    CHECK_ADD_ASCII("1", "1", "02");
    CHECK_ADD_ASCII("1", "1", "02");
}
END_TEST

START_TEST (test2) {
    CHECK_ADD_ASCII("1", "1", "02");
    CHECK_ADD_ASCII("1", "1", "02");
    CHECK_ADD_ASCII("1", "1", "02");
}
END_TEST


TCase* tc_adds_ascii() {
    TCase *addtc = tcase_create("add-ascii");
    tcase_add_test(addtc, test0);
    tcase_add_test(addtc, test1);
    tcase_add_test(addtc, test2);
    return addtc;
}