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

/*! ===> Creates on 2021/9/12. <=== */

/*!
 * @author TianSheng
 */
#ifndef _KERNEL_OPTIONS_H
#define _KERNEL_OPTIONS_H

#include "database.h"

/*! --------------------------------- 和表有关的操作 ------------------------------------- */
/** 修改表名 */
void modify_table_name(struct database *base, const char *oldname, const char *newname);
/** 添加一张表到数据库 */
inline void add_table(struct database *base, struct table *table);
/** 添加一张表到数据库（反序列化时使用） */
inline void ladd_table(struct database *base, struct table *table);
/** 获取一张表 */
struct table* get_table(struct database *base, const char *name);
/** ----------------------------------------------- ------------------------------------- */


/*! --------------------------------- 和数据库有关的操作 ------------------------------------- */
/*! 加载数据库 */
void load_database(struct database *base, const char *name);
/** 添加一条数据 */
void insert(struct database *base, const char *tabname);
/** 修改数据库名 */
void modify_database_name(struct database *base, const char *oldname, const char *newname);
/** ----------------------------------------------- ------------------------------------------ */


/*! --------------------------------- 和字段有关的操作 ------------------------------------- */
/**
 * 修改字段信息，本来是打算每个属性都写单个函数的。
 * 但是如果这样做的话如果同时修改多个内容那么就会写入多次IO，风险较大不合适数据的原子性操作。
 *
 * 如果无需修改的属性参数设置为NULL即可，type和len设置为0即可
 */
void modify_column(struct database *base,
                        const char *name,               /* <table name>/<column name> */
                        const char *newname,
                        unsigned char type,
                        uint len,
                        const char *remark,
                        const char *vdef);
/** 删除字段, 参数为:
 *      <database name>/<table name>/<column name>
 */
void remove_column(const char *path);
/** --------------------------------------------------------------------------------------- */

#endif /* _KERNEL_OPTIONS_H */
