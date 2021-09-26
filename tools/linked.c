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
#include <linked.h>

struct linked *linked_init()
{
        struct linked *linked = kmalloc(sizeof(struct linked));
        linked->value = NULL;
        linked->next = NULL;
        linked->parent = NULL;
}

void linked_add(struct linked *root, void *value) {
        struct linked *iter_node;
        struct linked *build_node;

        build_node = kmalloc(sizeof(struct linked));
        build_node->value = value;
        build_node->next = NULL;
        build_node->parent = root;

        if (root->next == NULL) {
                root->next = build_node;
                return;
        }

        iter_node = root->next;
        while (1) {
                if (iter_node->next == NULL) {
                        iter_node->next = build_node;
                        break;
                } else {
                        iter_node = iter_node->next;
                }
        }
}