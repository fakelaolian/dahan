/*! ************************************************************************
 *
 * Copyright (C) 2020 netforklabs All rights reserved.
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
#include "kernel/database.h"

#define TABLE_ARRAY_RESIZE(base)                                    \
{                                                                   \
        base->arrsize += TABLE_ARRAY_SIZE;                          \
        base->tables = krealloc(base->tables,                       \
                (sizeof(struct table) * base->arrsize));            \
}

bool load(struct database *base, char *name)
{
        return false;
}

bool load_or_create_database(struct database *base, char *name)
{
        char pathname[255];
        char *datadir = kconf_data_dir();

        xsnprintf(pathname, 255, "%s/%s", datadir, name);
        if(file_exist(pathname))
                return load(base, name);

        base->name = name;
        base->tabnum = 0;
        base->arrsize = TABLE_ARRAY_SIZE;
        base->tables = kmalloc(sizeof(struct table) * TABLE_ARRAY_SIZE);
        strncpy(base->pathname, pathname, 255);

        // 创建文件夹
        mkdirs(base->pathname);
        return true;
}

void cfs_add_table(struct database *base, struct table *table)
{
        if(base->tabnum == (base->arrsize - 1))
                TABLE_ARRAY_RESIZE(base)

        base->tables[base->tabnum] = (*table);
        ++base->tabnum;
}

struct table *cfs_get_table(struct database *base, const char *name)
{
        struct table *tab;

        size_t i;
        for(i = 0; i < base->tabnum; i++) {
                tab = (base->tables + i);
                if(strcmp(tab->name, name) == 0)
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