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
#include "kernel/database.h"

#define TABLE_ARRAY_RESIZE(base)                                    \
{                                                                   \
        base->arrsize += TABLE_ARRAY_SIZE;                          \
        base->tables = krealloc(base->tables,                       \
                (sizeof(struct table) * base->arrsize));            \
}

void create_database(struct database *base, char *name)
{
        char *datadir;

        priv_database_init(base, name);
        datadir = kconf_data_dir();

        xsprintf(base->path, PATH_MAX, "%s/%s", datadir, name);
}

void database_add_table(struct database *base, struct table *table)
{
        if(base->tabnum == (base->arrsize - 1))
                TABLE_ARRAY_RESIZE(base)

        base->tables[base->tabnum] = (*table);
        ++base->tabnum;
}

struct table *base_get_table(struct database *base, const char *name)
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