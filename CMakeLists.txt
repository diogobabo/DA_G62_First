cmake_minimum_required(VERSION 3.21)
project(DA_T4_G62)

set(CMAKE_CXX_STANDARD 14)

include_directories(codigo)

add_executable(DA_T4_G62
        codigo/carrinha.cpp
        codigo/carrinha.h
        codigo/encomenda.cpp
        codigo/encomenda.h
        codigo/estafeta.cpp
        codigo/estafeta.h
        codigo/main.cpp
        codigo/pedido.cpp
        codigo/pedido.h)
