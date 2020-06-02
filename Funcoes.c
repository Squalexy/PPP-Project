#include "Declaracoes.h"

// --------------------------- LISTAS --------------------------- //

node_orcamento *create_list_orcamento() {
    return calloc(sizeof(node_orcamento), 1); //Cria uma lista
}

node_despesa *create_list_despesa() {
    return calloc(sizeof(node_despesa), 1);
}

node_despesa_total *create_list_despesa_total() {
    return calloc(sizeof(node_despesa_total), 1);
}

node_desvio_orcamento *create_list_desvio_orcamento() {
    return calloc(sizeof(node_desvio_orcamento), 1);
}

// ---------- FUNCOES --------- //
//1. ORÇAMENTO

void input_orcamento(node_orcamento *lista_orcamentos) {
    char tipo[MAXTAMANHO];
    char valor[MAXTAMANHO];
    int preco;
    printf("Nome do tipo: \n");
    fgets(tipo, MAXTAMANHO, stdin);
    tipo[strlen(tipo) - 1] = '\0'; //para não meter um \n
    printf("Valor do tipo: \n");
    fgets(valor, MAXTAMANHO, stdin);
    valor[strlen(valor) - 1] = '\0';
    preco = (int) strtol(valor, NULL, 0);
    inserir_orcamento(lista_orcamentos, tipo, preco);
}

