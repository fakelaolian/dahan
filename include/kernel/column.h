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

/*! ===> Creates on 2021/9/4. <=== */

/*!
 * @author TianSheng
 */
#ifndef _COLUMN_H
#define _COLUMN_H

#include "kconfig.h"
#include "a/kcheck.h"
#include "a/comm.h"
#include "eng/datafile.h"

struct column {
        char name[DH_NAME_MAX];
        unsigned char type;               /* 字段类型 */
        uint len;                         /* 字段长度（仅限于可变长度的字段） */
        char remark[DH_REMARK_MAX];       /* 备注 */
        char vdef[DH_VDEF_MAX];           /* 默认值 */
};

/**
 * 初始化字段信息
 *
 * @param column    指针
 * @param name      字段名
 * @param type      字段类型， 参考<ENUM COLTYPE>
 * @param len       字段长度
 */
inline void create_column(struct column *column,
                        char *name,
                        unsigned char type,
                        size_t len,
                        char *remark,
                        char *vdef);

#endif // _COLUMN_H