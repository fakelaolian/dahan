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
 * 虚拟硬盘系统
 *
 * @author TianSheng
 */
#ifndef _SML_DRIVE_H
#define _SML_DRIVE_H

#include <files.h>

ENUM HDRIVE_WRITE_FLAGS {
        HDRIVE_INSERT = 0,
        HDRIVE_APPEND,
        HDRIVE_REPLACE
};

struct sml_hard_drive {
        void *bbuf;     /* 虚拟磁盘存放内容的地方 */
        uint64 total;   /* 虚拟磁盘大小 */
        uint64 rem;     /* 已使用的空间大小 */
};
#define HDRIVE struct sml_hard_drive

/* 开启虚拟磁盘 */
HDRIVE *hdrive_open();
/* 关闭虚拟磁盘 */
void hdrive_close(HDRIVE *drive);
/* 从虚拟磁盘读取数据 */
void hdrive_read(void *__restrict__ destbuf, size_t offset, size_t count, HDRIVE *drive);
/* 写入到虚拟磁盘数据, flag设置写入方式。如果flag方式为APPEND,
 * 那么offset可以不需要设置。或者设置为-1即可。 */
void hdrive_write(void *__restrict__ srcbuf, size_t offset, size_t count, uc flag, HDRIVE *drive);

#endif /* _SML_DRIVE_H */
