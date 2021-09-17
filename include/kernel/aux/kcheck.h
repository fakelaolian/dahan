/*! ************************************************************************
 *
 * Copyright (C) 2020 luotiansheng All rights reserved.
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

/*! ===> Creates on 2021/9/8. <=== */

/*!
 * 检测工具
 *
 * @author tiansheng
 */
#ifndef _KCHECK_H
#define _KCHECK_H

#include <stdbool.h>
#include <tools/files.h>

/**
 * 校验字段名是否重复
 *
 * @param sp        字段结构体数组指针
 * @param size      数组大小
 * @param name      新增的字段名
 */
inline bool
kcheck_column_name_dup(const void *sp, size_t size, const char *name);

/**
 * 校验表名是否重复
 *
 * @param sp        表结构体数组指针
 * @param size      数组大小
 * @param name      新增的表名
 */
inline bool
kcheck_table_name_dup(const void *sp, size_t size, const char *name);

/**
 * 检查数据库名是否重复
 *
 * @param pathname  数据库存放目录
 * @param name      数据库名称
 */
inline bool
kcheck_database_name_dup(const char *pathname, const char *name);

#endif /* _KCHECK_H */
