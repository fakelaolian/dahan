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

/*! ===> Creates on 2021/9/7. <=== */

/*!
 * 序列化表结构信息
 *
 * @author TianSheng
 */
#include "_serial.h"

__always_inline__
static void write_aat(const char *pathname, struct aat *aat)
{
        char aatpath[DH_PATH_MAX];
        xsnprintf(aatpath, DH_PATH_MAX, "%s/%s", pathname, _AAT_NAME);
        FILE *fp = fopen(aatpath, "wb");

        fwrite(&aat->arrsize, sizeof(size_t), 1, fp);
        fwrite(aat->spac_state, sizeof(uint), aat->arrsize, fp);
        fwrite(aat->areas, sizeof(struct aatarea), aat->arrsize, fp);

        fclose(fp);
}

__always_inline__
static void write_table(const char *pathname, struct table *table)
{
        char tablepath[DH_PATH_MAX];
        xsnprintf(tablepath, DH_PATH_MAX, "%s/%s", pathname, _TABLE_NAME);

        // 写入表数据
        FILE *fp = fopen(tablepath, "wb");
        fwrite(table->remark, DH_REMARK_MAX, 1, fp);
        fwrite(&table->size, sizeof(size_t), 1, fp);
        fwrite(&table->blocksize, sizeof(size_t), 1, fp);
        fclose(fp);

        // 写入区域分配表数据
        write_aat(pathname, table->aat);
}

/**
 * 写入单个字段的信息
 *
 * @param [i] coldir    字段所存放的文件夹
 * @param [i] col       字段数组
 */
__always_inline__
static void write_single_column(const char *coldir, struct column *col)
{
        char fcolpath[DH_PATH_MAX];
        xsnprintf(fcolpath, DH_PATH_MAX, "%s/%s", coldir, col->name);

        FILE *fp = fopen(fcolpath, "wb");
        fwrite(&col->id, sizeof(uint), 1, fp);
        fwrite(col->name, DH_NAME_MAX, 1, fp);
        fwrite(col->remark, DH_REMARK_MAX, 1, fp);
        fwrite(col->vdef, DH_VDEF_MAX, 1, fp);
        fwrite(&(col->type), sizeof(unsigned char), 1, fp);
        fwrite(&(col->len), sizeof(uint), 1, fp);
        fclose(fp);
}

/**
 * 序列化字段数组
 * ‘’
 * @param tablepath     表文件存放路径
 * @param cols          字段数组指针
 * @param size          数组大小
 */
__always_inline__
static void write_columns(const char *tablepath, struct linked *cols, size_t size)
{
        char coldir[DH_PATH_MAX];
        getcoldir0(coldir, tablepath);

        // 如果文件夹不存在就创建
        if (!file_exist(coldir))
                dahan_mkdirs(coldir);

        // 循环序列化所有字段
        linked_iter(cols, iter, write_single_column(coldir, COLVALUE(iter->value)))
}