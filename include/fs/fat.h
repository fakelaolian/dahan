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

/*! ===> Creates on 2021/9/18. <=== */

/*!
 * 文件分配表
 * @author TianSheng
 */
#ifndef _M_FAT_H
#define _M_FAT_H

struct fat0 {
        unsigned int beg;       /* 开始块号 */
        unsigned int end;       /* 结束块号 */
};

#define __fat struct fat0

#endif /* _M_FAT_H */
