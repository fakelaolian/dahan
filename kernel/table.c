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
void table_linked_remove(struct table *table, const char *name)
{
        struct linked *node = table_linked_get(table->columns, name);
        if (node == NULL)
                return;

        /* 删除区域分配表 */
        struct column *col = COLVALUE(node->value);

        /* 删除节点 */
        LINKED_DELETE(node);
}

/* 销毁链表 */
void table_linked_destroy(struct linked *root)
{
        if(root->next == NULL)
                goto table_linked_destroy;

        struct linked *fnode;
        struct linked *node = root->next;

        if (node->next != NULL) {
                fnode = node;
                node = node->next;
                kfree(fnode);
        }

        kfree(node);

        table_linked_destroy:
        kfree(root);
}


void create_table(struct table *table, char *name)
{
        table->colnum = 0;
        strncpy(table->name, name, DH_NAME_MAX);
        table->size = 0;
        table->blocksize = 16000; /* 16kb */
        table->columns = linked_create();

        memset(table->remark, 0, DH_REMARK_MAX);
}

void table_add_column(struct table *table, struct column *column)
{
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
        table_linked_destroy(table->columns);
        // TODO datafile_destroy(table->datafile);
}