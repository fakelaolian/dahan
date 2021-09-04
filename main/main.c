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

int main(void)
{
        struct database base;
        struct table table;

        struct column username;
        struct column password;
        struct column admin;
        struct column user;
        struct column member;

        struct column *getcol;

        table_init(&table, "user");

        column_init(&username, "username", _VARCHAR, 255);
        column_init(&password, "password", _VARCHAR, 255);
        column_init(&admin, "admin", _VARCHAR, 255);
        column_init(&user, "user", _VARCHAR, 255);
        column_init(&member, "member", _VARCHAR, 255);

        table_add_column(&table, &username);
        table_add_column(&table, &password);
        table_add_column(&table, &admin);
        table_add_column(&table, &user);
        table_add_column(&table, &member);

        getcol = table_get_column(&table, "username");

        printf("getcol: %s\n", getcol->name);

        printf("%s\n", table.columns[0].name);
        printf("%s\n", table.columns[1].name);
        printf("%s\n", table.columns[2].name);
        printf("%s\n", table.columns[3].name);
        printf("%s\n", table.columns[4].name);

        database_init(&base, "mydb");
        database_add_table(&base, &table);

        struct table *user_table;
        user_table = database_get_table(&base, "user");

        printf("table name: %s\n", user_table->name);

        return 0;
}