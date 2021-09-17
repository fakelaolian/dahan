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

/*! ===> Creates on 2021/9/8. <=== */

/*!
 * @author tiansheng
 */
#ifndef _SERIAL_H
#define _SERIAL_H

#include "mdef/_f_name.h"
#include "kernel/database.h"

__always_inline static void gettabdir(char *tabdir, const char *basedir, const char *name)
{
        /* 结果类似： /home/root/<数据库名>/<表名> */
        xsnprintf(tabdir, _PATH_MAX, "%s/%s", basedir, name);
}

/**
 * 根据表路径拼接字段所在文件夹
 */
__always_inline static void getcoldir0(char *coldir, const char *tablepath)
{
        xsnprintf(coldir, _PATH_MAX, "%s/%s", tablepath, _FCOLS_DIR_NAME);
}

__always_inline static void getcoldir1(char *coldir, const char *basedir, const char *tabname)
{
        char tabdir[_PATH_MAX];
        gettabdir(tabdir, basedir, tabname);
        getcoldir0(coldir, tabdir);
}

extern void dahan_add_table(struct database *base, struct table *table);
extern struct table *dahan_get_table(struct database *base, const char *name);
extern void dahan_ladd_table(struct database *base, struct table *table);

#endif /* _SERIAL_H */
