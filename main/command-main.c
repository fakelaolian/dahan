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

/*! ===> Creates on 2021/9/4. <=== */

/*!
 * @author TianSheng
 */
#include "vasm/design.h"
#include "kernel/options.h"

//#define __bytebuf__0
#define __options__0

void test_options()
{
        kconf_init("/dahansql");

        vasm_load_impl_v0();

        vasm_dcvap_database(mydb);
        vasm_mkvap_database(&mydb, "mydb");

        vasm_dcvap_table(usertab);
        vasm_mkvap_table(&usertab, "t_user");

        vasm_dcvap_column(username);
        vasm_dcvap_column(password);

        vasm_mkvap_column(&username, "username", BLOCK_TYPE_VARCHAR, 255, NULL, NULL);
        vasm_mkvap_column(&password, "password", BLOCK_TYPE_VARCHAR, 256, "没有默认值", NULL);

        vasm_add_column(&usertab, &username);
        vasm_add_column(&usertab, &password);

        vasm_add_table(&mydb, &usertab);

        modify_column_info(&mydb, "t_user/username", "name_bak", 0, 0, NULL, NULL);

        vasm_dcvap_database(lmydb);
        vasm_lvap_database(&lmydb, "mydb");

        vasm_fvap_database(&mydb);
        vasm_fvap_database(&lmydb);
}

int main(void)
{
#ifdef WIN32
    system("chcp 65001");
#endif
#ifdef __options__0
        test_options();
#endif
        return 0;
}