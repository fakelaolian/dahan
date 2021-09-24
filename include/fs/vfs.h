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

/*! ===> Creates on 2021/9/23. <=== */

/*!
 * 虚拟文件地址映射，这个东西会先开辟一大块的内存。将文件内容映射到
 * 内存中。从而只需要操作内存即可快速遍历文件的内容。
 *
 * @author TianSheng
 */
#ifndef _VFS_H
#define _VFS_H

#include "sml-drive.h"

/* 虚拟文件 */
struct __viobuf {
        size_t direct;          /* 寻址信息 */
        uc flag;                /* 可读 | 可写 | 读写 */
        uc lock;                /* 锁标志位 */
        size_t offset;          /* 偏移量 */
        size_t bufsize;         /* 文件大小 */
};
#define VFILE struct __viobuf

/* 打开虚拟文件映射系统。
 * 打开的文件路径样例为：<库名/表名> -> mydb/tab */
VFILE *vfs_open(const char *path);
/* 关闭虚拟文件映射系统 */
void vfs_close(VFILE *vfs);
/* 移动读写指针 */
void vfs_seek(size_t pos, uc type, VFILE *vfs);
/* 读取虚拟文件系统中的文件数据 */

void *vfs_read(void *__restrict__ destbuf, size_t size, size_t count, VFILE *__restrict__ vf);
/* 写入数据到虚拟文件系统，虚拟文件系统会同步到磁盘上 */
void *vfs_write(void *__restrict__ srcbuf, size_t size, size_t count, VFILE *__restrict__ vf);

#endif /* _VFS_H */
