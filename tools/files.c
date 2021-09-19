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
#include <files.h>

void fparent(const char *src, char *dest)
{
        u4 size = strlen(src) - 1;
        for (int i = 0; i < size; i++) {
                if (*((src + size) - i) == '/') {
                        memcpy(dest, src, i - 1);
                }
        }
}

bool is_dot_or_dotdot(const char *name)
{
        return name[0] == '.' &&
               (name[1] == '\0' || (name[1] == '.' && name[2] == '\0'));
}

struct dirent *readdir_skip_dot_and_dotdot(DIR *dirp)
{
        struct dirent *e;

        while ((e = readdir(dirp)) != NULL) {
                if (!is_dot_or_dotdot(e->d_name))
                        break;
        }

        return e;
}

bool file_exist(const char *pathname)
{
        struct stat sb;
        return lstat(pathname, &sb) == 0;
}

bool is_empty_dir(const char *pathname)
{
        DIR *dir = opendir(pathname);
        struct dirent *e;
        bool ret = true;

        if (!dir)
                return true;

        e = readdir_skip_dot_and_dotdot(dir);
        if (e)
                ret = false;

        closedir(dir);
        return ret;
}

void _dahan_if_not_exist_mkdir(const char *pathname)
{
        // 如果文件夹不存在则创建
        if (!file_exist(pathname))
                mkdir(pathname, S_IRWXU);
}

void dahan_mkdirs(const char *__cpy_pathname)
{
        char pathname[255];
        strncpy(pathname, __cpy_pathname, 255);

        char tmp;
        size_t len = strlen(pathname);
        for (size_t i = 0, end = len - 1; i < len; i++) {
                tmp = pathname[i];
                if (i == end) {
                        _dahan_if_not_exist_mkdir(pathname);
                        return;
                }

                if (tmp == '/' || tmp == '\\') {
                        pathname[i] = '\0';
                        _dahan_if_not_exist_mkdir(pathname);
                        pathname[i] = '/';
                }
        }
}