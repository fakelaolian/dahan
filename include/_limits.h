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

/*! ===> Creates on 2021/9/7. <=== */

/*!
 * @author TianSheng
 */
#ifndef _F_LIMITS_H
#define _F_LIMITS_H

#include <limits.h>

#define DH_CUT_NAME_SIZE          60           /* 名称截取建议大小 */
#define DH_NAME_MAX               200          /* 表名或函数名最大长度 */
#define DH_REMARK_MAX             300          /* 备注最大长度 */
#define DH_VDEF_MAX               200          /* 默认值最大长度 */
/* 路径最大长度 */
#ifdef WIN32
#    define DH_PATH_MAX           256
#elif linux
#    define DH_PATH_MAX           600
#else
#    define DH_PATH_MAX           300
#endif /* WIN32 */

#endif /* _F_LIMITS_H */
