cmake_minimum_required(VERSION 3.25)
project(Mini-Aims-Portal)

set(CMAKE_CXX_STANDARD 14)

include_directories(headers)

add_executable(Mini-Aims-Portal
        headers/Admin.h
        headers/starter_func.h
        headers/Student.h
        headers/Teacher.h
        Admin_ops.cpp
        main.cpp
        starter_func_declaration.cpp
        Student_ops.cpp
        Teacher_ops.cpp)
