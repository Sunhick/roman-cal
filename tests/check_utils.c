/* check_utils.c -- unit testcases for utility functions in rm cacl
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

// check ascii additions
START_TEST (test0) {
    CHECK_ADD_ASCII("1", "1", "02");
    CHECK_ADD_ASCII("16", "7", "023");
    CHECK_ADD_ASCII("0", "0", "00");
    CHECK_ADD_ASCII("1234567890", "1234567890", "02469135780");
    CHECK_ADD_ASCII("1", "1234567890", "01234567891");
    CHECK_ADD_ASCII("0", "00", "000");
}
END_TEST

// check roman conversions
START_TEST (test1) {
    CHECK_RM_NUMERAL("DCCLXXXIX", 789);
    CHECK_RM_NUMERAL("MMCMLVI", 2956);
    CHECK_RM_NUMERAL("V", 5);
    CHECK_RM_NUMERAL("IX", 9);
    CHECK_RM_NUMERAL("XII", 12);
    CHECK_RM_NUMERAL("XVI", 16);
    CHECK_RM_NUMERAL("XXIX", 29);
    CHECK_RM_NUMERAL("XLIV", 44);
    CHECK_RM_NUMERAL("XLV", 45);
    CHECK_RM_NUMERAL("LXVIII", 68);
    CHECK_RM_NUMERAL("LXXXIII", 83);
    CHECK_RM_NUMERAL("XCVII", 97);
    CHECK_RM_NUMERAL("XCIX", 99);
    CHECK_RM_NUMERAL("D", 500);
    CHECK_RM_NUMERAL("DI", 501);
    CHECK_RM_NUMERAL("DCXLIX", 649);
    CHECK_RM_NUMERAL("DCCXCVIII", 798);
    CHECK_RM_NUMERAL("DCCCXCI", 891);
    CHECK_RM_NUMERAL("M", 1000);
    CHECK_RM_NUMERAL("MIV", 1004);
    CHECK_RM_NUMERAL("MVI", 1006);
    CHECK_RM_NUMERAL("MXXIII", 1023);
    CHECK_RM_NUMERAL("MMXIV", 2014);
    CHECK_RM_NUMERAL("MMMCMXCIX", 3999);
}
END_TEST

// check ascii subtractions
START_TEST (test2) {
}
END_TEST


TCase* tc_utils() {
    TCase *addtc = tcase_create("utils-ascii");
    tcase_add_test(addtc, test0);
    tcase_add_test(addtc, test1);
    tcase_add_test(addtc, test2);
    return addtc;
}