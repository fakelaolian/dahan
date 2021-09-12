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
#include "kernel/options.h"

void init_config();
void build_table(struct database *base);
void build_table(struct database *base);

int main(void)
{
        loadvasm();
        init_config();

        struct database base;
        if (!create_database(&base, "mydb"))
                return 1;

        build_table(&base);

        modify_table_name(&base, "user", "usermod");
        modify_column_info(&base, "usermod/username", "newusername",
                           0, 0, "修改了字段名", NULL);

        struct database lbsae;
        load_database(&lbsae, "mydb");

        vasm_fvap_database(&base);
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
        table_init(&table0, "user");
        table_init(&table1, "mytable");

        struct column username;
        struct column password;
        struct column admin;
        struct column user;
        struct column member;

        column_init(&username, "username", _VARCHAR, 255, "用户名", NULL);
        column_init(&password, "password", _VARCHAR, 255, NULL, NULL);
        column_init(&admin, "admin", _VARCHAR, 255, "管理员", NULL);
        column_init(&user, "user", _VARCHAR, 255, NULL, NULL);
        column_init(&member, "member", _VARCHAR, 255, NULL, NULL);

        table_add_column(&table0, &password);
        table_add_column(&table0, &username);
        table_add_column(&table0, &admin);
        table_add_column(&table0, &user);
        table_add_column(&table0, &member);

        table_add_column(&table1, &user);
        table_add_column(&table1, &member);

        vacat_add_table(base, &table0);
        vacat_add_table(base, &table1);
}