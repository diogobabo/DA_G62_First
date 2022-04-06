cmake_minimum_required(VERSION 3.21)
project(DA_T6_G62)

set(CMAKE_CXX_STANDARD 14)

include_directories(codigo)

add_executable(DA_T4_G62
        codigo/carrinha.cpp codigo/carrinha.h
        codigo/encomenda.cpp codigo/encomenda.h
        codigo/main.cpp
        codigo/Empresa.cpp codigo/Empresa.h
        codigo/cenarios.h codigo/cenario1.cpp codigo/cenario2.cpp codigo/cenario3.cpp)
