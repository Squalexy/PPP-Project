#include "Declaracoes.h"
// --------------------------- LISTAS --------------------------- //

node_orcamento *create_list_orcamento() {
    return calloc(sizeof(node_orcamento), 1); //Cria uma lista
}

node_despesa *create_list_despesa() {
    return calloc(sizeof(node_despesa), 1);
}

// ---------- FUNCOES --------- //
//1. ORÇAMENTO

void input_orcamento(node_orcamento *lista_orcamentos) {
    char tipo[MAXTAMANHO];
    int valor;
    printf("Nome do tipo: \n"); //guardar numa variavél, ver se já aparece na lista; se existir, não acrescenta mas atualiza o valor do orçamento
    scanf("%s", tipo); //caso não exista, adiciona o tipo e o valor à lista
    printf("Valor do tipo: \n");
    scanf("%d", &valor);
    inserir_orcamento(lista_orcamentos, tipo, valor);
}

void inserir_orcamento(node_orcamento *lista_orcamentos, char *tipo, int valor) {
    node_orcamento *novo = calloc(sizeof(node_orcamento), 1); //Cria um novo node_orcamento; novo = nova lista do orçamento
    strcpy(novo->orc.tipo, tipo); //Determina o nome do orçamento nessa node_orcamento
    novo->orc.valor = valor; //Determina o valor do orçamento nessa node_orcamento
    node_orcamento *aux = lista_orcamentos;
    while (aux->next != NULL && strcasecmp(aux->orc.tipo, tipo) > 0) { //Enquanto o último node_orcamento apontar para vazio
        aux = aux->next; //O último node_orcamento apontará para um próximo node_orcamento
    }
    novo->next = aux->next;
    aux->next = novo;
}



void print_orcamento(node_orcamento *lista) {
    if (lista->orc.valor == 0) lista = lista->next; //voltar aqui depois porque isto é estranho as fuck
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
    int valor;
    printf("Nome do tipo que quer atualizar: \n"); //guardar numa variavél, ver se já aparece na lista; se existir, não acrescenta mas atualiza o valor do orçamento
    scanf("%s", tipo); //caso não exista, adiciona o tipo e o valor à lista
    printf("Valor do tipo que quer atualizar: \n");
    scanf("%d", &valor);
    atualizar_lista(lista_orcamentos, tipo, valor);
}


//2. DESPESAS

void input_despesas(node_despesa *lista_despesas) {
    char descricao[MAXTAMANHO];
    char tipo[MAXTAMANHO];
    int preco;
    printf("Descrição da despesa: \n");
    scanf("%s", descricao);
    printf("Valor da despesa: \n");
    scanf("%d", &preco);
    printf("Tipo de despesa: \n");
    scanf("%s", tipo);
    inserir_despesa(lista_despesas, descricao, preco, tipo);
}

void inserir_despesa(node_despesa *lista_despesas, char *descricao, int preco, char *tipo) {
    node_despesa *novo = calloc(sizeof(node_despesa), 1); //Cria um novo node_orcamento; novo = nova lista do orçamento
    strcpy(novo->orc.descricao, descricao); //Determina o nome do orçamento nessa node_orcamento
    novo->orc.preco = preco; //Determina o valor do orçamento nessa node_orcamento
    strcpy(novo->orc.tipo, tipo);
    novo->next = NULL;
    node_despesa *aux = lista_despesas;
    while (aux->next != NULL) { //Enquanto o último node_orcamento apontar para vazio
        aux = aux->next; //O último node_orcamento apontará para um próximo node_orcamento
    }
    aux->next = novo; //Cria um novo node_orcamento
    novo->next = NULL;
}

void print_despesa(node_despesa *despesa) {
    if (despesa->orc.preco == 0) despesa = despesa->next; //voltar aqui depois porque isto é estranho as fuck
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
    int preco;
    printf("Nome da descrição que quer atualizar: \n"); //guardar numa variavél, ver se já aparece na lista; se existir, não acrescenta mas atualiza o valor do orçamento
    scanf("%s", descricao); //caso não exista, adiciona o tipo e o valor à lista
    printf("Valor da descricao que quer atualizar: \n");
    scanf("%d", &preco);
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
        printf("Tipo: %s - Valor: %d\n", aux->orc.tipo, aux->orc.valor);
        inserir_orcamento(lista, aux->orc.tipo, aux->orc.valor);
    }
    free(aux);
    fclose(fptr);
}

//}


void escrever_orcamento(node_orcamento *novo) {
    FILE *fptr;
    fptr = fopen("Orcamento.data", "wb");
    if (fptr == NULL) {
        fprintf(stderr, "\nError opening file\n");
        exit(1);
    } else {
        while (novo != NULL) {
            if (novo->orc.valor == 0) novo = novo->next; //Por causa do calloc, aparece um 0 no início
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
        printf("DESCRIÇÃO: %s - VALOR: %d - TIPO: %s\n", aux->orc.descricao, aux->orc.preco, aux->orc.tipo);
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
            if (novo->orc.preco == 0) novo = novo->next; //Por causa do calloc, aparece um 0 no início
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