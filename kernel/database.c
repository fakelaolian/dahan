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
#include <files.h>
#include "write_file.c"

#define TABLE_ARRAY_RESIZE(base)                                    \
{                                                                   \
        base->arrsize += TABLE_ARRAY_SIZE;                          \
        base->tables = krealloc(base->tables,                       \
                (sizeof(struct table) * base->arrsize));            \
}

bool _cfs_load(struct database *base, char *name)
{
        ERROR("加载失败");
        return false;
}

bool load_or_create_database(struct database *base, char *name)
{
        char pathname[255];
        char *datadir = kconf_data_dir();

        xsnprintf(pathname, 255, "%s/%s", datadir, name);
        // if (file_exist(pathname))
        //         return _cfs_load(base, name);

        base->name = name;
        base->tabnum = 0;
        base->arrsize = TABLE_ARRAY_SIZE;
        base->tables = kmalloc(sizeof(struct table) * TABLE_ARRAY_SIZE);
        strncpy(base->pathname, pathname, 255);

        // 创建文件夹
        cfs_mkdirs(base->pathname);
        return true;
}

/** 序列化表结构，将表结构序列化成文件持久化存放到文件中。 */
void _cfs_serialze_table(struct database *base, struct table *table)
{
        char tablepath[255];
        /* 结果类似： /home/root/<数据库名>/<表名> */
        xsnprintf(tablepath, 255, "%s/%s", base->pathname, table->name);

        if(!file_exist(tablepath))
                cfs_mkdirs(tablepath);

        // 将表结构信息写入文件
        _write_table_file(tablepath, table);
}

void cfs_add_table(struct database *base, struct table *table)
{
        if (base->tabnum == (base->arrsize - 1))
                TABLE_ARRAY_RESIZE(base)

        base->tables[base->tabnum] = (*table);
        ++base->tabnum;

        // 序列化表
        _cfs_serialze_table(base, table);
}

struct table *cfs_get_table(struct database *base, const char *name)
{
        struct table *tab;

        size_t i;
        for(i = 0; i < base->tabnum; i++) {
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