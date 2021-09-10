# =================================================================================
#
# Copyright (C) 2020 luots All rights reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# =================================================================================/

### ==============================================
### ===> Creates on 2021/07/20. <=== ###
### author 范特西
CMAKE_MINIMUM_REQUIRED(VERSION 3.13...3.19)
PROJECT(vap C)

SET(CMAKE_C_STANDARD 11)

ADD_DEFINITIONS(-D__vap_debug)
ADD_DEFINITIONS(-fgnu89-inline)

INCLUDE_DIRECTORIES(SYSTEM ${PROJECT_SOURCE_DIR}/include)
INCLUDE_DIRECTORIES(SYSTEM ${PROJECT_SOURCE_DIR}/sha256)

ADD_EXECUTABLE(
        ${PROJECT_NAME}
        main/main.c
        kernel/column.c
        kernel/table.c
        kernel/database.c
        kernel/kconfig.c
        kernel/serialize/serialize.c
        kernel/serialize/deserialize.c
        kernel/aux/kcheck.c
        tools/string.c
        tools/files.c
        sha256/sha256.c
)
