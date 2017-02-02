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
START_TEST (test_add_ascii) {
    CHECK_ADD_ASCII("1", "1", "02");
    CHECK_ADD_ASCII("16", "7", "023");
    CHECK_ADD_ASCII("0", "0", "00");
    CHECK_ADD_ASCII("1234567890", "1234567890", "02469135780");
    CHECK_ADD_ASCII("1", "1234567890", "01234567891");
    CHECK_ADD_ASCII("0", "00", "000");
}
END_TEST

// check roman conversions
START_TEST (test_rm_conv) {
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

// check to roman conversions
START_TEST (test_rm_llong_conv) {
    CHECK_NUMERAL(789, "DCCLXXXIX");
    CHECK_NUMERAL(2956, "MMCMLVI");
    CHECK_NUMERAL(5, "V");
    CHECK_NUMERAL(9, "IX");
    CHECK_NUMERAL(12, "XII");
    CHECK_NUMERAL(16, "XVI");
    CHECK_NUMERAL(29, "XXIX");
    CHECK_NUMERAL(44, "XLIV");
    CHECK_NUMERAL(45, "XLV");
    CHECK_NUMERAL(68, "LXVIII");
    CHECK_NUMERAL(83, "LXXXIII");
    CHECK_NUMERAL(97, "XCVII");
    CHECK_NUMERAL(99, "XCIX");
    CHECK_NUMERAL(500, "D");
    CHECK_NUMERAL(501, "DI");
    CHECK_NUMERAL(649, "DCXLIX");
    CHECK_NUMERAL(798, "DCCXCVIII");
    CHECK_NUMERAL(891, "DCCCXCI");
    CHECK_NUMERAL(1000, "M");
    CHECK_NUMERAL(1004, "MIV");
    CHECK_NUMERAL(1006, "MVI");
    CHECK_NUMERAL(1023, "MXXIII");
    CHECK_NUMERAL(2014, "MMXIV");
    CHECK_NUMERAL(3999, "MMMCMXCIX");
}
END_TEST

// check ascii subtractions
START_TEST (test2) {
}
END_TEST


TCase* tc_utils() {
    TCase *addtc = tcase_create("rm-utils");
    tcase_add_test(addtc, test_add_ascii);
    tcase_add_test(addtc, test_rm_conv);
    tcase_add_test(addtc, test2);
    tcase_add_test(addtc, test_rm_llong_conv);
    return addtc;
}