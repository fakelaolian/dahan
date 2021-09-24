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
 * @author TianSheng
 */
#include "fs/sml-drive.h"

#ifdef WIN32

#       include <windows.h>

#endif

#define __DRIVE_ALLOC_SIZE (uint64) 512 << 30

/* 获取已使用的内存大小，单位：byte */
uint64 getrem()
{
        MEMORYSTATUSEX state;
        state.dwLength = sizeof(state);
        GlobalMemoryStatusEx(&state);
        return state.ullAvailPhys;
}

HDRIVE *hdrive_open()
{
        HDRIVE *drive = kmalloc(sizeof(HDRIVE));
        /* 给虚拟磁盘分配512MB的空间 */
        drive->bbuf = kmalloc(__DRIVE_ALLOC_SIZE);
        drive->total = __DRIVE_ALLOC_SIZE;
        drive->rem = 0;

        return drive;
}

void hdrive_close(HDRIVE *drive)
{
        kfree(drive->bbuf);
        kfree(drive);
}

/* 从虚拟磁盘读取数据 */
void hdrive_read(void *__restrict__ destbuf, size_t offset, size_t count, HDRIVE *drive)
{

}

/* 写入到虚拟磁盘数据 */
void hdrive_write(void *__restrict__ srcbuf, size_t offset, size_t count, uc flag, HDRIVE *drive)
{

}