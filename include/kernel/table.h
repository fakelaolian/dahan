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
#ifndef _TABLE_H
#define _TABLE_H

#include "column.h"

#define COLUMN_ARRAY_SIZE 16

struct table {
        char name[__cfs_name_len];
        size_t colnum;                          /* 字段个数 */
        size_t arrsize;                         /* 存放字段结构体的数组大小 */
        char remark[__cfs_remark_len];              /* 备注 */
        struct column *columns;                 /* 结构体数组 */
};

inline static void table_init(struct table *table, char *name, char *remark)
{
        table->colnum = 0;
        table->arrsize = COLUMN_ARRAY_SIZE;
        strncpy(table->name, name, __cfs_name_len);
        strncpy(table->remark, remark, __cfs_remark_len);
        table->columns = kmalloc(sizeof(struct column) * COLUMN_ARRAY_SIZE);
}

inline static void destroy_table(struct table *table)
{
        kfree(table->columns);
}

/** 添加字段 */
void table_add_column(struct table *table, struct column *column);
/** 根据名称获取表中的字段指针 */
struct column *table_get_column(struct table *table, const char *name);

#endif // _TABLE_H