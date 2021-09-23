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

/*! ===> Creates on 2021/9/18. <=== */

/*!
 * @author TianSheng
 */
#ifndef _TYPES_H
#define _TYPES_H

#define uc unsigned char
#define u4 unsigned int
#define u8 unsigned long
#define int64 long long
#define uint64 unsigned int64

#define bool uc
#define true  1
#define false 0

#ifdef WIN32
#       define __always_inline__ inline
#elif linux
#       define __always_inline__ __always_inline
#endif

#endif /* _TYPES_H */
