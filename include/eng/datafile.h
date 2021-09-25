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

/*! ===> Creates on 2021/9/25. <=== */

/*!
 * 数据文件设计
 * @author TianSheng
 */
#ifndef _DATAFILE_H
#define _DATAFILE_H

#include "block.h"
#include <files.h>

/* 数据文件描述结构体 */
struct datafile {
        char *filepath;
};
#define datafile_t struct datafile

/* 初始化数据文件 */
datafile_t *datafile_init(const char *dir, size_t blocksize, size_t colcount);
/* 销毁数据文件指针 */
inline void datafile_destroy(datafile_t *datafile);

#endif /* _DATAFILE_H */