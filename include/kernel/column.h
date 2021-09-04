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
#pragma once

#include <glibc.h>
#include <string>

/**
 * 字段类型枚举
 */
enum COLTYPE
{
        _INT,
        _CHAR,
        _FLOAT,
        _DECIMAL,
        _TEXT,
};

/**
 * 字段类
 */
class Column
{
public:
        inline Column(const char* name, COLTYPE coltype, size_t len)
        {
                this->name = std::move(name);
                this->type = coltype;
                this->len = len;
        }

public:
        size_t len;
        std::string name;
        std::string remark;
        std::string vdef; // 默认值
        bool allow_null; // 是否允许为空
        COLTYPE type;
};