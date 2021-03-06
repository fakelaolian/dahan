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

/*! ===> Creates on 2021/9/4. <=== */

/*!
 * @author TianSheng
 */
#include "serialize/serialize.c"

static struct opened_database *opened = NULL;

void database_init(struct database *base, const char *pathname, const char *name)
{
        base->tabnum = 0;
        base->arrsize = TABLE_ARRAY_SIZE;
        base->tables = kmalloc(sizeof(struct table) * TABLE_ARRAY_SIZE);
        strncpy(base->name, name, DH_NAME_MAX);
        strncpy(base->pathname, pathname, DH_PATH_MAX);
}

extern bool create_database(struct database *base, char *name)
{
        char pathname[DH_PATH_MAX];
        char *datadir = kconf_data_dir();
        xsnprintf(pathname, DH_PATH_MAX, "%s/%s", datadir, name);

#ifndef __dahan_close_check
        if (kcheck_database_name_dup(kconf_data_dir(), name)) {
                puts("数据库已存在");
                return false;
        }
#endif /* __dahan_close_check */

        database_init(base, pathname, name);

        // 创建文件夹
        dahan_mkdirs(base->pathname);
        add_opened_database(base);
        return true;
}

void database_destroy(struct database *database)
{
        size_t i;
        for (i = 0; i < database->tabnum; i++)
                table_destroy((database->tables + i));
        kfree(database->tables);
}

void add_opened_database(struct database *database)
{
        if (opened == NULL) {
                opened = kmalloc(sizeof(struct opened_database));
                opened->p = database;
                opened->next = NULL;
        } else {
                struct opened_database *node;
                node = opened;

            opened_node_iter:
                if(node->next == NULL) {
                        struct opened_database *newnode
                                = kmalloc(sizeof(struct opened_database));
                        newnode->p = database;
                        newnode->next = NULL;

                        node->next = newnode;
                } else {
                        node = node->next;
                        goto opened_node_iter;
                }
        }
}

struct database *get_opened_database(const char *name)
{
        struct opened_database *iternode = opened;
    get_opened_iter:
        if(iternode != NULL) {
                if(strcmp(iternode->p->name, name) == 0) {
                        return iternode->p;
                } else {
                        iternode = iternode->next;
                        goto get_opened_iter;
                }
        }

        return NULL;
}