void inserir_orcamento(node_orcamento *lista_orcamentos, char *tipo, int valor) {
    node_orcamento *novo = calloc(sizeof(node_orcamento), 1);
    strcpy(novo->orc.tipo, tipo);
    novo->orc.valor = valor;
    node_orcamento *aux = lista_orcamentos;
    while (aux->next != NULL && strcasecmp(aux->next->orc.tipo, tipo) < 0) { //Ordem alfabética
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
    tipo[strlen(tipo) - 1] = '\0';
    printf("Valor do tipo que quer atualizar: \n");
    fgets(valor, MAXTAMANHO, stdin);
    valor[strlen(valor) - 1] = '\0';
    preco = (int) strtol(valor, NULL, 0);
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
    descricao[strlen(descricao) - 1] = '\0';
    printf("Valor da despesa: \n");
    fgets(valor, MAXTAMANHO, stdin);
    valor[strlen(valor) - 1] = '\0';
    preco = (int) strtol(valor, NULL, 0);
    printf("Tipo de despesa: \n");
    fgets(tipo, MAXTAMANHO, stdin);
    tipo[strlen(tipo) - 1] = '\0';
    inserir_despesa(lista_despesas, descricao, preco, tipo);
}

void inserir_despesa(node_despesa *lista_despesas, char *descricao, int preco, char *tipo) {
    node_despesa *novo = calloc(sizeof(node_despesa), 1);
    strcpy(novo->orc.descricao, descricao);
    novo->orc.preco = preco;
    strcpy(novo->orc.tipo, tipo);
    novo->next = NULL;
    node_despesa *aux = lista_despesas;
    while (aux->next != NULL && strcasecmp(aux->next->orc.tipo, tipo) < 0) {
        aux = aux->next;
    }
    novo->next = aux->next;
    aux->next = novo;
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
    descricao[strlen(descricao) - 1] = '\0';
    printf("Valor da descricao que quer atualizar: \n");
    fgets(valor, MAXTAMANHO, stdin);
    valor[strlen(valor) - 1] = '\0';
    preco = (int) strtol(valor, NULL, 0);
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

//Funções para limpar orçamentos e listas cada vez que os ler para não duplicá-los ao fazer print
//Pode acontecer eu ler um ficheiro, adicionar um elemento à lista, acrescentá-lo ao ficheiro e ler novamente o ficheiro
//Como não limpei a lista, ele iria ler o ficheiro antigo (sem o elemento adicionado) e o ficheiro novo, ou seja, iria duplicar os elementos já existentes
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

void limpar_despesas(node_despesa *despesa) {
    node_despesa *copia = despesa;
    despesa = despesa->next;
    copia->next = NULL;
    while (despesa != NULL) {
        node_despesa *next = despesa->next;
        free(despesa);
        despesa = next;
    }
}

//Insere na lista o tipo de despesas (ex: ALIMENTAÇÃO) e o valor total das despesas
//Compara sempre com o elemento a seguir para saber quando dar reset às despesas se o tipo for diferente (ex: ALIMENTAÇÃO e TRANSPORTES)
void despesas_totais(node_despesa *despesa, node_despesa_total *lista_despesas_totais) {
    int contagem = 0;
    if (despesa->orc.preco == 0) despesa = despesa->next;
    while (despesa != NULL && despesa->next != NULL) {
        if (despesa->next == NULL) {
            contagem += despesa->orc.preco;
            printf("Despesas totais do tipo %s : %d\n", despesa->orc.tipo, contagem);
            inserir_despesas_totais(lista_despesas_totais, despesa, contagem);
        } else if (strcasecmp(despesa->orc.tipo, despesa->next->orc.tipo) ==
                   0) { //se o próximo elemento for o mesmo tipo
            contagem += despesa->orc.preco;
        } else {//se o próximo elemento for um tipo diferente
            contagem += despesa->orc.preco;
            printf("Despesas totais do tipo %s : %d\n", despesa->orc.tipo, contagem);
            inserir_despesas_totais(lista_despesas_totais, despesa, contagem);
            contagem = 0;
        }
        despesa = despesa->next;
    }
}

//Aloca memória a uma nova lista onde inserir tipo da despesa (ex: ALIMENTAÇÃO) e o valor total das despesas desse tipo
void inserir_despesas_totais(node_despesa_total *lista_despesas_totais, node_despesa *despesa, int contagem) {
    node_despesa_total *novo = calloc(sizeof(node_despesa_total), 1);
    strcpy(novo->despesa.despesa, despesa->orc.tipo);
    novo->despesa.total = contagem;
    node_despesa_total *aux = lista_despesas_totais;
    while (aux->next != NULL) aux = aux->next;
    novo->next = aux->next;
    aux->next = novo;
};


//Guarda numa lista as despesas que têm um valor superior a 10% em relação ao orçamentado inicialmente
//Ex: despesa 220, orçamento 150; lista_desvio_orcamento de 70 euros ou 46%
void desvio_despesas(node_desvio_orcamento *lista_desvio_orcamento, node_orcamento *lista,
                     node_despesa_total *lista_despesas_totais) {

    if (lista->orc.valor == 0) lista = lista->next;
    if (lista_despesas_totais->despesa.total == 0) lista_despesas_totais = lista_despesas_totais->next;
    printf("Os seguintes orçamentos sofreram um lista_desvio_orcamento superior a 10%%:\n");

    while (lista_despesas_totais != NULL && lista != NULL) {
        int desvio_despesa;
        int percentagem = (((lista_despesas_totais->despesa.total) * 100) / lista->orc.valor) - 100;
        if ((lista_despesas_totais->despesa.total - lista_desvio_orcamento->desvioOrc.desvio) >
            lista->orc.valor) { //ex: se despesas220-desvio20 > orc200
            printf("Tipo: %s - Valor: %d - Desvio: %d%% (+%d) - Orçamento inicial: %d\n", lista->orc.tipo,
                   lista_despesas_totais->despesa.total, percentagem,
                   lista_despesas_totais->despesa.total - lista->orc.valor, lista->orc.valor);
            desvio_despesa = lista_despesas_totais->despesa.total - lista->orc.valor;
            inserir_desvio_orcamento(lista_desvio_orcamento, lista, desvio_despesa);
        }
        lista = lista->next;
        lista_despesas_totais = lista_despesas_totais->next;
    }
}

void
inserir_desvio_orcamento(node_desvio_orcamento *lista_desvio_orcamento, node_orcamento *lista, int desvio_despesa) {
    node_desvio_orcamento *novo = calloc(sizeof(node_desvio_orcamento), 1);
    strcpy(novo->desvioOrc.orc, lista->orc.tipo);
    novo->desvioOrc.original = lista->orc.valor;
    novo->desvioOrc.desvio = desvio_despesa;
    //PARA VERIFICAR SE ESTÁ A ADICIONAR CORRETAMENTE
    //printf("Orcamento inicial de %s: %d \t Orcamento final: %d \t Desvio: %d\n", novo2->desvioOrc.orc, novo2->desvioOrc.original,
    //      novo2->desvioOrc.original + novo2->desvioOrc.desvio, novo2->desvioOrc.desvio);
    node_desvio_orcamento *aux = lista_desvio_orcamento;
    while (aux->next != NULL) aux = aux->next;
    novo->next = aux->next;
    aux->next = novo;
}


//6. ESCREVER FICHEIROS DE SAÍDA
void escrever_despesas_totais(node_despesa_total *novo, char *nome) {
    FILE *fptr;
    fptr = fopen(nome, "w");
    if (fptr == NULL) {
        fprintf(stderr, "Erro a abrir ficheiro\n");
        exit(1);
    } else {
        while (novo != NULL) {
            if (novo->despesa.total == 0) novo = novo->next;
            fprintf(fptr, "VALOR TOTAL DA DESPESA %s: %d\n", novo->despesa.despesa, novo->despesa.total);
            novo = novo->next;
        }
    }
    fclose(fptr);
}

void escrever_desvio_orcamento(node_desvio_orcamento *novo, char *nome2) {
    int desvio_global = 0;
    FILE *fptr;
    fptr = fopen(nome2, "w");
    if (fptr == NULL) {
        fprintf(stderr, "Erro a abrir ficheiro\n");
        exit(1);
    } else {
        while (novo != NULL) {
            if (novo->desvioOrc.original == 0) novo = novo->next;
            int despesa_total = novo->desvioOrc.original + novo->desvioOrc.desvio;
            int percentagem = (((despesa_total) * 100) / novo->desvioOrc.original) - 100;
            fprintf(fptr, "ORCAMENTO INICIAL DE %s: %d\tORCAMENTO FINAL: %d\t\tDESVIO:%d (+%d%%)\n",
                    novo->desvioOrc.orc, novo->desvioOrc.original, despesa_total, novo->desvioOrc.desvio, percentagem);
            desvio_global += novo->desvioOrc.desvio;
            novo = novo->next;
        }
    }
    fprintf(fptr, "\nDESVIO GLOBAL: %d\n", desvio_global);
    fclose(fptr);
}

int get_one_line(FILE * fich, char *linha, int lim) {
    int c, i;
    i = 0;
    while (isspace(c = fgetc(fich)));
    if (c != EOF) {
        if (!iscntrl(c)) linha[i++] = c;
    } else
        return c;

    for (; i < lim - 1;) {
        c = fgetc(fich);
        if (c == EOF)
            return c;
        if (c == '\n')
            break;
        if (!iscntrl(c)) linha[i++] = c;
    }
    linha[i] = 0;
    while ((c != EOF) && (c != '\n'))
        c = fgetc(fich);
    return c;
}