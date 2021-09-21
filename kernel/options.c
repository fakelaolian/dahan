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
#include "kernel/options.h"
#include "serialize/serialize.c"

#define CHK_TABLE_NOT_FOUND(__ptr, name)           \
if(__ptr == NULL) {                                \
        kerror("【%s】表不存在\n", name);             \
        return;                                    \
}

#define CHK_COLUMN_NOT_FOUND(__ptr, name)          \
if(__ptr == NULL) {                                \
        kerror("【%s】字段不存在\n", name);           \
        return;                                    \
}

__always_inline__ static void getname(const char *path, char *tabname, char *colname)
{
        char cpypath[DH_PATH_MAX];
        strncpy(cpypath, path, DH_PATH_MAX);

        char *word;
        word = strtok(cpypath, "/");

        unsigned char count = 0;
        while (word != NULL) {
                switch (count) {
                        case 0: {
                                if (tabname != NULL)
                                        strncpy(tabname, word, DH_NAME_MAX);
                                break;
                        }
                        case 1: {
                                if (colname != NULL)
                                        strncpy(colname, word, DH_NAME_MAX);
                                break;
                        }
                }
                word = strtok(NULL, "/");
                count++;
        }
}

/**
 * 修改字段名并重命名文件
 *
 * @param col       字段指针
 * @param name      新名称
 */
__always_inline__ static void _modify_column_name(struct column *col, const char *coldir,
                                                const char *name)
{
        char oldpath[DH_PATH_MAX];
        char newpath[DH_PATH_MAX];
        char oldname[DH_NAME_MAX];
        strncpy(oldname, col->name, DH_NAME_MAX);

        memset(col->name, 0, DH_NAME_MAX);
        strncpy(col->name, name, DH_NAME_MAX);

        xsnprintf(oldpath, DH_PATH_MAX, "%s/%s", coldir, oldname);
        xsnprintf(newpath, DH_PATH_MAX, "%s/%s", coldir, name);

        // 重命名
        rename(oldpath, newpath);
}

void modify_column_info(struct database *base, const char *name, const char *newname,
                        unsigned char type, u4 len, const char *remark,
                        const char *vdef)
{
        char tabname[DH_NAME_MAX];        /* 表名 */
        char colname[DH_NAME_MAX];        /* 字段名 */
        char coldir[DH_PATH_MAX];         /* 字段所在文件夹 */

        struct table *table;
        struct column *column;

        // 获取字段名以及表名
        getname(name, tabname, colname);

        // 获取表结构体
        table = dahan_get_table(base, tabname);
        CHK_TABLE_NOT_FOUND(table, tabname)

        // 获取字段结构体
        column = table_get_column(table, colname);
        CHK_COLUMN_NOT_FOUND(column, colname)

        getcoldir1(coldir, base->pathname, table->name);

        // 修改字段名
        if (name != NULL && strlen(name) != 0)
                _modify_column_name(column, coldir, newname);

        if (remark != NULL && strlen(remark) != 0) {
                memset(column->remark, 0, DH_REMARK_MAX);
                strncpy(column->remark, remark, DH_REMARK_MAX);
        }

        if (vdef != NULL && strlen(vdef) != 0) {
                memset(column->vdef, 0, DH_VDEF_MAX);
                strncpy(column->vdef, vdef, DH_VDEF_MAX);
        }

        // TODO 需要检测当前字段的数据中类型是否符合条件
        if (type > 0)
                column->type = type;

        // TODO 需要检测当前字段的数据中长度是否符合条件
        if (len > 0)
                column->len = len;

        // 写入文件
        write_single_column(coldir, column);
}

/** 序列化表结构，将表结构序列化成文件持久化存放到文件中。 */
void dahan_serialze_table(struct database *base, struct table *table)
{
        char tablepath[DH_PATH_MAX];
        gettabdir(tablepath, base->pathname, table->name);

        if (!file_exist(tablepath))
                dahan_mkdirs(tablepath);

        // 将表结构信息写入文件
        write_table(tablepath, table);
        write_columns(tablepath, table->columns, table->colnum);
}

void modify_table_name(struct database *base, const char *oldname, const char *newname)
{
        struct table *table;
        table = dahan_get_table(base, oldname);

        CHK_TABLE_NOT_FOUND(table, oldname)

        char oldpath[DH_PATH_MAX];
        char newpath[DH_PATH_MAX];

        xsnprintf(oldpath, DH_PATH_MAX, "%s/%s", base->pathname, table->name);
        xsnprintf(newpath, DH_PATH_MAX, "%s/%s", base->pathname, newname);

        memset(table->name, 0, DH_NAME_MAX);
        strncpy(table->name, newname, DH_NAME_MAX);

        rename(oldpath, newpath);
}

extern void load_dahan_add_table(struct database *bp, struct table *tp, bool is_load)
{
        if (bp->tabnum == (bp->arrsize - 1)) _ARRAY_RESIZE(bp, TABLE_ARRAY_SIZE, tables,
                                                           sizeof(struct table));

        // 检测字段名是否重复
        if (kcheck_table_name_dup(bp->tables, bp->tabnum, tp->name)) {
                puts("表名重复");
                return;
        }

        bp->tables[bp->tabnum] = (*tp);
        ++bp->tabnum;

        // 序列化
        if(!is_load)
                dahan_serialze_table(bp, tp);
}

void dahan_ladd_table(struct database *bp, struct table *tp)
{
        load_dahan_add_table(bp, tp, true);
}

void dahan_add_table(struct database *bp, struct table *tp)
{
        load_dahan_add_table(bp, tp, false);
}

struct table *dahan_get_table(struct database *base, const char *name)
{
        struct table *tab;

        size_t i;
        for (i = 0; i < base->tabnum; i++) {
                tab = (base->tables + i);
                if (strcmp(tab->name, name) == 0)
                        return tab;
        }

        return NULL;
}

void modify_database_name(struct database *base, const char *oldname, const char *newname)
{
        char newpathname[DH_PATH_MAX];
        char oldpathname[DH_PATH_MAX];
        xsnprintf(newpathname, DH_PATH_MAX, "%s/%s", kconf_data_dir(), newname);
        xsnprintf(oldpathname, DH_PATH_MAX, "%s/%s", kconf_data_dir(), oldname);

        rename(oldpathname, newpathname);
        strncpy(base->pathname, newpathname, DH_PATH_MAX);
}

void dahan_insert(struct database *base, const char *tabname)
{
        struct table *table;
        table = dahan_get_table(base, tabname);
        if (table == NULL)
                return;
}