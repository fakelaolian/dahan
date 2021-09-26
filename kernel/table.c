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
#include "kernel/table.h"

/* 获取一个节点 */
struct linked *table_linked_get(struct linked *root, const char *name)
{
        linked_iter(root, iter, {
                if (strcmp(COLVALUE(iter->value)->name, name) == 0)
                        return iter;
        })

        return NULL;
}

/* 删除一个节点，相当于从表中删除了一个字段 */
void table_linked_remove(struct linked *root, const char *name)
{
        struct linked *node = table_linked_get(root, name);
        if (node != NULL) {
                LINKED_DELETE(node)
        }
}

/* // TODO 销毁链表 */
void table_linked_destroy(struct linked *root)
{
}


void create_table(struct table *table, char *name)
{
        table->colnum = 0;
        strncpy(table->name, name, DH_NAME_MAX);
        table->size = 0;
        table->blocksize = 16000; /* 16kb */
        table->aat = aat_init();
        table->columns = linked_init();

        memset(table->remark, 0, DH_REMARK_MAX);
}

void table_add_column(struct table *table, struct column *column)
{
        column->id = table->colnum;
        aat_bound(table->aat, column->id);
        linked_add(table->columns, column);
        ++table->colnum;
}

struct column *get_column(struct table *table, const char *name)
{
        struct linked *node = table_linked_get(table->columns, name);
        if (node != NULL) {
                return COLVALUE(node->value);
        }

        return NULL;
}

void table_destroy(struct table *table)
{
        aat_destroy(table->aat);
        table_linked_destroy(table->columns);
        // TODO datafile_destroy(table->datafile);
}

void table_remove_column(struct table *table, const char *name)
{
        table_linked_remove(table->columns, name);
}