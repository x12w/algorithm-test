cmake_minimum_required(VERSION 3.10)
project(algorithm_test)

# 1. 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 2. 递归搜索所有子文件夹下的 .cpp 文件
file(GLOB_RECURSE ALL_SOURCES "*.cpp")

# 3. 遍历找到的所有源文件
foreach(source_file ${ALL_SOURCES})
    
    # 排除掉 build 目录或 cmake-build-debug 目录下的干扰文件（如果有）
    if(NOT source_file MATCHES "build|cmake-build-debug")
        
        # 获取文件名（不带后缀），例如从 "question120/solution1.cpp" 得到 "solution1"
        get_filename_component(exe_name ${source_file} NAME_WE)
        
        # 获取该文件所在的文件夹名，例如 "question120"
        get_filename_component(parent_dir ${source_file} DIRECTORY)
        get_filename_component(dir_name ${parent_dir} NAME)
        
        # 为了防止不同文件夹下有同名文件（比如都有 solution.cpp），
        # 建议将可执行文件名命名为：文件夹名_文件名 (例如: question120_solution1)
        set(target_name "${dir_name}_${exe_name}")
        
        # 生成可执行程序
        add_executable(${target_name} ${source_file})
        
        # 打印调试信息，让你知道生成了哪些 target
        message(STATUS "Target created: ${target_name}")
        
    endif()
endforeach()