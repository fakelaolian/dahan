/*! ************************************************************************
 *
 * Copyright (C) 2020 netforklabs All rights reserved.
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
 * @author 范特西
 */
#ifndef _GIO_H
#define _GIO_H

#include <stdio.h>
#include <stdbool.h>
#include <dirent.h>

bool is_dot_or_dotdot(const char *name);
struct dirent *readdir_skip_dot_and_dotdot(DIR *dirp);

/** 判断文件是否存在 */
bool file_exist(const char *path);
/** 判断文件夹是否是空 */
bool is_empty_dir(const char *path);

#endif /* _GIO_H */
