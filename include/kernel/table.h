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
#ifndef _TABLE_H
#define _TABLE_H

#include "aat.h"

struct table {
        char name[DH_NAME_MAX];
        uint colnum;                            /* 字段个数 */
        size_t size;                            /* 数据大小 */
        size_t blocksize;                       /* 数据块大小 */
        char remark[DH_REMARK_MAX];             /* 备注 */
        datafile_t *datafile;                   /* 数据文件 */
        struct aat *aat;                        /* 区域分配表 */
        struct linked *columns;                 /* 字段链表 */
};

#define COLVALUE(__va__) ((struct column *) __va__)

/** 初始化表 */
inline void create_table(struct table *table, char *name);
/** 释放表数据 */
inline void table_destroy(struct table *table);
/** 添加字段 */
void table_add_column(struct table *table, struct column *column);
/** 根据名称获取表中的字段指针 */
__always_inline__
struct column *get_column(struct table *table, const char *name);
/* 删除链表内容 */
void table_linked_remove(struct table *table, const char *name);
#define table_remove_column(__table, __name) table_linked_remove(__table, __name)

#endif // _TABLE_H