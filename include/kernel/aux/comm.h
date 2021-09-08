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

/*! ===> Creates on 2021/9/8. <=== */

/*!
 * 通用宏或函数
 * @author 范特西
 */
#ifndef CFS_COMM_H
#define CFS_COMM_H

/**
 * 重新定义数组大小
 */
#define _ARRAY_RESIZE(__sp, __a_size, __arrname, __s_size)              \
{                                                                       \
        __sp->arrsize += __a_size;                                      \
        __sp->__arrname = krealloc(__sp->__arrname,                     \
                        (__s_size * __sp->arrsize));                    \
}

#endif /* CFS_COMM_H */
