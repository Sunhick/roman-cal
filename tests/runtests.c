/* runtests.h -- run all test cases
 *
 * Copyright (C) 2017 Sunil <sunhick@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include <check.h>

#include "tests.h"

int main() {
    Suite *all = suite_create("rmcalc_tests");
    
    suite_add_tcase(all, tc_adds_ascii());
    // suite_add_tcase(all, tc_adds());
    // suite_add_tcase(all, tc_subs());
    
    SRunner *runner = srunner_create(all);
    srunner_run_all(runner, CK_NORMAL);
    // int failures = srunner_ntests_failed(runner);
    // srunner_free(runner);

    return 0;
}