#ifndef TESTES_ESTRUTURAS_H
#define TESTES_ESTRUTURAS_H

#define MAXTAMANHO 50

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --------------------- DEFINIR AS ESTRUTURAS --------------------- //

typedef struct _orcamentado {
    char tipo[MAXTAMANHO];
    int valor;
}orcamentado;

//Lista dos orçamentos
typedef struct node_orcamento {
    orcamentado orc;
    struct node_orcamento *next;
}node_orcamento;

typedef struct _despesas{
    char descricao[MAXTAMANHO];
    int preco;
    char tipo[MAXTAMANHO];
}despesas;

//Lista das despesas
typedef struct node_despesa {
    despesas orc;
    struct node_despesa *next;
}node_despesa;

typedef struct _despesa_total{
    char despesa[MAXTAMANHO];
    int total;
}despesa_total;

//Lista das despesas totais calculadas
typedef struct node_despesa_total {
    despesa_total despesa;
    struct node_despesa_total *next;
}node_despesa_total;

typedef struct _desvio_orcamento{
    char orc[MAXTAMANHO];
    int original;
    int desvio;
}desvio_orcamento;

//Lista dos orçamentos com desvio superior a 10%
typedef struct node_desvio_orcamento{
    desvio_orcamento desvioOrc;
    struct node_desvio_orcamento *next;
}node_desvio_orcamento;

// ----------------------------------------------------------------- //

// --------------------- DECLARAR AS FUNÇÕES --------------------- //

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
void escrever_despesas_totais(node_despesa_total *novo);
void escrever_desvio_orcamento(node_desvio_orcamento* novo);

// -------------------------------------------------------------- //

#endif //TESTES_ESTRUTURAS_H

