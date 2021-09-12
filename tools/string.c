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

/*! ===> Creates on 2021/9/5. <=== */

/*!
 * @author 范特西
 */
#include <glibc.h>
#include <ctype.h>
#include <tools/vstring.h>

void rtrim(char *str)
{
        if (str == NULL || *str == '\0')
                return;

        int len = strlen(str);
        char *p = str + len - 1;
        while (p >= str && isspace(*p))
                *p = '\0'; --p;
}


//去除首部空格
void ltrim(char *str)
{
        if (str == NULL || *str == '\0')
                return;

        int len = 0;
        char *p = str;
        while (*p != '\0' && isspace(*p))
                ++p; ++len;

        memmove(str, p, strlen(str) - len + 1);
}

void trim(char *str)
{
        rtrim(str);
        ltrim(str);
}

int xsnprintf(char *dest, size_t max, const char *fmt, ...)
{
        int len;
        va_list ap;

        va_start(ap, fmt);
        len = vsnprintf(dest, max, fmt, ap);
        va_end(ap);

        if (len < 0)
                ERROR("【xsnprintf】错误调用。\n");
        if (len >= max)
                ERROR("【xsnprintf】缓冲区溢出。\n");

        return len;
}