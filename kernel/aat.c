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

/*! ===> Creates on 2021/9/25. <=== */

/*!
 * @author TianSheng
 */
#include "kernel/aat.h"

#define DEFAULT_ALLOC_AREA_SIZE 16

struct aat *aat_init()
{
        return aat_load_init(DEFAULT_ALLOC_AREA_SIZE);
}

struct aat *aat_load_init(size_t arrsize)
{
        struct aat *aat;
        struct aatarea *areas;

        aat = kmalloc(sizeof(struct aat));
        areas = kmalloc(sizeof(struct aatarea) * arrsize);
        aat->idle = kmalloc(sizeof(uint) * arrsize);

        memset(aat->idle, 0, sizeof(uint) * arrsize);

        aat->arrsize = arrsize;
        aat->areas = areas;

        return aat;
}

void aat_destroy(struct aat *aat)
{
        kfree(aat->idle);
        kfree(aat->areas);
        kfree(aat);
}

void aat_bound(struct aat *aat, uint colid)
{
        struct aatarea *aatarea;

        for (int i = 0; i < aat->arrsize; i++) {
                if(aat->idle[i] != 1) {
                        aat->idle[i] = 1;

                        aatarea = &aat->areas[i];
                        aatarea->areaid = i;
                        aatarea->colid = colid;

                        return;
                }
        }
}

size_t aat_get(struct aat *aat, uint colid)
{
        struct aatarea *aatarea;

        for (int i = 0; i < aat->arrsize; i++) {
                if (aat->idle[i] != 0) {
                        aatarea = &aat->areas[i];
                        if (aatarea->colid == colid) {
                                return aatarea->areaid;
                        }
                }
        }
}