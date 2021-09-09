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

/*! ===> Creates on 2021/9/8. <=== */

/*!
 * 反序列化表结构信息
 *
 * @author 范特西
 */
#include "_serial.h"

void deserialize_column(struct table *table, char *colpath)
{
        struct column col;

        char colname[CFS_NAME_MAX];
        char colremark[CFS_REMARK_MAX];
        char colvdef[CFS_VDEF_MAX];
        unsigned char coltype;
        unsigned int collen;

        FILE *fp = fopen(colpath, "rb");
        fread(colname, CFS_NAME_MAX, 1, fp);
        fread(colremark, CFS_REMARK_MAX, 1, fp);
        fread(colvdef, CFS_VDEF_MAX, 1, fp);
        fread(&coltype, sizeof(unsigned char), 1, fp);
        fread(&collen, sizeof(unsigned int), 1, fp);
        fclose(fp);

        column_init(&col, colname, coltype, collen);
        strncpy(col.remark, colremark, CFS_REMARK_MAX);
        strncpy(col.vdef, colvdef, CFS_VDEF_MAX);

        printf("col(%s), type(%d), len(%d), vdef(%s), remark(%s)\n",
             col.name, col.type, col.len, col.vdef, col.remark);

        table_add_column(table, &col);
}

/**
 * 加载所有字段
 *
 * @param table         表结构体指针
 * @param folcsdir      fcols目录
 */
void load_columns(struct table *table, const char *fcolsdir)
{
        DIR *dirp = opendir(fcolsdir);
        struct dirent *e;

        while ((e = readdir_skip_dot_and_dotdot(dirp)) != NULL) {
                char colpath[CFS_PATH_MAX];
                xsnprintf(colpath, CFS_PATH_MAX, "%s/%s", fcolsdir, e->d_name);
                deserialize_column(table, colpath);
        }
        closedir(dirp);
}

/**
 * 反序列化表
 *
 * @param base      数据库结构体指针
 * @param tabledir  表文件所在目录
 * @param basedir   表名
 */
void deserialize_table(struct database *base, const char *tabledir, char *name)
{
        struct table table;
        char remark[CFS_REMARK_MAX];

        // boot文件路径
        char bootpath[CFS_PATH_MAX];
        xsnprintf(bootpath, CFS_PATH_MAX, "%s/%s", tabledir, CFS_TABLE_NAME);

        FILE *fp = fopen(bootpath, "rb");
        fread(remark, CFS_REMARK_MAX, 1, fp);
        fclose(fp);

        table_init(&table, name, remark);

        char fcolsdir[CFS_PATH_MAX];
        xsnprintf(fcolsdir, CFS_PATH_MAX, "%s/%s", tabledir, CFS_FCOLS_DIR_NAME);

        // 加载字段列表
        load_columns(&table, fcolsdir);

        cfs_add_table(base, &table);
}

/**
 * 加载所有表
 *
 * @param base      数据库结构体指针
 * @param basedir   数据库目录
 */
void load_tables(struct database *base, const char *basedir)
{
        DIR* dirp = opendir(basedir);
        struct dirent *e;

        while ((e = readdir_skip_dot_and_dotdot(dirp)) != NULL) {
                char bootdir[PATH_MAX];
                xsnprintf(bootdir, PATH_MAX, "%s/%s", basedir, e->d_name);
                deserialize_table(base, bootdir, e->d_name);
        }
        closedir(dirp);
}

/**
 * 加载数据库
 *
 * @param base      数据库指针
 * @param basedir   数据库所在目录
 * @param name      数据库名称
 */
extern bool
load_database(struct database *base, const char *basedir, const char *name)
{
        bool ret = false;
        char target[CFS_PATH_MAX];
        xsnprintf(target, CFS_PATH_MAX, "%s/%s", basedir, name);

        if (!file_exist(target)) {
                ERROR("没有找到“%s”数据库", name);
                goto load_database_out;
        }

        // 初始化结构体
        database_init(base, basedir, name);

        // 如果文件夹为空的话不做任何加载
        if(is_empty_dir(target))
                goto load_database_out;

        // 加载表文件
        load_tables(base, target);

load_database_out:
        return ret;
}