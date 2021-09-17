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
 * 方便保存二进制数据库的一个缓冲区，该缓冲区只支持追加数据和读取数据。
 * 不支持插入、 删除等操作。
 *
 * @author tiansheng
 */
#ifndef DAHAN_BYTEBUF_H
#define DAHAN_BYTEBUF_H

#include <string.h>

typedef char buffer_t;

struct bytebuf {
        size_t count;       /* 缓冲区总大小 */
        size_t size;        /* 已使用大小 */
        size_t wpos;        /* 写指针 */
        size_t rpos;        /* 读指针 */
        buffer_t *buf;      /* 缓冲区 */
};

#define __bytebuf struct bytebuf

/** 从第0个位置设置缓冲区偏移量 */
#define bytebuf_seek_beg(__buf, __pos) __buf->rpos = __pos
/** 从第当前位置设置缓冲区偏移量 */
#define bytebuf_seek_cur(__buf, __pos) __buf->rpos += __pos
/** 从第最后的位置设置缓冲区偏移量 */
#define bytebuf_seek_end(__buf) __buf->rpos = __buf->size - __buf->size

/** 获取缓冲区指针位置 */
#define bytebuf_tell(__buf) __buf->rpos

/**
 * 创建bytebuf（叫open完全就是为了尊重buffer这个名字）
 * size参数为创建缓冲区的
 */
__bytebuf *bytebuf_open(size_t size);
/** 往缓冲区写入数据 */
void bytebuf_write(void *ptr, size_t size, __bytebuf *buf);
/** 从缓冲区读取数据 */
#define bytebuf_read(ptr, size, buf) \
memcpy(ptr, (buf->buf + buf->rpos), size); \
buf->rpos += size;
/** 关闭缓冲区 */
#define bytebuf_close(__buf) \
kfree(__buf->buf);\
kfree(__buf);

#endif /* DAHAN_BYTEBUF_H */