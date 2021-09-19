/*! ************************************************************************
 *
 * Copyright (C) 2020 LuoTianSheng All rights reserved.
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
 * @author TianSheng
 */
#ifndef _GUTIL_H
#define _GUTIL_H

#include <string.h>
#include <stdarg.h>
#include <types.h>

/** 修剪字符串去除首部空格 */
void ltrim(char *str);
/** 修剪字符串去除末尾空格 */
void rtrim(char *str);
/** 修剪字符串去除前后空格 */
inline void trim(char *str);
/** 格式化字符串 */
__attribute__((format (printf, 3, 4)))
int xsnprintf(char *dest, size_t max, const char *fmt, ...);

#endif /* _GUTIL_H */
