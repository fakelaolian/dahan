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
#ifndef VAP_INST_H
#define VAP_INST_H

struct directive {
        unsigned char code;        /* 指令码 */
        char name[8];              /* 助记符号 */
        char command[200];         /* 备注 */
        char param[30];            /* 参数，使用逗号分割 */
};

#define __such(code, name, cm) \
struct directive name = { code, #name,  cm};

#endif /* VAP_INST_H */