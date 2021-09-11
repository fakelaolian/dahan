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

/*! ===> Creates on 2021/9/4. <=== */

/*!
 * @author 范特西
 */
#include "serialize/serialize.c"

void database_init(struct database *base, const char *pathname, const char *name)
{
        base->tabnum = 0;
        base->arrsize = TABLE_ARRAY_SIZE;
        base->tables = kmalloc(sizeof(struct table) * TABLE_ARRAY_SIZE);
        strncpy(base->name, name, _NAME_MAX);
        strncpy(base->pathname, pathname, _PATH_MAX);
}

extern bool create_database(struct database *base, char *name)
{
        char pathname[255];
        char *datadir = kconf_data_dir();
        xsnprintf(pathname, 255, "%s/%s", datadir, name);

#ifndef __vacat_close_check
        if (kcheck_database_name_dup(kconf_data_dir(), name)) {
                puts("数据库已存在");
                return false;
        }
#endif /* __vacat_debug */

        database_init(base, pathname, name);

        // 创建文件夹
        vacat_mkdirs(base->pathname);
        return true;
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
        _serialize_table_struct(tablepath, table);
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

void destroy_database(struct database *database)
{
        size_t i;
        for (i = 0; i < database->tabnum; i++)
                destroy_table((database->tables + i));
        kfree(database->tables);
}