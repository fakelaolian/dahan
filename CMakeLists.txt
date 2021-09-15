# =================================================================================
#
# copyright (c) 2020 luots all rights reserved.
#
# licensed under the apache license, version 2.0 (the "license");
# you may not use this file except in compliance with the license.
# you may obtain a copy of the license at
#
#     http://www.apache.org/licenses/license-2.0
#
# unless required by applicable law or agreed to in writing, software
# distributed under the license is distributed on an "as is" basis,
# without warranties or conditions of any kind, either express or implied.
# see the license for the specific language governing permissions and
# limitations under the license.
#
# =================================================================================/

### ==============================================
### ===> creates on 2021/07/20. <=== ###
### author 范特西
cmake_minimum_required(VERSION 3.13...3.19)
project(dahan C)

set(CMAKE_C_STANDARD 11)


add_definitions(-D__dahan_debug)
# add_definitions(-D__dahan_close_check)
add_definitions(-fgnu89-inline)

include_directories(system ${PROJECT_SOURCE_DIR}/include)
include_directories(system ${PROJECT_SOURCE_DIR}/sha256)

aux_source_directory(${CMAKE_SOURCE_DIR}/main main)
aux_source_directory(${CMAKE_SOURCE_DIR}/sha256 sha256)
aux_source_directory(${CMAKE_SOURCE_DIR}/kernel kernel)
aux_source_directory(${CMAKE_SOURCE_DIR}/kernel/aux kernel_aux)
aux_source_directory(${CMAKE_SOURCE_DIR}/kernel/serialize kernel_serialize)
aux_source_directory(${CMAKE_SOURCE_DIR}/kernel/buffer kernel_buffer)
aux_source_directory(${CMAKE_SOURCE_DIR}/tools tools)
aux_source_directory(${CMAKE_SOURCE_DIR}/vasm vasm)

add_executable(
        ${PROJECT_NAME}
        ${main}
        ${sha256}
        ${kernel}
        ${kernel_aux}
        ${kernel_serialize}
        ${kernel_buffer}
        ${tools}
        ${vasm}
)
