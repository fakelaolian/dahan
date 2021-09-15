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
#ifndef _INST_SET_H
#define _INST_SET_H

#include <gext_api.h>
#include <kernel/options.h>

#define __inst_set_api __gext_api__

/** 创建数据库 */
typedef bool (*f_inst_set_cvap_database)(void *base, char *name);
__inst_set_api f_inst_set_cvap_database INST_SET_CVAP_DATABASE;
#define inst_set_cvap_database INST_SET_CVAP_DATABASE
/** 创建数据表 */
typedef void (*f_inst_set_cvap_table)(void *table, char *name);
__inst_set_api f_inst_set_cvap_table INST_SET_CVAP_TABLE;
#define inst_set_cvap_table INST_SET_CVAP_TABLE
/** 创建字段 */
typedef void (*f_inst_set_cvap_column)(void *column, char *name,
        unsigned char type,
        size_t len,
        char *remark,
        char *vdef);
__inst_set_api f_inst_set_cvap_column INST_SET_CVAP_COLUMN;
#define inst_set_cvap_column INST_SET_CVAP_COLUMN
/** 将字段添加到数据表 */
typedef void (*f_inst_set_add_column)(void *table, void *col);
__inst_set_api f_inst_set_add_column INST_SET_ADD_COLUMN;
#define inst_set_add_column INST_SET_ADD_COLUMN
/** 将数据表添加到数据库 */
typedef void (*f_inst_set_add_table)(void *base, void *table);
__inst_set_api f_inst_set_add_table INST_SET_ADD_TABLE;
#define inst_set_add_table INST_SET_ADD_TABLE
/** 加载数据库 */
typedef void (*f_inst_set_lvap_database)(void *base, char *name);
__inst_set_api f_inst_set_lvap_database INST_SET_LVAP_DATABASE;
#define inst_set_lvap_database INST_SET_LVAP_DATABASE
/** 释放数据库指针 */
typedef void (*f_inst_set_fvap_database)(void *base);
__inst_set_api f_inst_set_fvap_database INST_SET_FVAP_DATABASE;
#define inst_set_fvap_database INST_SET_FVAP_DATABASE
/** 加载数据表 */
typedef void* (*f_inst_set_lvap_table)(void *base, char *name);
__inst_set_api f_inst_set_lvap_table INST_SET_LVAP_TABLE;
#define inst_set_lvap_table INST_SET_LVAP_TABLE
/** 加载字段 */
typedef void* (*f_inst_set_lvap_column)(void *table, char *name);
__inst_set_api f_inst_set_lvap_column INST_SET_LVAP_COLUMN;
#define inst_set_lvap_column INST_SET_LVAP_COLUMN
/** 修改数据库名 */
typedef void (*f_inst_set_mod_database_name)(void *base, char *oldname, char *newname);
__inst_set_api f_inst_set_mod_database_name INST_SET_MOD_DATABASE_NAME;
#define inst_set_mod_database_name INST_SET_MOD_DATABASE_NAME
/** 修改表名 */
typedef void (*f_inst_set_mod_table_name)(void *table, char *name);
__inst_set_api f_inst_set_mod_table_name INST_SET_MOD_TABLE_NAME;
#define inst_set_mod_table_name INST_SET_MOD_TABLE_NAME
/** 修改表备注 */
typedef void (*f_inst_set_mod_table_remark)(void *table, char *remark);
__inst_set_api f_inst_set_mod_table_remark INST_SET_MOD_TABLE_REMARK;
#define inst_set_mod_table_remark INST_SET_MOD_TABLE_REMARK
/** 修改字段名 */
typedef void (*f_inst_set_mod_column_name)(void *column, char *name);
__inst_set_api f_inst_set_mod_column_name INST_SET_MOD_COLUMN_NAME;
#define inst_set_mod_column_name INST_SET_MOD_COLUMN_NAME
/** 修改字段类型 */
typedef void (*f_inst_set_mod_column_type)(void *column, unsigned char type);
__inst_set_api f_inst_set_mod_column_type INST_SET_MOD_COLUMN_TYPE;
#define inst_set_mod_column_type INST_SET_MOD_COLUMN_TYPE
/** 修改字段长度 */
typedef void (*f_inst_set_mod_column_len)(void *column, size_t len);
__inst_set_api f_inst_set_mod_column_len INST_SET_MOD_COLUMN_LEN;
#define inst_set_mod_column_len INST_SET_MOD_COLUMN_LEN
/** 修改字段是否可空 */
typedef void (*f_inst_set_mod_column_allow_null)(void *column, bool allownull);
__inst_set_api f_inst_set_mod_column_allow_null INST_SET_MOD_COLUMN_ALLOW_NULL;
#define inst_set_mod_column_allow_null INST_SET_MOD_COLUMN_ALLOW_NULL
/** 修改字段默认值 */
typedef void (*f_inst_set_mod_column_defval)(void *column, char *defval);
__inst_set_api f_inst_set_mod_column_defval INST_SET_MOD_COLUMN_DEFVAL;
#define inst_set_mod_column_defval INST_SET_MOD_COLUMN_DEFVAL
/** 修改字段备注 */
typedef void (*f_inst_set_mod_column_remark)(void *column, char *remark);
__inst_set_api f_inst_set_mod_column_remark INST_SET_MOD_COLUMN_REMARK;
#define inst_set_mod_column_remark INST_SET_MOD_COLUMN_REMARK
/** 提交数据库修改内容 */
typedef void (*f_inst_set_mod_database_submit)(void *base);
__inst_set_api f_inst_set_mod_database_submit INST_SET_MOD_DATABASE_SUBMIT;
#define inst_set_mod_database_submit INST_SET_MOD_DATABASE_SUBMIT
/** 提交表修改内容 */
typedef void (*f_inst_set_mod_table_submit)(void *base, void *table);
__inst_set_api f_inst_set_mod_table_submit INST_SET_MOD_TABLE_SUBMIT;
#define inst_set_mod_table_submit INST_SET_MOD_TABLE_SUBMIT
/** 提交字段修改内容 */
typedef void (*f_inst_set_mod_column_submit)(void *base, void *table, void *column);
__inst_set_api f_inst_set_mod_column_submit INST_SET_MOD_COLUMN_SUBMIT;
#define inst_set_mod_column_submit INST_SET_MOD_COLUMN_SUBMIT
/** 创建缓冲区 */
typedef void (*f_inst_set_cvap_buf)(size_t bufsize);
__inst_set_api f_inst_set_cvap_buf INST_SET_CVAP_BUF;
#define inst_set_cvap_buf INST_SET_CVAP_BUF
/** 向缓冲区添加数据 */
typedef void (*f_inst_set_push_buf)(void *ptr, size_t size, void *buf);
__inst_set_api f_inst_set_push_buf INST_SET_PUSH_BUF;
#define inst_set_push_buf INST_SET_PUSH_BUF

/** 加载指令对应的函数指针 */
static void loadinst_set();

/**
 * 编译.inst_set文件
 *
 * @param dahanpath 文件路径
 */
extern void dahan_exec_comp(char *dahanpath);

#endif /* _INST_SET_H */
