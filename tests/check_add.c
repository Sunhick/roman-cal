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

#include "headers/rmcalc.h"

START_TEST (test0) {
    verify("I", "V", "VI");
    verify("I", "IV", "V");
    verify("I", "", "I");
}
END_TEST

START_TEST (test1) {
    verify("I", "V", "VI");
    verify("I", "IV", "V");
    verify("I", "", "I");
}
END_TEST

START_TEST (test2) {
    verify("I", "V", "VI");
    verify("I", "IV", "V");
    verify("I", "", "I");
}
END_TEST


TCase* tc_adds() {
    return NULL;
}