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
        aat->spac_state = kmalloc(sizeof(uint) * arrsize);

        memset(aat->spac_state, 0, sizeof(uint) * arrsize);

        aat->arrsize = arrsize;
        aat->areas = areas;

        return aat;
}

void aat_destroy(struct aat *aat)
{
        kfree(aat->spac_state);
        kfree(aat->areas);
        kfree(aat);
}

void aat_bound(struct aat *aat, uint colid)
{
        struct aatarea *aatarea;

        for (int i = 0; i < aat->arrsize; i++) {
                if(aat->spac_state[i] != 1) {
                        aat->spac_state[i] = 1;

                        aatarea = &aat->areas[i];
                        aatarea->areaid = i;
                        aatarea->colid = colid;

                        return;
                }
        }

        // 如果能走到这，代表文件分配表已经满了。所以需要扩容
        aat->arrsize += 16;

        aat->areas = kmalloc(sizeof(struct aatarea) * aat->arrsize);
        uint *spac_statetmp = kmalloc(sizeof(uint) * aat->arrsize);
        memset(spac_statetmp, 0, sizeof(uint) * aat->arrsize);

        memmove(spac_statetmp, aat->spac_state, sizeof(uint) * aat->arrsize);
        kfree(aat->spac_state);
        aat->spac_state = spac_statetmp;
}

size_t aat_get(struct aat *aat, uint colid)
{
        size_t ret = 0;
        struct aatarea *aatarea;

        for (int i = 0; i < aat->arrsize; i++) {
                if (aat->spac_state[i] != 0) {
                        aatarea = &aat->areas[i];
                        if (aatarea->colid == colid) {
                                ret = aatarea->areaid;
                                goto aat_get_out;
                        }
                }
        }

aat_get_out:
        return ret;
}

void aat_remove(struct aat *aat, uint colid)
{
        size_t i = aat_get(aat, colid);
        aat->spac_state[i] = 0;
}