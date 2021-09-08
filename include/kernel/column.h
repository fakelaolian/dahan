/*! ************************************************************************
 *
 * Copyright (C) 2020 luots All rights reserved.
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
 * @author 范特西
 */
#ifndef _COLUMN_H
#define _COLUMN_H

#include <glibc.h>
#include <gtools.h>
#include "kconfig.h"
#include "aux/kcheck.h"

/**
 * 字段类型枚举
 */
ENUM COLTYPE {
        _INT,
        _VARCHAR,
        _FLOAT,
        _DECIMAL,
        _TEXT,
};

struct column {
        char name[CFS_NAME_MAX];
        unsigned char type;             /* 字段类型 */
        unsigned int len;               /* 字段长度（仅限于可变长度的字段） */
        char remark[CFS_REMARK_MAX];    /* 备注 */
        char vdef[CFS_VDEF_MAX];        /* 默认值 */
};

/**
 * 初始化字段信息
 *
 * @param column    指针
 * @param name      字段名
 * @param type      字段类型， 参考<ENUM COLTYPE>
 * @param len       字段长度
 */
inline void column_init(struct column *column,
                        char *name,
                        unsigned int type,
                        unsigned len);

#endif // _COLUMN_H