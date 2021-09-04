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

struct database {
        char* name;
        size_t tabnum;
        size_t arrsize;
        struct table* tables;
};

/** 初始化数据库 */
inline void database_init(struct database *database, char *name);

/** 添加一张表到数据库 */
void database_add_table(struct database *database, struct table *table);

/** 获取一张表 */
struct table* database_get_table(struct database *database, const char *name);

#endif // _DATABASE_H
