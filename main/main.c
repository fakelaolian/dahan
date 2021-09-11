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

/*! ===> Creates on 2021/9/4. <=== */

/*!
 * @author 范特西
 */
#include <vasm/vasm.h>
#include "kernel/database.h"

void init_config();
void build_table(struct database *base);

int main(void)
{
        loadvasm();
        init_config();

        struct database base;
        if (!vasm_cvap_database(&base, "mydb"))
                return 1;

        build_table(&base);

        struct database lbase;
        vasm_lvap_database(&lbase, "mydb");

        vasm_fvap_database(&base);
        vasm_fvap_database(&lbase);
        kconf_destroy();
        return 0;
}

void init_config()
{
        kconf_init("/home/shitbro/vacatsql");
}

void build_table(struct database *base)
{
        struct table table0;
        struct table table1;
        vasm_cvap_table(&table0, "user");
        vasm_cvap_table(&table1, "mytable");

        struct column username;
        struct column password;
        struct column admin;
        struct column user;
        struct column member;

        vasm_cvap_column(&username, "username", _VARCHAR, 255, "用户名", NULL);
        vasm_cvap_column(&password, "password", _VARCHAR, 255, NULL, NULL);
        vasm_cvap_column(&admin, "admin", _VARCHAR, 255, "管理员", NULL);
        vasm_cvap_column(&user, "user", _VARCHAR, 255, NULL, NULL);
        vasm_cvap_column(&member, "member", _VARCHAR, 255, NULL, NULL);


        vasm_add_column(&table0, &password);
        vasm_add_column(&table0, &username);
        vasm_add_column(&table0, &admin);
        vasm_add_column(&table0, &user);
        vasm_add_column(&table0, &member);

        vasm_add_column(&table1, &user);
        vasm_add_column(&table1, &member);

        vasm_add_table(base, &table0);
        vasm_add_table(base, &table1);
}