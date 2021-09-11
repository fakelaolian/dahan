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
#include "compaux.h"

/**
 * 解析v开头的指令, v开头指令有：
 *      - vap
 */
void vacat_parse_start_v(const char *vacatline)
{
        if (vacatline[1] == 'a' && vacatline[2] == 'p') {

        }
}

/**
 * 编译.vacat文件
 * @param vacatpath vacat文件路径
 */
extern void vacat_exec_comp(const char *vacatpath)
{
        char getlc[1024];
        FILE *fp = fopen(vacatpath, "r");

        while (!feof(fp)) {
                fgets(getlc, sizeof(getlc) - 1, fp);
                trim(getlc);
                // 根据首字母匹配下一步需要处理的内容
                switch (getlc[0]) {
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
                        case 'm': {break;}
                        case 'l': {break;}
                        case 'n': {break;}
                        case 'o': {break;}
                        case 'p': {break;}
                        case 'q': {break;}
                        case 'r': {break;}
                        case 's': {break;}
                        case 't': {break;}
                        case 'u': {break;}
                        case 'v': {
                                vacat_parse_start_v(getlc);
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