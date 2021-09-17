/*! ************************************************************************
 *
 * Copyright (C) 2020 luotiansheng All rights reserved.
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
 * @author tiansheng
 */
#include "kernel/column.h"

void create_column(struct column *column,
                   char *name,
                   unsigned char type,
                   size_t len,
                   char *remark,
                   char *vdef)
{
        column->type = type;
        column->len = len;
        strncpy(column->name, name, _NAME_MAX);

        if (remark != NULL && strlen(remark) != 0)
                strncpy(column->remark, remark, _REMARK_MAX);
        else
                memset(column->remark, 0, _REMARK_MAX);

        if (vdef != NULL && strlen(vdef) != 0)
                strncpy(column->vdef, vdef, _VDEF_MAX);
        else
                memset(column->vdef, 0, _VDEF_MAX);
}