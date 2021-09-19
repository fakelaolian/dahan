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

/*! ===> Creates on 2021/9/19. <=== */

/*!
 * @author TianSheng
 */
#include <files.h>
#include "fs/fs-main.h"

void save_block_file(const char *fblockpath, u4 n)
{
        char parent[80];
        fparent(fblockpath, parent);
}

void fblock_init(const char *fblockpath, u4 n)
{
        char w = 0;
        u4 countsize = n * KB_4;
        FILE *fp = fopen(fblockpath, "wb+");
        fwrite(&w, sizeof(char), countsize, fp);
        fclose(fp);

        save_block_file(fblockpath, n);
}
