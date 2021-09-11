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
#ifndef _DATABASE_H
#define _DATABASE_H

#include "table.h"

#define TABLE_ARRAY_SIZE 16

struct database {
        char name[_NAME_MAX];
        size_t tabnum;
        size_t arrsize;
        char pathname[_PATH_MAX];
        struct table *tables;           /* 表结构体列表 */
};

/** 初始化数据库 */
inline void database_init(struct database *base, const char *pathname, const char *name);
/** 创建数据库, 并序列化到文件中 */
bool create_database(struct database *base, char *name);
/** 销毁数据库结构体所占用的内存 */
void destroy_database(struct database *database);
/** 添加一张表到数据库 */
void vacat_add_table(struct database *base, struct table *table);
/** 获取一张表 */
struct table* vacat_get_table(struct database *base, const char *name);
/** 加载数据库 */
extern bool load_database(struct database *base, const char *basedir, const char *name);

#endif // _DATABASE_H
