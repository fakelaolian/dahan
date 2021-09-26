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

/*! ===> Creates on 2021/9/26. <=== */

/*!
 * @author TianSheng
 */
#ifndef _LINKED_H
#define _LINKED_H

#include <stddef.h>
#include <dhmem.h>

/* 字段链表 */
struct linked {
        void *value;
        struct linked *next;
        struct linked *parent;
};

/* 释放单个节点 */
#define LINKED_DELETE(__node)                   \
__node->parent->next = __node->next;            \
__node->next->parent = __node->parent;          \
kfree(__node);

#define linked_iter(__root, __name, __func_block)       \
struct linked *__name = __root;                         \
while ((__name = __name->next) != NULL) {               \
        __func_block;                                   \
}

/* 初始化一个链表 */
struct linked *linked_init();
/* 往node下新增一个节点（注意：这个节点可以是任何节点。
 * 不是非必须根节点。*/
void linked_add(struct linked *root, void *value);

#endif /* _LINKED_H */
