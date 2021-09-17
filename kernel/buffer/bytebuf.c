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

/*! ===> Creates on 2021/9/14. <=== */

/*!
 * @author tiansheng
 */
#include <gmemp.h>
#include "kernel/bytebuf.h"

__always_inline static void bufresize(__bytebuf *buf, size_t resize)
{
        size_t n_size = resize + buf->count;
        buf->buf = krealloc(buf->buf, n_size);
        buf->count = n_size;
}

__bytebuf *bytebuf_open(size_t size)
{
        __bytebuf *buf = kmalloc(sizeof(__bytebuf));
        buf->count = size;
        buf->wpos = 0;
        buf->rpos = 0;
        buf->size = 0;
        buf->buf = kmalloc(size);
        memset(buf->buf, 0, size);

        return buf;
}

void bytebuf_write(void *ptr, size_t size, __bytebuf *buf)
{
        if((buf->wpos + size) >= buf->count)
                bufresize(buf, size + 128);

        memcpy((buf->buf + buf->wpos), ptr, size);
        buf->wpos += size;
        buf->size += size;
}