/* rmconv.h -- helper file for converting roman to numeric. 
 *
 * Copyright (C) 2017 Sunil <sunhick@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef RM_CONV_H
#define RM_CONV_H

#define INVALID     -999
#define CHR_LIMIT   10

/* convert roman to integer */
int rm_conv_int(char* roman);

/* convert roman to long */
long rm_conv_long(char* roman);

/* convert roman to long long */
long long rm_conv_llong(char* roman);

/* Generic function: use only if the conversion results in a overflow exception.
    This returns ASCII numeric number. eg: "45667678" */
char* rm_conv_numeric(char* roman);

/* Convert number to a roman numerals */
char* rm_llong_conv(long long number);

/* Convert ascii number to roman numerals */
char* rm_ascii_conv(char* number);

/* add the string numbers */
char* add_ascii(char* first, char* second);

#endif