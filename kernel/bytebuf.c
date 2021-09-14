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

/*! ===> Creates on 2021/9/14. <=== */

/*!
 * 用于二进制解析的函数库
 *
 * @author 范特西
 */
#include <gmemp.h>
#include "kernel/bytebuf.h"

__always_inline static void reopen_bytebuf(bytebuf *buf, size_t resize)
{
        size_t n_size = resize + buf->size;
        buf = krealloc(buf, n_size);
        buf->size = n_size;
}

void bytebuf_open(bytebuf *buf)
{
        buf->size = 64;
        buf->pos = 0;
        buf->buf = kmalloc(buf->size);
        memset(buf->buf, 0, buf->size);
}

void bytebuf_read(void *ptr, size_t size, bytebuf *buf)
{
        memcpy(ptr, (buf->buf + buf->pos), size);
}

void bytebuf_write(void *ptr, size_t size, bytebuf *buf)
{
        if((buf->pos + size) >= buf->size)
                reopen_bytebuf(buf, 64 + size);

        memcpy(buf->buf, ptr, size);
        buf->pos += size;
}