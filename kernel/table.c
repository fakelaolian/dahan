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
#include "kernel/table.h"

void table_init(struct table *table, char *name)
{
        table->colnum = 0;
        table->arrsize = COLUMN_ARRAY_SIZE;
        strncpy(table->name, name, _NAME_MAX);
        table->columns = kmalloc(sizeof(struct column) * COLUMN_ARRAY_SIZE);

        memset(table->remark, 0, _REMARK_MAX);
}

void table_add_column(struct table *table, struct column *column)
{
        if (table->colnum == (table->arrsize - 1))
                _ARRAY_RESIZE(table, COLUMN_ARRAY_SIZE,
                              columns, sizeof(struct column));

        if(kcheck_column_name_dup(table->columns, table->colnum, column->name)) {
                puts("字段名重复");
                return;
        }

        table->columns[table->colnum] = (*column);
        ++table->colnum;
}

struct column *table_get_column(struct table *table, const char *name)
{
        struct column *col;

        size_t i;
        for(i = 0; i < table->colnum; i++) {
                col = (table->columns + i);
                if (strcmp(col->name, name) == 0)
                        return col;
        }

        return NULL;
}

void destroy_table(struct table *table)
{
        kfree(table->columns);
}