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

/*! ===> Creates on 2021/9/4. <=== */

/*!
 * @author 范特西
 */
#ifndef _DATABASE_H
#define _DATABASE_H

#include "table.h"

#define TABLE_ARRAY_SIZE 16

struct database {
        char *name;
        size_t tabnum;
        size_t arrsize;
        char path[PATH_MAX];
        struct table *tables;           /* 表结构体列表 */
};

/** 初始化数据库 */
inline static void priv_database_init(struct database *base, char *name)
{
        base->name = name;
        base->tabnum = 0;
        base->arrsize = TABLE_ARRAY_SIZE;
        base->tables = kmalloc(sizeof(struct table) * TABLE_ARRAY_SIZE);
}

/** 创建数据库, 并序列化到文件中 */
void create_database(struct database *base, char *name);
/** 销毁数据库结构体所占用的内存 */
inline static void destroy_database(struct database *database)
{
        size_t i;
        for (i = 0; i < database->tabnum; i++)
                destroy_table((database->tables + i));
        kfree(database->tables);
}
/** 添加一张表到数据库 */
void database_add_table(struct database *base, struct table *table);
/** 获取一张表 */
struct table* database_get_table(struct database *base, const char *name);
/** TODO 加载数据库 */
void database_load(struct database *base, const char *name);

#endif // _DATABASE_H
