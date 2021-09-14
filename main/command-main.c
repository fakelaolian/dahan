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
#include "kernel/bytebuf.h"
#include "kernel/options.h"

int main(void)
{
        bytebuf buf;
        bytebuf_open(&buf);

        unsigned long longsize = 1234567890;
        bytebuf_write(&longsize, sizeof(unsigned long), &buf);

        bytebuf_seek_beg(&buf, 0);

        unsigned long llongsize;
        bytebuf_read(&llongsize, sizeof(unsigned long), &buf);

        printf("test: %zu\n", llongsize);

        bytebuf_close(&buf);

        kconf_init("/home/shitbro/vacatsql");

        struct database mydb;
        create_database(&mydb, "mydb");

        struct table usertab;
        create_table(&usertab, "t_user");

        struct column username;
        struct column password;

        create_column(&username, "username", _VARCHAR, 255, NULL, NULL);
        create_column(&password, "password", _VARCHAR, 256, "没有默认值", NULL);

        table_add_column(&usertab, &username);
        table_add_column(&usertab, &password);

        vacat_add_table(&mydb, &usertab);

        struct database lmydb;
        load_database(&lmydb, "mydb");

        vacat_insert(&lmydb, "t_user");

        return 0;
}