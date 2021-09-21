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
#include "kernel/bytebuf.h"
#include "kernel/options.h"
#include "ifs/ifs.h"

void test_ifs()
{
}

void test_options()
{
        kconf_init("/home/shitbro/dahansql");

        vasm_load_impl_v0();

        vasm_dvap_database(mydb);
        vasm_mvap_database(&mydb, "mydb");

        vasm_dvap_table(usertab);
        vasm_mvap_table(&usertab, "t_user");

        vasm_dvap_column(username);
        vasm_dvap_column(password);

        vasm_mvap_column(&username, "username", _VARCHAR, 255, NULL, NULL);
        vasm_mvap_column(&password, "password", _VARCHAR, 256, "没有默认值", NULL);

        vasm_add_column(&usertab, &username);
        vasm_add_column(&usertab, &password);

        vasm_add_table(&mydb, &usertab);

        vasm_dvap_database(lmydb);
        vasm_lvap_database(&lmydb, "mydb");

        vasm_fvap_database(&mydb);
        vasm_fvap_database(&lmydb);
}

void test_bytebuf()
{
        __bytebuf *buf = bytebuf_open(64);

        char *helloworld = "helloworld..........这里是第10个点";
        bytebuf_write(helloworld, strlen(helloworld), buf);
        u4 number = 123456789;
        bytebuf_write(&number, sizeof(u4), buf);

        char *reads = kmalloc(strlen(helloworld) + 1);
        memset(reads, 0, strlen(helloworld) + 1);
        bytebuf_read(reads, strlen(helloworld), buf);

        u4 rnumber;
        bytebuf_read(&rnumber, sizeof(u4), buf);

        printf("char *: %s, u4: %d\n", reads, rnumber);

        bytebuf_close(buf);
}

//#define __ifs__0
//#define __bytebuf__0
#define __options__0
int main(void)
{
#ifdef __bytebuf__0
        test_bytebuf();
#endif
#ifdef __options__0
        test_options();
#endif
#ifdef __ifs__0
        test_ifs();
#endif
        return 0;
}