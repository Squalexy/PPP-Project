cmake_minimum_required(VERSION 3.15)
project(PROJETO C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-Wall -Wextra")

add_executable(1_gerar_ficheiros "Funcoes.c" "1_gerar_despesas.c" "Declaracoes.h")
add_executable(2_ler_ficheiros "Funcoes.c" "2_analisar_despesas.c" "Declaracoes.h")