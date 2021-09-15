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

// #define __options__0
void test_options()
{
        kconf_init("/home/shitbro/dahansql");

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

        dahan_add_table(&mydb, &usertab);

        struct database lmydb;
        load_database(&lmydb, "mydb");

        dahan_insert(&lmydb, "t_user");
}

#define __bytebuf__0
void test_bytebuf()
{
        bytebuf *buf = bufopen(12);

        char *helloworld = "helloworld..........这里是第10个点";
        bufwrite(helloworld, strlen(helloworld), buf);
        unsigned int number = 123456789;
        bufwrite(&number, sizeof(unsigned int), buf);

        char *reads = kmalloc(strlen(helloworld) + 1);
        memset(reads, 0, strlen(helloworld) + 1);
        bufread(reads, strlen(helloworld), buf);

        unsigned int rnumber;
        bufread(&rnumber, sizeof(unsigned int), buf);

        printf("char *: %s, unsigned int: %d\n", reads, rnumber);

}

int main(void)
{
#ifdef __bytebuf__0
        test_bytebuf();
#endif
#ifdef __options__0
        test_options();
#endif
        return 0;
}