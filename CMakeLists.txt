cmake_minimum_required(VERSION 3.17)
project(ccompiler C)

set(CMAKE_C_STANDARD 99)

add_executable(ccompiler main.c scan.c defs.h data.h decl.h tree.c expr.c interp.c)