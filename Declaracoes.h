#ifndef TESTES_ESTRUTURAS_H
#define TESTES_ESTRUTURAS_H
#endif //TESTES_ESTRUTURAS_H

#define MAXTAMANHO 50

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Estruturas.h"



//0. NODES
node_orcamento* create_list_orcamento();
node_despesa* create_list_despesa();
node_despesa_total* create_list_despesa_total();
node_desvio_orcamento* create_list_desvio_orcamento();

//1. ORÇAMENTO
void input_orcamento(node_orcamento* lista_orcamentos);
void inserir_orcamento(char *tipo, int valor);
void print_orcamento();
void atualizar_lista(char *tipo, int valor);
void atualizar_orcamento();

//2. DESPESAS
void input_despesas();
void inserir_despesa(char *descricao, int preco, char *tipo);
void print_despesa();
void atualizar_lista_despesas(char *descricao, int preco);
void atualizar_despesas();

//3. FICHEIROS
void ler_orcamento();
void escrever_orcamento();
void ler_despesas();
void escrever_despesas();

//4. LIMPEZA
void limpar_orcamentos();
void limpar_despesas();

//5. PROGRAMA 2
void despesas_totais();
void inserir_despesas_totais(node_despesa *despesa, int contagem);
void desvio_despesas();
void inserir_desvio_orcamento(node_desvio_orcamento* lista_desvio_orcamento, node_orcamento* lista, int desvio_despesa);
void escrever_despesas_totais(node_despesa_total *novo, char *nome);
void escrever_desvio_orcamento(node_desvio_orcamento* novo, char *nome2);
int get_one_line(FILE * fich, char *linha, int lim);