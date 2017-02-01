/* check_add.c -- unit testcases for subtraction of roman numerals
 *
 * Copyright (C) 2017 Sunil <sunhick@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include <check.h>
#include <stddef.h>

#include "rmconv.h"
#include "tests.h"

START_TEST (test0) {
    CHECK_SUB("I", "V", "IV");
    CHECK_SUB("I", "IV", "III");
    CHECK_SUB("I", "", "I");
}
END_TEST

START_TEST (test1) {
    CHECK_SUB("I", "V", "IV");
    CHECK_SUB("I", "IV", "III");
    CHECK_SUB("I", "", "I");
}
END_TEST

START_TEST (test2) {
    CHECK_SUB("I", "V", "IV");
    CHECK_SUB("I", "IV", "III");
    CHECK_SUB("I", "", "I");
}
END_TEST

TCase* tc_subs() {
    TCase *subtc = tcase_create("rm-sub");
    tcase_add_test(subtc, test0);
    tcase_add_test(subtc, test1);
    tcase_add_test(subtc, test2);
    return subtc;
}