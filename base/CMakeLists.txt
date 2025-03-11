# CMake 支持的最低版本
cmake_minimum_required(VERSION 3.31)
# 项目名称及其其他信息
project(calendar VERSION 0.1.0)
# 设置可执行文件的存放目录
set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
# 源文件目录
aux_source_directory(src SRC_FILES)
# 库文件目录
include_directories(include)
# 根据源文件来生成可执行的二进制文件 (自动匹配上述项目的名字)
add_executable(${CMAKE_PROJECT_NAME} ${SRC_FILES})
