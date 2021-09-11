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

enum vasm_ptr_t {
        /** 修改数据名 */
        vasm_mod_database_name,
        /** 修改数据表名 */
        vasm_mod_table_name,
        /** 修改数据表备注 */
        vasm_mod_table_remark,
        /** 修改字段名 */
        vasm_mod_column_name,
        /** 修改字段类型 */
        vasm_mod_column_type,
        /** 修改字段可空标志位 */
        vasm_mod_column_allow_null,
        /** 修改字段默认值 */
        vasm_mod_column_defval,
        /** 修改字段备注 */
        vasm_mod_column_remark,
};

/** 加载数据库 */
typedef void (*f_vasm_lvap_database)(void *base, const char *name);
__vasm_api f_vasm_lvap_database VASM_LVAP_DATABASE;
#define vasm_lvap_database VASM_LVAP_DATABASE
/** 加载数据表 */
typedef void (*f_vasm_lvap_table)(void *base, void *table, const char *name);
__vasm_api f_vasm_lvap_table VASM_LVAP_TABLE;
#define vasm_lvap_table VASM_LVAP_TABLE
/** 加载字段 */
typedef void (*f_vasm_lvap_column)(void *table, void *column, const char *name);
__vasm_api f_vasm_lvap_column VASM_LVAP_COLUMN;
#define vasm_lvap_column VASM_LVAP_COLUMN
/** 修改数据库名 */
typedef void (*f_vasm_mod_database_name)(void *base, const char *name);
__vasm_api f_vasm_mod_database_name VASM_MOD_DATABASE_NAME;
#define vasm_mod_database_name VASM_MOD_DATABASE_NAME
/** 修改表名 */
typedef void (*f_vasm_mod_table_name)(void *table, const char *name);
__vasm_api f_vasm_mod_table_name VASM_MOD_TABLE_NAME;
#define vasm_mod_table_name VASM_MOD_TABLE_NAME
/** 修改表备注 */
typedef void (*f_vasm_mod_table_remark)(void *table, const char *remark);
__vasm_api f_vasm_mod_table_remark VASM_MOD_TABLE_REMARK;
#define vasm_mod_table_remark VASM_MOD_TABLE_REMARK
/** 修改字段名 */
typedef void (*f_vasm_mod_column_name)(void *column, const char *name);
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
typedef void (*f_vasm_mod_column_defval)(void *column, const char *defval);
__vasm_api f_vasm_mod_column_defval VASM_MOD_COLUMN_DEFVAL;
#define vasm_mod_column_defval VASM_MOD_COLUMN_DEFVAL
/** 修改字段备注 */
typedef void (*f_vasm_mod_column_remark)(void *column, const char *remark);
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

/**
 * 编译.vasm文件
 *
 * @param vacatpath 文件路径
 */
extern void vacat_exec_comp(const char *vacatpath);

#endif /* _VASM_H */