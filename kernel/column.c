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
#include "kernel/column.h"

void column_init(struct column *column, char *name, unsigned int type,
                 unsigned len)
{
        column->type = type;
        column->len = len;
        memset(column->vdef, 0, _VDEF_MAX);
        memset(column->remark, 0, _REMARK_MAX);
        strncpy(column->name, name, _NAME_MAX);
}