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

/*! ===> Creates on 2021/9/11. <=== */

/*!
 * @author 范特西
 */
#include <tools/vstring.h>
#include <tools/files.h>
#include "vap_cd/diret.h"

__always_inline void parse_vap(const char *line)
{
}

void begin_with_v(const char *line)
{
        switch(line[1]) {
                //
                // a -> p,
                //
                case 'a': {
                        if(line[2] == 'p')
                                parse_vap(line);
                }
        }
}

extern void vap_cd_parse(const char *cd_path)
{
        char line[1024] = {0};
        FILE *fp = fopen(cd_path, "r");
        while (!feof(fp)) {
                memset(line, 0, sizeof(line));
                fgets(line, sizeof(line) - 1, fp);
                switch(line[0]) {
                        case 'a': {break;}
                        case 'b': {break;}
                        case 'c': {break;}
                        case 'd': {break;}
                        case 'e': {break;}
                        case 'f': {break;}
                        case 'g': {break;}
                        case 'h': {break;}
                        case 'i': {break;}
                        case 'j': {break;}
                        case 'k': {break;}
                        case 'l': {break;}
                        case 'm': {break;}
                        case 'n': {break;}
                        case 'o': {break;}
                        case 'p': {break;}
                        case 'q': {break;}
                        case 'r': {break;}
                        case 's': {break;}
                        case 't': {break;}
                        case 'u': {break;}
                        case 'v': {
                                begin_with_v(line);
                                break;
                        }
                        case 'w': {break;}
                        case 'x': {break;}
                        case 'y': {break;}
                        case 'z': {break;}
                }
        }
        fclose(fp);
}