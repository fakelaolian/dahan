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

/*! ===> Creates on 2021/9/12. <=== */

/*!
 * @author 范特西
 */
#include "kernel/options.h"
#include "serialize/serialize.c"

/** 修改表名 */
void modify_table_name(struct database *base, const char *oldname, const char *newname)
{
        struct table *table;
        table = vacat_get_table(base, oldname);

        if(table == NULL) {
                kerror("【%s】表不存在\n", oldname);
                return;
        }

        char oldpath[_PATH_MAX];
        char newpath[_PATH_MAX];

        xsnprintf(oldpath, _PATH_MAX, "%s/%s", base->pathname, table->name);
        xsnprintf(newpath, _PATH_MAX, "%s/%s", base->pathname, newname);

        memset(table->name, 0, _NAME_MAX);
        strncpy(table->name, newname, _NAME_MAX);

#ifdef __vacat_debug
        DEBUG("############## 调试开始【修改表名】 ##############\n");
        DEBUG("原路径: %s\n", oldpath);
        DEBUG("新路径: %s\n", newpath);
        DEBUG("############## 调试结束【修改表名】 ##############\n");
#endif

        rename(oldpath, newpath);
}

/** 序列化表结构，将表结构序列化成文件持久化存放到文件中。 */
void _vacat_serialze_table(struct database *base, struct table *table)
{
        char tablepath[_PATH_MAX];
        /* 结果类似： /home/root/<数据库名>/<表名> */
        xsnprintf(tablepath, _PATH_MAX, "%s/%s", base->pathname, table->name);

        if (!file_exist(tablepath))
                vacat_mkdirs(tablepath);

        // 将表结构信息写入文件
        _write_table(tablepath, table);
        _write_columns(tablepath, table->columns, table->colnum);
}

void vacat_add_table(struct database *bp, struct table *tp)
{
        if (bp->tabnum == (bp->arrsize - 1))
        _ARRAY_RESIZE(bp, TABLE_ARRAY_SIZE, tables,
                      sizeof(struct table));

        // 检测字段名是否重复
        if (kcheck_table_name_dup(bp->tables, bp->tabnum, tp->name)) {
                puts("表名重复");
                return;
        }

        bp->tables[bp->tabnum] = (*tp);
        ++bp->tabnum;

        // 序列化
        _vacat_serialze_table(bp, tp);
}

struct table *vacat_get_table(struct database *base, const char *name)
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
        char newpathname[_PATH_MAX];
        char oldpathname[_PATH_MAX];
        xsnprintf(newpathname, _PATH_MAX, "%s/%s", kconf_data_dir(), newname);
        xsnprintf(oldpathname, _PATH_MAX, "%s/%s", kconf_data_dir(), oldname);

        rename(oldpathname, newpathname);
        strncpy(base->pathname, newpathname, _PATH_MAX);
}