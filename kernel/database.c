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

#define TABLE_ARRAY_SIZE 1

#define TABLE_ARRAY_RESIZE(database)                            \
{                                                               \
        database->arrsize += TABLE_ARRAY_SIZE;                  \
        database->tables = krealloc(database->tables,           \
                (sizeof(struct table) * database->arrsize));    \
}

void database_init(struct database *database, char *name)
{
        database->name = name;
        database->tabnum = 0;
        database->arrsize = TABLE_ARRAY_SIZE;

        database->tables = kmalloc(sizeof(struct table) * TABLE_ARRAY_SIZE);
}

void database_add_table(struct database *database, struct table *table)
{
        if(database->tabnum == (database->arrsize - 1))
                TABLE_ARRAY_RESIZE(database)

        database->tables[database->tabnum] = (*table);
        ++database->tabnum;
}

struct table *database_get_table(struct database *database, const char *name)
{
        struct table *tab;

        size_t i;
        for(i = 0; i < database->tabnum; i++) {
                tab = (database->tables + i);
                if(strcmp(tab->name, name) == 0)
                        return tab;
        }

        return NULL;
}