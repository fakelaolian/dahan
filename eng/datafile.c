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
#include "eng/datafile.h"

datafile_t *datafile_init(const char *dir, size_t blocksize, size_t colcount)
{
        datafile_t *dfp;
        char filepath[DH_PATH_MAX];

        xsnprintf(filepath, DH_PATH_MAX, "%s/%s", dir, _DATA_FILE);
        FILE *fp = fopen(filepath, "wb");
        fseek(fp, blocksize * colcount, SEEK_SET);
        fputc(' ', fp);
        fclose(fp);

        dfp = kmalloc(sizeof(datafile_t));
        dfp->filepath = filepath;

        return dfp;
}

void datafile_destroy(datafile_t *datafile)
{
        kfree(datafile);
}