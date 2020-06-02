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
void inserir_orcamento(node_orcamento* lista_orcamentos, char* tipo, int valor);
void print_orcamento(node_orcamento* lista);
void atualizar_lista(node_orcamento* lista_orcamentos, char* tipo, int valor);
void atualizar_orcamento(node_orcamento* lista_orcamentos);

//2. DESPESAS
void input_despesas(node_despesa* lista_despesas);
void inserir_despesa(node_despesa* lista_despesas, char* descricao, int preco, char* tipo);
void print_despesa(node_despesa* despesa);
void atualizar_lista_dois(node_despesa* lista_despesas, char* descricao, int preco);
void atualizar_despesas(node_despesa* lista_despesas);

//3. FICHEIROS
void ler_orcamento(node_orcamento* lista);
void escrever_orcamento(node_orcamento* lista);
void ler_despesas(node_despesa *despesa);
void escrever_despesas(node_despesa *novo);

//4. LIMPEZA
void limpar_orcamentos(node_orcamento *lista);
void limpar_despesas(node_despesa* despesa);

//5. PROGRAMA 2
void despesas_totais(node_despesa *despesa, node_despesa_total* lista_despesas_totais);
void inserir_despesas_totais(node_despesa_total *lista_despesas_totais, node_despesa* despesa, int contagem);
void desvio_despesas(node_desvio_orcamento *lista_desvio_orcamento, node_orcamento *lista, node_despesa_total* lista_despesas_totais);
void inserir_desvio_orcamento(node_desvio_orcamento* lista_desvio_orcamento, node_orcamento* lista, int desvio_despesa);
void escrever_despesas_totais(node_despesa_total *novo, char *nome);
void escrever_desvio_orcamento(node_desvio_orcamento* novo, char *nome2);