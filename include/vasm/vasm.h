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

/*! ===> Creates on 2021/9/11. <=== */

/*!
 * @author 范特西
 */
#ifndef _VASM_H
#define _VASM_H

#include <gext_api.h>
#include <kernel/database.h>

#define __vasm_api __gext_api__

/** 加载数据库 */
typedef void (*f_vasm_lvap_database)(struct database *base, const char *name);
__vasm_api f_vasm_lvap_database VASM_LVAP_DATABASE;
#define vasm_lvap_database VASM_LVAP_DATABASE
/** 加载数据表 */
typedef void (*f_vasm_lvap_table)(struct database *base, struct table *table, const char *name);
__vasm_api f_vasm_lvap_table VASM_LVAP_TABLE;
#define vasm_lvap_table VASM_LVAP_TABLE
/** 加载字段 */
typedef void (*f_vasm_lvap_column)(struct table *table, struct column *column, const char *name);
__vasm_api f_vasm_lvap_column VASM_LVAP_COLUMN;
#define vasm_lvap_column VASM_LVAP_COLUMN
/** 修改数据库名 */
typedef void (*f_vasm_mod_database_name)(struct database *base, const char *name);
__vasm_api f_vasm_mod_database_name VASM_MOD_DATABASE_NAME;
#define vasm_mod_database_name VASM_MOD_DATABASE_NAME
/** 修改表名 */
typedef void (*f_vasm_mod_table_name)(struct table *table, const char *name);
__vasm_api f_vasm_mod_table_name VASM_MOD_TABLE_NAME;
#define vasm_mod_table_name VASM_MOD_TABLE_NAME
/** 修改表备注 */
typedef void (*f_vasm_mod_table_remark)(struct table *table, const char *remark);
__vasm_api f_vasm_mod_table_remark VASM_MOD_TABLE_REMARK;
#define vasm_mod_table_remark VASM_MOD_TABLE_REMARK
/** 修改字段名 */
typedef void (*f_vasm_mod_column_name)(struct column *column, const char *name);
__vasm_api f_vasm_mod_column_name VASM_MOD_COLUMN_NAME;
#define vasm_mod_column_name VASM_MOD_COLUMN_NAME
/** 修改字段类型 */
typedef void (*f_vasm_mod_column_type)(struct column *column, unsigned char type);
__vasm_api f_vasm_mod_column_type VASM_MOD_COLUMN_TYPE;
#define vasm_mod_column_type VASM_MOD_COLUMN_TYPE
/** 修改字段长度 */
typedef void (*f_vasm_mod_column_len)(struct column *column, size_t len);
__vasm_api f_vasm_mod_column_len VASM_MOD_COLUMN_LEN;
#define vasm_mod_column_len VASM_MOD_COLUMN_LEN
/** 修改字段是否可空 */
typedef void (*f_vasm_mod_column_allow_null)(struct column *column, bool allownull);
__vasm_api f_vasm_mod_column_allow_null VASM_MOD_COLUMN_ALLOW_NULL;
#define vasm_mod_column_allow_null VASM_MOD_COLUMN_ALLOW_NULL
/** 修改字段默认值 */
typedef void (*f_vasm_mod_column_defval)(struct column *column, const char *defval);
__vasm_api f_vasm_mod_column_defval VASM_MOD_COLUMN_DEFVAL;
#define vasm_mod_column_defval VASM_MOD_COLUMN_DEFVAL
/** 修改字段备注 */
typedef void (*f_vasm_mod_column_remark)(struct column *column, const char *remark);
__vasm_api f_vasm_mod_column_remark VASM_MOD_COLUMN_REMARK;
#define vasm_mod_column_remark VASM_MOD_COLUMN_REMARK

/**
 * 编译.vasm文件
 *
 * @param vacatpath 文件路径
 */
extern void vacat_exec_comp(const char *vacatpath);

#endif /* _VASM_H */