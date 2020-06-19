#ifndef TESTES_ESTRUTURAS_H
#define TESTES_ESTRUTURAS_H
#endif //TESTES_ESTRUTURAS_H

#define MAXTAMANHO 50

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Estruturas.h"

//0. INICIALIZAÇÃO DE LISTAS
void create_list_orcamento();
void create_list_despesa();
void create_list_despesa_total();
void create_list_desvio_orcamento();

//1. ORÇAMENTO
void input_orcamento();
void inserir_orcamento(char *tipo, int valor);
void print_orcamento();
void atualizar_lista_orcamento(char *tipo, int valor);
void atualizar_orcamento();

//2. DESPESAS
void input_despesas();
void inserir_despesa(char *descricao, int preco, char *tipo);
void print_despesa();
void atualizar_lista_despesas(char *descricao, int preco);
void atualizar_despesas();

//3. FICHEIROS DE ENTRADA
void ler_orcamento();
void escrever_orcamento();
void ler_despesas();
void escrever_despesas();

//4. DESPESAS TOTAIS
void despesas_totais();
void inserir_despesas_totais(node_despesa *despesa, int contagem);
void print_despesas_totais();

//5. DESVIO DE ORÇAMENTO
void desvio_despesas();
void inserir_desvio_orcamento(int desvio_despesa, orcamentado o);
void print_desvio_orcamento();

//5. FICHEIROS DE SAÍDA
void escrever_despesas_totais(char *nome);
void escrever_desvio_orcamento(char *nome2);

//6. LIMPEZA DE LISTAS
void limpar_orcamentos(char clear_header);
void limpar_despesas(char clear_header);
void limpar_despesas_totais(char clear_header);
void limpar_desvio_orcamento(char clear_header);

//7. FICHEIROS NO GERAL
int get_one_line(FILE * fich, char *linha, int lim);