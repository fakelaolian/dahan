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

/*! ===> Creates on 2021/9/7. <=== */

/*!
 * 序列化表结构信息
 *
 * @author 范特西
 */
#include "_serial.h"

inline static void _write_table_remark(FILE *fp, char *remark)
{
        fwrite(remark, VAP_REMARK_MAX, 1, fp);
}

inline static void _write_table(const char *pathname, struct table *table)
{
        char tablepath[VAP_PATH_MAX];
        xsnprintf(tablepath, VAP_PATH_MAX, "%s/%s", pathname, VAP_TABLE_NAME);
        // 写入数据
        FILE *fp = fopen(tablepath, "wb");
        _write_table_remark(fp, table->remark);
        fclose(fp);
}

/**
 * 写入单个字段的信息
 *
 * @param [i] coldir    字段所存放的文件夹
 * @param [i] col       字段数组
 */
__always_inline static void _write_single_column(const char *coldir, struct column *col)
{
        char fcolpath[VAP_PATH_MAX];
        xsnprintf(fcolpath, VAP_PATH_MAX, "%s/%s", coldir, col->name);

        FILE *fp = fopen(fcolpath, "wb");
        fwrite(col->name, VAP_NAME_MAX, 1, fp);
        fwrite(col->remark, VAP_REMARK_MAX, 1, fp);
        fwrite(col->vdef, VAP_VDEF_MAX, 1, fp);
        fwrite(&(col->type), sizeof(unsigned char), 1, fp);
        fwrite(&(col->len), sizeof(unsigned int), 1, fp);
        fclose(fp);
}

/**
 * 序列化字段数组
 * ‘’
 * @param tablepath     表文件存放路径
 * @param cols          字段数组指针
 * @param size          数组大小
 */
inline static void _write_columns(const char *tablepath, struct column *cols, size_t size)
{
        char coldir[VAP_PATH_MAX];
        xsnprintf(coldir, VAP_PATH_MAX, "%s/%s", tablepath, VAP_FCOLS_DIR_NAME);

        // 如果文件夹不存在就创建
        if (!file_exist(coldir))
                vap_mkdirs(coldir);

        // 循环序列化所有字段
        for (size_t i = 0; i < size; i++)
                _write_single_column(coldir, &cols[i]);
}

/**
 * 序列化表结构
 */
#define _serialize_table_struct(pathname, table)                      \
_write_table(pathname, table);                                        \
_write_columns(pathname, table->columns, table->colnum);
