cmake_minimum_required(VERSION 3.16)

project(cpp_tokenizer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(tokenizer
    src/main.cpp
    src/lexer.cpp
    src/stringutil.cpp
    src/parser.cpp
)


target_include_directories(tokenizer PRIVATE include)