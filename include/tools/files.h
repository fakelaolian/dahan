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

/*! ===> Creates on 2021/9/5. <=== */

/*!
 * @author TianSheng
 */
#ifndef _FILES_H
#define _FILES_H

#include <dhlibc.h>
#include <sys/stat.h>
#include <dirent.h>
#include <xstring.h>
#include <_limits.h>

bool is_dot_or_dotdot(const char *name);
struct dirent *readdir_skip_dot_and_dotdot(DIR *dirp);

/** 获取文件路径的parent */
void fparent(const char *src, char *dest);
/** 判断文件是否存在 */
bool file_exist(const char *pathname);
/** 判断文件夹是否是空 */
bool is_empty_dir(const char *pathname);
/** 创建多级目录，不存在则创建 */
void dahan_mkdirs(const char *pathname);

#endif /* _FILES_H */
