/* rmconv.c -- impl file for converting roman to numeric. 
 *
 * Copyright (C) 2017 Sunil <sunhick@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include <stddef.h>

#include "headers/rmconv.h"

/* convert roman to integer */
int rm_conv_int(char* roman) {
    return 0;
}

/* convert roman to long */
long rm_conv_long(char* roman) {
    return 0L;
}

/* convert roman to long long */
long long rm_conv_llong(char* roman) {
    return 0L;
}

/* Generic function: use only if the conversion results in a overflow exception.
    This returns ASCII numeric number. eg: "45667678" */
char* rm_conv_numeric(char* roman) {
    return NULL;
}