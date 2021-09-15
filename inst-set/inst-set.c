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

/*! ===> Creates on 2021/9/14. <=== */

/*!
 * @author 范特西
 */
#include "inst-set/inst-set.h"

static void load_inst_set()
{
        INST_SET_CVAP_DATABASE = (f_inst_set_cvap_database) create_database;
        INST_SET_CVAP_TABLE = (f_inst_set_cvap_table) create_table;
        INST_SET_CVAP_COLUMN = (f_inst_set_cvap_column) create_column;
        INST_SET_ADD_COLUMN = (f_inst_set_add_column) table_add_column;
        INST_SET_ADD_TABLE = (f_inst_set_add_table) dahan_add_table;
        INST_SET_LVAP_DATABASE = (f_inst_set_lvap_database) dahan_add_table;
        INST_SET_LVAP_TABLE = (f_inst_set_lvap_table) dahan_get_table;
        INST_SET_LVAP_COLUMN = (f_inst_set_lvap_column) table_get_column;
        INST_SET_LVAP_DATABASE = (f_inst_set_lvap_database) load_database;
        INST_SET_FVAP_DATABASE = (f_inst_set_fvap_database) destroy_database;
        INST_SET_MOD_DATABASE_NAME = (f_inst_set_mod_database_name) modify_database_name;
}