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
 * @author 范特西
 */
#ifndef VACAT_BYTEBUF_H
#define VACAT_BYTEBUF_H

#include <string.h>

typedef char *buffer_t;

struct bytebuf {
        size_t size;      /* 缓冲区总大小 */
        size_t pos;       /* 当前缓冲区位置 */
        buffer_t buf;     /* 缓冲区 */
};

#define bytebuf struct bytebuf

#define bytebuf_seek_beg(__buf, __pos) (__buf)->pos = __pos
#define bytebuf_seek_cur(__buf, __pos) (__buf)->pos += __pos
#define bytebuf_seek_end(__buf) (__buf)->pos = (__buf)->size

#define bytebuf_tell(__buf) __buf->pos

void bytebuf_open(bytebuf *buf);
void bytebuf_write(void *ptr, size_t size, bytebuf *buf);

inline void bytebuf_read(void *ptr, size_t size, bytebuf *buf);
#define bytebuf_close(__buf) kfree((__buf)->buf)

#endif /* VACAT_BYTEBUF_H */