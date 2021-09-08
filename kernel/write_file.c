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

/*! ===> Creates on 2021/9/7. <=== */

/*!
 * @author 范特西
 */
#include "kernel/database.h"
#include "mdef/_f_name.h"

static void _write_table_remark(FILE *fp, char *remark)
{
        size_t size = strlen(remark);
        fwrite(&size, sizeof(size_t), 1, fp);
        fwrite(remark, size, 1, fp);
}

inline static void _write_table_file(const char *pathname,
                                     struct table *table)
{
        char tablepath[255];
        xsnprintf(tablepath, 255, "%s/%s", pathname, __cfs_table_name);
        // 写入数据
        FILE *fp = fopen(tablepath, "wb");
        _write_table_remark(fp, table->remark);
        fclose(fp);
}