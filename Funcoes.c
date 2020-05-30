#include "Declaracoes.h"

// --------------------------- LISTAS --------------------------- //

node_orcamento *create_list_orcamento() {
    return calloc(sizeof(node_orcamento), 1); //Cria uma lista
}

node_despesa *create_list_despesa() {
    return calloc(sizeof(node_despesa), 1);
}

node_despesa_total *create_list_despesa_total(){
    return calloc(sizeof(node_despesa_total),1);
}

// ---------- FUNCOES --------- //
//1. ORÇAMENTO

void input_orcamento(node_orcamento *lista_orcamentos) {
    char tipo[MAXTAMANHO];
    char valor[MAXTAMANHO];
    int preco;
    printf("Nome do tipo: \n");
    fgets(tipo, MAXTAMANHO, stdin);
    tipo[strlen(tipo)-1] = '\0'; //para não meter um \n
    printf("Valor do tipo: \n");
    fgets(valor, MAXTAMANHO, stdin);
    valor[strlen(valor)-1] = '\0';
    preco = (int)strtol(valor,NULL,0);
    inserir_orcamento(lista_orcamentos, tipo, preco);
}

void inserir_orcamento(node_orcamento *lista_orcamentos, char *tipo, int valor) {
    node_orcamento *novo = calloc(sizeof(node_orcamento), 1);
    strcpy(novo->orc.tipo, tipo);
    novo->orc.valor = valor;
    node_orcamento *aux = lista_orcamentos;
    while (aux->next != NULL && strcasecmp(aux->next->orc.tipo, tipo)<0) { //Ordem alfabética
        aux = aux->next;
    }
    novo->next = aux->next;
    aux->next = novo;
}

void print_orcamento(node_orcamento *lista) {
    if (lista->orc.valor == 0) lista = lista->next; //calloc cria um 0 na lista
    while (lista != NULL) {
        printf("TIPO: %s - ORÇAMENTO: %d \n", lista->orc.tipo, lista->orc.valor);
        lista = lista->next;
    }
}

void atualizar_lista(node_orcamento *lista_orcamentos, char *tipo, int valor) {
    while (lista_orcamentos != NULL) {
        if (strcasecmp(lista_orcamentos->orc.tipo, tipo) == 0) {
            lista_orcamentos->orc.valor = valor;
            break;
        }
        lista_orcamentos = lista_orcamentos->next;
    }
}

void atualizar_orcamento(node_orcamento *lista_orcamentos) {
    char tipo[MAXTAMANHO];
    char valor[MAXTAMANHO];
    int preco;
    printf("Nome do tipo que quer atualizar: \n");
    fgets(tipo, MAXTAMANHO, stdin);
    tipo[strlen(tipo)-1] = '\0';
    printf("Valor do tipo que quer atualizar: \n");
    fgets(valor, MAXTAMANHO, stdin);
    valor[strlen(valor)-1] = '\0';
    preco = (int)strtol(valor,NULL,0);
    atualizar_lista(lista_orcamentos, tipo, preco);
}

//2. DESPESAS

void input_despesas(node_despesa *lista_despesas) {
    char descricao[MAXTAMANHO];
    char tipo[MAXTAMANHO];
    char valor[MAXTAMANHO];
    int preco;
    printf("Descrição da despesa: \n");
    fgets(descricao, MAXTAMANHO, stdin);
    descricao[strlen(descricao)-1] = '\0';
    printf("Valor da despesa: \n");
    fgets(valor, MAXTAMANHO, stdin);
    valor[strlen(valor)-1] = '\0';
    preco = (int)strtol(valor,NULL,0);
    printf("Tipo de despesa: \n");
    fgets(tipo, MAXTAMANHO, stdin);
    tipo[strlen(tipo)-1] = '\0';
    inserir_despesa(lista_despesas, descricao, preco, tipo);
}

void inserir_despesa(node_despesa *lista_despesas, char *descricao, int preco, char *tipo) {
    node_despesa *novo = calloc(sizeof(node_despesa), 1);
    strcpy(novo->orc.descricao, descricao);
    novo->orc.preco = preco;
    strcpy(novo->orc.tipo, tipo);
    novo->next = NULL;
    node_despesa *aux = lista_despesas;
    while (aux->next != NULL && strcasecmp(aux->next->orc.tipo, tipo)<0) {
        aux = aux->next;
    }
    novo -> next = aux -> next;
    aux -> next = novo;
}

void print_despesa(node_despesa *despesa) {
    if (despesa->orc.preco == 0) despesa = despesa->next;
    while (despesa != NULL) {
        printf("DESCRIÇÃO: %s - ORÇAMENTO: %d  - TIPO: %s\n", despesa->orc.descricao, despesa->orc.preco,
               despesa->orc.tipo);
        despesa = despesa->next;
    }
}

void atualizar_lista_dois(node_despesa *lista_despesas, char *descricao, int preco) {
    while (lista_despesas != NULL) {
        if (strcasecmp(lista_despesas->orc.descricao, descricao) == 0) {
            lista_despesas->orc.preco = preco;
            break;
        }
        lista_despesas = lista_despesas->next;
    }
}

