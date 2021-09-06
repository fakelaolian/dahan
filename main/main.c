/*! ************************************************************************
 *
 * Copyright (C) 2020 netforklabs All rights reserved.
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
#include <stdbool.h>
#include <stdalign.h>
#include "kernel/database.h"
#include "gtools.h"
#include "files.h"
void init_config();

void build_table(struct database *base);

int main(void)
{
        init_config();

        struct database base;
        if (!load_or_create_database(&base, "mydb"))
                return 1;

        build_table(&base);

        destroy_database(&base);
        kconf_destroy();

        return 0;
}

void init_config()
{
        kconf_init("/home/shitbro/cfssql");
}

void build_table(struct database *base)
{
        struct table table;

        struct column username;
        struct column password;
        struct column admin;
        struct column user;
        struct column member;

        table_init(&table, "user");

        column_init(&username, "username", _VARCHAR, 255);
        column_init(&password, "password", _VARCHAR, 255);
        column_init(&admin, "admin", _VARCHAR, 255);
        column_init(&user, "user", _VARCHAR, 255);
        column_init(&member, "member", _VARCHAR, 255);

        table_add_column(&table, &password);
        table_add_column(&table, &username);
        table_add_column(&table, &admin);
        table_add_column(&table, &user);
        table_add_column(&table, &member);

        cfs_add_table(base, &table);
}