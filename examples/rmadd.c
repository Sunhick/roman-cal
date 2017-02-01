/* rmadd.c -- example of roman additions
 *
 * Copyright (C) 2017 Sunil <sunhick@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include <stdio.h>
#include <stdlib.h>

#include "rmcalc.h"

int main() {
    char first[10], second[10];
    scanf("%s", first);
    scanf("%s", second);

    struct rm_result* res = rm_add(first, second);
    if (res->errcode != ERROR) {
        printf("Result = %s\n", res->value);
    } else {
        printf("ERR: %s\n", res->err_message);
    }

    free(res);
    return 0;
}