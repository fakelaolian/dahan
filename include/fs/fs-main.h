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

/*! ===> Creates on 2021/9/19. <=== */

/*!
 * @author TianSheng
 */
#ifndef _FS_MAIN_H
#define _FS_MAIN_H

#include <types.h>

#define KB_4 4096

/** 数据区块，每个数据区块占用4kb的内存大小。
 * 如果当一条数据溢出当前文件块，那么当前文件块的内容会被抛弃。
 * 数据将会被存放到下一个区块内。
 *
 * 这个数据块是会常驻内存的。直到数据库服务关闭后销毁。每次更新会同步到文件中。 */
typedef struct fblock {
        u4 seqnum;          /* 区块序号 */
        u4 unused;          /* 未使用数据大小 */
        u4 endpos;          /* 区块结束位置 */
} fblock, fblock_t;

/* 初始化文件区块，第一个参数表示文件块表存放位置。第二个参数
 * 表示默认初始化多少个区块。*/
void fblock_init(const char *fblockpath, u4 n);

#endif /* _FS_MAIN_H */
