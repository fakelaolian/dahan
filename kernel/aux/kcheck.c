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

/*! ===> Creates on 2021/9/8. <=== */

/*!
 * @author 范特西
 */
#include "kernel/database.h"
#include "kernel/aux/kcheck.h"

bool kcheck_column_name_dup(const void *sp, size_t size, const char *name)
{
        struct column *columns = (struct column *) sp;
        for (size_t i = 0; i < size; i++) {
                if (strcmp(columns[i].name, name) == 0)
                        return true;
        }
        return false;
}

bool kcheck_table_name_dup(const void *sp, size_t size, const char *name)
{
        struct table *tables = (struct table *) sp;
        for (size_t i = 0; i < size; i++) {
                if (strcmp(tables[i].name, name) == 0)
                        return true;
        }
        return false;
}

bool kcheck_database_name_dup(const char *pathname, const char *name)
{
        DIR *dirp = opendir(pathname);
        struct dirent *e;

        bool ret = false;
        while((e = readdir_skip_dot_and_dotdot(dirp)) != NULL) {
                if (strcmp(e->d_name, name) == 0) {
                        ret = true;
                        goto kcheck_database_name_dup_out;
                }
        }

kcheck_database_name_dup_out:
        closedir(dirp);
        return ret;
}