/* rmresult.h -- defines rm result structure
 *
 * Copyright (C) 2017 Sunil <sunhick@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef RM_RESULT_H
#define RM_RESULT_H

#define INVALID_ROMAN         0xE77
#define SUCCESS               0x099
#define ERROR                 0xBAD

/* defines the rm_result structure */
struct rm_result {
    char* value;
    char* err_message;
    int errcode;
};

#endif