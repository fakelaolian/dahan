/*! ************************************************************************
 *
 * Copyright (C) 2020 netforklabs All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *! ************************************************************************/

/*! ===> Creates on 2021/9/5. <=== */

/*!
 * @author 范特西
 */
#ifndef _GUTIL_H
#define _GUTIL_H

#include "glibc.h"

__attribute__((format (printf, 3, 4)))
int xsprintf(char *dest, size_t max, const char *fmt, ...);

#endif /* _GUTIL_H */
