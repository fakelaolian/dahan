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

/*! ===> Creates on 2021/9/5. <=== */

/*!
 * 全局配置
 * @author tiansheng
 */
#ifndef _CONFIG_H
#define _CONFIG_H

#include <gmemp.h>
#include <string.h>
#include <mdef/_f_limits.h>
#include <mdef/_f_name.h>

struct kconfig *privcnf;

struct kconfig {
        char datadir[_PATH_MAX];          /* 数据存放路径 */
};

/** 获取数据文件存放的路径 */
#define kconf_data_dir() privcnf->datadir

/** 初始化全局配置结构体 */
inline static void kconf_init(char *datadir)
{
        privcnf = kmalloc(sizeof(struct kconfig));
        strcpy(privcnf->datadir, datadir);
}

#define kconf_destroy() kfree(privcnf)

#endif /* _CONFIG_H */
