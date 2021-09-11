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

/** 创建数据库 */
typedef bool (*f_vasm_cvap_database)(void *base, char *name);
__vasm_api f_vasm_cvap_database VASM_CVAP_DATABASE;
#define vasm_cvap_database VASM_CVAP_DATABASE
/** 创建数据表 */
typedef void (*f_vasm_cvap_table)(void *table, char *name);
__vasm_api f_vasm_cvap_table VASM_CVAP_TABLE;
#define vasm_cvap_table VASM_CVAP_TABLE
/** 创建字段 */
typedef void (*f_vasm_cvap_column)(void *column, char *name,
        unsigned char type,
        size_t len,
        char *remark,
        char *vdef);
__vasm_api f_vasm_cvap_column VASM_CVAP_COLUMN;
#define vasm_cvap_column VASM_CVAP_COLUMN
/** 将字段添加到数据表 */
typedef void (*f_vasm_add_column)(void *table, void *col);
__vasm_api f_vasm_add_column VASM_ADD_COLUMN;
#define vasm_add_column VASM_ADD_COLUMN
/** 将数据表添加到数据库 */
typedef void (*f_vasm_add_table)(void *base, void *table);
__vasm_api f_vasm_add_table VASM_ADD_TABLE;
#define vasm_add_table VASM_ADD_TABLE
/** 加载数据库 */
typedef void (*f_vasm_lvap_database)(void *base, char *name);
__vasm_api f_vasm_lvap_database VASM_LVAP_DATABASE;
#define vasm_lvap_database VASM_LVAP_DATABASE
/** 释放数据库指针 */
typedef void (*f_vasm_fvap_database)(void *base);
__vasm_api f_vasm_fvap_database VASM_FVAP_DATABASE;
#define vasm_fvap_database VASM_FVAP_DATABASE
/** 加载数据表 */
typedef void* (*f_vasm_lvap_table)(void *base, char *name);
__vasm_api f_vasm_lvap_table VASM_LVAP_TABLE;
#define vasm_lvap_table VASM_LVAP_TABLE
/** 加载字段 */
typedef void* (*f_vasm_lvap_column)(void *table, char *name);
__vasm_api f_vasm_lvap_column VASM_LVAP_COLUMN;
#define vasm_lvap_column VASM_LVAP_COLUMN
/** 修改数据库名 */
typedef void (*f_vasm_mod_database_name)(void *base, char *oldname, char *newname);
__vasm_api f_vasm_mod_database_name VASM_MOD_DATABASE_NAME;
#define vasm_mod_database_name VASM_MOD_DATABASE_NAME
/** 修改表名 */
typedef void (*f_vasm_mod_table_name)(void *table, char *name);
__vasm_api f_vasm_mod_table_name VASM_MOD_TABLE_NAME;
#define vasm_mod_table_name VASM_MOD_TABLE_NAME
/** 修改表备注 */
typedef void (*f_vasm_mod_table_remark)(void *table, char *remark);
__vasm_api f_vasm_mod_table_remark VASM_MOD_TABLE_REMARK;
#define vasm_mod_table_remark VASM_MOD_TABLE_REMARK
/** 修改字段名 */
typedef void (*f_vasm_mod_column_name)(void *column, char *name);
__vasm_api f_vasm_mod_column_name VASM_MOD_COLUMN_NAME;
#define vasm_mod_column_name VASM_MOD_COLUMN_NAME
/** 修改字段类型 */
typedef void (*f_vasm_mod_column_type)(void *column, unsigned char type);
__vasm_api f_vasm_mod_column_type VASM_MOD_COLUMN_TYPE;
#define vasm_mod_column_type VASM_MOD_COLUMN_TYPE
/** 修改字段长度 */
typedef void (*f_vasm_mod_column_len)(void *column, size_t len);
__vasm_api f_vasm_mod_column_len VASM_MOD_COLUMN_LEN;
#define vasm_mod_column_len VASM_MOD_COLUMN_LEN
/** 修改字段是否可空 */
typedef void (*f_vasm_mod_column_allow_null)(void *column, bool allownull);
__vasm_api f_vasm_mod_column_allow_null VASM_MOD_COLUMN_ALLOW_NULL;
#define vasm_mod_column_allow_null VASM_MOD_COLUMN_ALLOW_NULL
/** 修改字段默认值 */
typedef void (*f_vasm_mod_column_defval)(void *column, char *defval);
__vasm_api f_vasm_mod_column_defval VASM_MOD_COLUMN_DEFVAL;
#define vasm_mod_column_defval VASM_MOD_COLUMN_DEFVAL
/** 修改字段备注 */
typedef void (*f_vasm_mod_column_remark)(void *column, char *remark);
__vasm_api f_vasm_mod_column_remark VASM_MOD_COLUMN_REMARK;
#define vasm_mod_column_remark VASM_MOD_COLUMN_REMARK
/** 提交数据库修改内容 */
typedef void (*f_vasm_mod_database_submit)(void *base);
__vasm_api f_vasm_mod_database_submit VASM_MOD_DATABASE_SUBMIT;
#define vasm_mod_database_submit VASM_MOD_DATABASE_SUBMIT
/** 提交表修改内容 */
typedef void (*f_vasm_mod_table_submit)(void *base, void *table);
__vasm_api f_vasm_mod_table_submit VASM_MOD_TABLE_SUBMIT;
#define vasm_mod_table_submit VASM_MOD_TABLE_SUBMIT
/** 提交字段修改内容 */
typedef void (*f_vasm_mod_column_submit)(void *base, void *table, void *column);
__vasm_api f_vasm_mod_column_submit VASM_MOD_COLUMN_SUBMIT;
#define vasm_mod_column_submit VASM_MOD_COLUMN_SUBMIT

static void loadvasm()
{
        VASM_CVAP_DATABASE = (f_vasm_cvap_database) create_database;
        VASM_CVAP_TABLE = (f_vasm_cvap_table) table_init;
        VASM_CVAP_COLUMN = (f_vasm_cvap_column) column_init;
        VASM_ADD_COLUMN = (f_vasm_add_column) table_add_column;
        VASM_ADD_TABLE = (f_vasm_add_table) vacat_add_table;
        VASM_LVAP_DATABASE = (f_vasm_lvap_database) vacat_add_table;
        VASM_LVAP_TABLE = (f_vasm_lvap_table) vacat_get_table;
        VASM_LVAP_COLUMN = (f_vasm_lvap_column) table_get_column;
        VASM_LVAP_DATABASE = (f_vasm_lvap_database) load_database;
        VASM_FVAP_DATABASE = (f_vasm_fvap_database) destroy_database;
        VASM_MOD_DATABASE_NAME = (f_vasm_mod_database_name) modify_database_name;
}

/**
 * 编译.vasm文件
 *
 * @param vacatpath 文件路径
 */
extern void vacat_exec_comp(char *vacatpath);

#endif /* _VASM_H */
