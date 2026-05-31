cmake_minimum_required(VERSION 3.16)

project(cpp_tokenizer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(tokenizer
    src/main.cpp
    src/tokenizer.cpp
    src/stringutil.cpp
)

target_include_directories(tokenizer PRIVATE include)