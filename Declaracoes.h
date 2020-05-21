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

typedef struct _despesas{
    char descricao[MAXTAMANHO];
    int preco;
    char tipo[MAXTAMANHO];
}despesas;

typedef struct node {
    orcamentado orc;
    struct node_orcamento *next;
}node_orcamento;

typedef struct node_dois {
    despesas orc;
    struct node_despesa *next;
}node_despesa;

// ----------------------------------------------------------------- //

// --------------------- DECLARAR AS FUNÇÕES --------------------- //

//0. NODES
node_orcamento* create_list();
node_despesa* create_list_dois();

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
void limpar(node_orcamento *lista);
void limpar_dois(node_despesa* despesa);

// -------------------------------------------------------------- //

#endif //TESTES_ESTRUTURAS_H