void atualizar_despesas(node_despesa *lista_despesas) {
    char descricao[MAXTAMANHO];
    char valor[MAXTAMANHO];
    int preco;
    printf("Nome da descrição que quer atualizar: \n");
    fgets(descricao, MAXTAMANHO, stdin);
    descricao[strlen(descricao)-1] = '\0';
    printf("Valor da descricao que quer atualizar: \n");
    fgets(valor, MAXTAMANHO, stdin);
    valor[strlen(valor)-1] = '\0';
    preco = (int)strtol(valor,NULL,0);
    atualizar_lista_dois(lista_despesas, descricao, preco);
}

//3. FICHEIROS

void ler_orcamento(node_orcamento *lista) {
    FILE *fptr;
    fptr = fopen("Orcamento.data", "rb");
    if (fptr == NULL) {
        fprintf(stderr, "Error opening file\n");
        exit(1);
    }
    node_orcamento *aux = calloc(sizeof(node_orcamento), 1);
    limpar_orcamentos(lista);
    while (fread(aux, sizeof(node_orcamento), 1, fptr)) {
        inserir_orcamento(lista, aux->orc.tipo, aux->orc.valor);
    }
    free(aux);
    fclose(fptr);
}

void escrever_orcamento(node_orcamento *novo) {
    FILE *fptr;
    fptr = fopen("Orcamento.data", "wb");
    if (fptr == NULL) {
        fprintf(stderr, "\nError opening file\n");
        exit(1);
    } else {
        while (novo != NULL) {
            if (novo->orc.valor == 0) novo = novo->next;
            fwrite(novo, sizeof(node_orcamento), 1, fptr);
            novo = novo->next;
        }
    }
    fclose(fptr);
}

void ler_despesas(node_despesa *despesa) {
    FILE *fptr;
    fptr = fopen("Despesas.data", "rb");
    if (fptr == NULL) {
        fprintf(stderr, "Error opening file\n");
        exit(1);
    }
    node_despesa *aux = calloc(sizeof(node_despesa), 1);
    limpar_despesas(despesa);
    while (fread(aux, sizeof(node_despesa), 1, fptr)) {
        inserir_despesa(despesa, aux->orc.descricao, aux->orc.preco, aux->orc.tipo);
    }
    free(aux);
    fclose(fptr);
}

void escrever_despesas(node_despesa *novo) {
    FILE *fptr;
    fptr = fopen("Despesas.data", "wb");
    if (fptr == NULL) {
        fprintf(stderr, "\nError opening file\n");
        exit(1);
    } else {
        while (novo != NULL) {
            if (novo->orc.preco == 0) novo = novo->next;
            fwrite(novo, sizeof(node_despesa), 1, fptr);
            novo = novo->next;
        }
    }
    fclose(fptr);
}

//Funções para limpar_orcamentos a lista e não duplicá-la cada vez que ler o ficheiro de orçamento
//Pode acontecer eu ler um ficheiro, adicionar um elemento à lista, acrescentá-lo ao ficheiro e ler novamente o ficheiro
//Como não limpei a lista, ele iria ler o ficheiro antigo (sem o elemento adicionado) e o ficheiro novo, ou seja, iria duplicar os elementos
//já existentes
void limpar_orcamentos(node_orcamento *lista) {
    node_orcamento *copia = lista;
    lista = lista->next;
    copia->next = NULL;
    while (lista != NULL) {
        node_orcamento *next = lista->next;
        free(lista);
        lista = next;
    }
}
void limpar_despesas(node_despesa* despesa) {
    node_despesa *copia = despesa;
    despesa = despesa->next;
    copia->next = NULL;
    while (despesa != NULL) {
        node_despesa *next = despesa->next;
        free(despesa);
        despesa = next;
    }
}

void despesas_totais(node_despesa *despesa, node_despesa_total* lista_despesas_totais){
    int contagem = 0;
    if (despesa->orc.preco == 0) despesa = despesa->next;
    while (despesa != NULL){
        if (strcasecmp(despesa->orc.tipo, despesa->next->orc.tipo)==0){ //se o próximo elemento for o mesmo tipo
            contagem += despesa->orc.preco;
            despesa = despesa -> next;
        }
        else if (strcasecmp(despesa->orc.tipo, despesa->next->orc.tipo)!=0){ //se o próximo elemento for um tipo diferente
            contagem += despesa->orc.preco;
            printf("Despesas totais do tipo %s : %d\n", despesa->orc.tipo, contagem);
            inserir_despesas_totais(lista_despesas_totais, despesa, contagem);
            contagem = 0;
            despesa = despesa -> next;
        }
    }
}

void inserir_despesas_totais(node_despesa_total *lista_despesas_totais, node_despesa* despesa, int contagem){
    node_despesa_total *novo = calloc(sizeof(node_despesa_total),1);
    strcpy(novo->despesa.despesa, despesa->orc.tipo);
    novo->despesa.total = contagem;
    node_despesa_total *aux = lista_despesas_totais;
    while (aux->next!=NULL) aux = aux->next;
    novo->next = aux-> next;
    aux->next = novo;
};

void desvio_despesas(node_despesa_total * despesa_final, node_orcamento *lista){
    if (despesa_final->despesa.total == 0) despesa_final = despesa_final->next;
    printf("Os seguintes orçamentos sofreram um desvio superior a 10 por cento:\n");
    while (despesa_final != NULL){
        int desvio = lista->orc.valor/10;
        if ((despesa_final->despesa.total-desvio)>lista->orc.valor){
            printf("Tipo: %s - Valor: %d\n", lista->orc.tipo, despesa_final->despesa.total);
        }
    }
}