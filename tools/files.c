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
#include "files.h"

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

        if(!dir)
                return true;

        e = readdir_skip_dot_and_dotdot(dir);
        if(e)
                ret = false;

        closedir(dir);
        return ret;
}

void mkdirs(const char *cpy_pathname)
{
        char pathname[255];
        strncpy(pathname, cpy_pathname, 255);

        size_t len = strlen(pathname);
        for (size_t i = 0; i < len; i++) {
                if(pathname[i] == '/' || pathname[i] == '\\') {
                        pathname[i] = '\0';
                        printf("%s", pathname);
                        pathname[i] = '/';
                }
        }
}