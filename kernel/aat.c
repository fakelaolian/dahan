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

struct aat *aat_init()
{
        struct aat *aat;
        struct aatcol *areas;
        uint *idlearea;

        aat = kmalloc(sizeof(struct aat));
        areas = kmalloc(sizeof(struct aatcol) * 16);
        idlearea = kmalloc(sizeof(uint) * 16);

        for (int i = 0; i < 16; i++)
                idlearea[i] = i;

        aat->arrsize = 16;
        aat->areas = areas;

        return aat;
}

void aat_destroy(struct aat *aat)
{
        kfree(aat->idle);
        kfree(aat->areas);
        kfree(aat);
}

void aat_bound(struct aat *aat, const char *colname)
{
        struct aatcol *aatcol;

        for (int i = 0; i < aat->arrsize; i++) {
                if(aat->idle[i] != 0) {
                        aat->idle[i] = 1;

                        aatcol = &aat->areas[i];
                        aatcol->areaid = i;
                        aatcol->colname = colname;

                        return;
                }
        }
}

size_t aat_get(struct aat *aat, const char *colname)
{
        struct aatcol *aatcol;

        for (int i = 0; i < aat->arrsize; i++) {
                if (aat->idle[i] != 0) {
                        aatcol = &aat->areas[i];
                        if (strcmp(aatcol->colname, colname) == 0) {
                                return aatcol->areaid;
                        }
                }
        }
}