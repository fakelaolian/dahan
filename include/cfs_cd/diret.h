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

/*! ===> Creates on 2021/9/9. <=== */

/*!
 * 指令集
 * @author 范特西
 */
#ifndef CFS_INST_H
#define CFS_INST_H

struct directive {
        unsigned char code;        /* 指令码 */
        char name[8];              /* 助记符号 */
        char command[200];         /* 备注 */
        char param[30];            /* 参数，使用逗号分割 */
};

#define __such(code, name, cm) \
struct directive name = { code, #name,  cm};

__such(0x0, nop, "不做任何操作")
__such(0x1, make_d, "创建一个数据库。 参数： 数据库名")
__such(0x2, make_t, "创建一张表。 参数： 数据库名， 表名")
__such(0x3, make_c, "创建一张表。 参数： 数据库名， 表名")

#endif /* CFS_INST_H */