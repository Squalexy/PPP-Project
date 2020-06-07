#include "Declaracoes.h"

// --------------------------- LISTAS --------------------------- //

static node_orcamento *lista_orcamentos;
static node_despesa *lista_despesas;
static node_despesa_total *lista_despesas_totais;
static node_desvio_orcamento *lista_desvio_orcamento;

void create_list_orcamento() {
    lista_orcamentos = calloc(sizeof(node_orcamento), 1); //Cria uma lista
}

void create_list_despesa() {
    lista_despesas = calloc(sizeof(node_despesa), 1);
}

void create_list_despesa_total() {
    lista_despesas_totais = calloc(sizeof(node_despesa_total), 1);
}

void create_list_desvio_orcamento() {
    lista_desvio_orcamento = calloc(sizeof(node_desvio_orcamento), 1);
}

// ---------- FUNCOES --------- //
//1. ORÇAMENTO

void input_orcamento() {
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
    inserir_orcamento(tipo, preco);
}

void inserir_orcamento(char *tipo, int valor) {
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

void print_orcamento() {
    node_orcamento *lista = lista_orcamentos;
    if (lista->orc.valor == 0) lista = lista->next; //calloc cria um 0 na lista
    while (lista != NULL) {
        printf("TIPO: %s - ORÇAMENTO: %d \n", lista->orc.tipo, lista->orc.valor);
        lista = lista->next;
    }
}

void atualizar_lista(char *tipo, int valor) {
    node_orcamento *lista = lista_orcamentos;
    while (lista != NULL) {
        if (strcasecmp(lista->orc.tipo, tipo) == 0) {
            lista->orc.valor = valor;
            break;
        }
        lista = lista->next;
    }
}

void atualizar_orcamento() {
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
    atualizar_lista(tipo, preco);
}

//2. DESPESAS

void input_despesas() {
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
    inserir_despesa(descricao, preco, tipo);
}

void inserir_despesa(char *descricao, int preco, char *tipo) {
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

void print_despesa() {
    node_despesa *despesa = lista_despesas;
    if (despesa->orc.preco == 0) despesa = despesa->next;
    while (despesa != NULL) {
        printf("DESCRIÇÃO: %s - ORÇAMENTO: %d  - TIPO: %s\n", despesa->orc.descricao, despesa->orc.preco,
               despesa->orc.tipo);
        despesa = despesa->next;
    }
}

void atualizar_lista_despesas(char *descricao, int preco) {
    node_despesa *aux = lista_despesas;
    while (aux != NULL) {
        if (strcasecmp(aux->orc.descricao, descricao) == 0) {
            aux->orc.preco = preco;
            break;
        }
        aux = aux->next;
    }
}

void atualizar_despesas() {
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
    atualizar_lista_despesas(descricao, preco);
}

//3. FICHEIROS

void ler_orcamento() {
    FILE *fptr;
    fptr = fopen("Orcamento.data", "rb");
    if (fptr == NULL) {
        fprintf(stderr, "Error opening file\n");
        exit(1);
    }
    node_orcamento *aux = calloc(sizeof(node_orcamento), 1);
    limpar_orcamentos();
    while (fread(aux, sizeof(node_orcamento), 1, fptr)) {
        inserir_orcamento(aux->orc.tipo, aux->orc.valor);
    }
    free(aux);
    fclose(fptr);
}

void escrever_orcamento() {
    FILE *fptr;
    node_orcamento *aux = lista_orcamentos;
    fptr = fopen("Orcamento.data", "wb");
    if (fptr == NULL) {
        fprintf(stderr, "\nError opening file\n");
        exit(1);
    } else {
        while (aux != NULL) {
            if (aux->orc.valor == 0) aux = aux->next;
            fwrite(aux, sizeof(node_orcamento), 1, fptr);
            aux = aux->next;
        }
    }
    fclose(fptr);
}

void ler_despesas() {
    FILE *fptr;
    fptr = fopen("Despesas.data", "rb");
    if (fptr == NULL) {
        fprintf(stderr, "Error opening file\n");
        exit(1);
    }
    node_despesa *aux = calloc(sizeof(node_despesa), 1);
    limpar_despesas();
    while (fread(aux, sizeof(node_despesa), 1, fptr)) {
        inserir_despesa(aux->orc.descricao, aux->orc.preco, aux->orc.tipo);
    }
    free(aux);
    fclose(fptr);
}

void escrever_despesas() {
    node_despesa *aux = lista_despesas;
    FILE *fptr;
    fptr = fopen("Despesas.data", "wb");
    if (fptr == NULL) {
        fprintf(stderr, "\nError opening file\n");
        exit(1);
    } else {
        while (aux != NULL) {
            if (aux->orc.preco == 0) aux = aux->next;
            fwrite(aux, sizeof(node_despesa), 1, fptr);
            aux = aux->next;
        }
    }
    fclose(fptr);
}

//Funções para limpar orçamentos e listas cada vez que os ler para não duplicá-los ao fazer print
//Pode acontecer eu ler um ficheiro, adicionar um elemento à lista, acrescentá-lo ao ficheiro e ler novamente o ficheiro
//Como não limpei a lista, ele iria ler o ficheiro antigo (sem o elemento adicionado) e o ficheiro novo, ou seja, iria duplicar os elementos já existentes
void limpar_orcamentos() {
    node_orcamento *lista = lista_orcamentos;
    node_orcamento *copia = lista;
    lista = lista->next;
    copia->next = NULL;
    while (lista != NULL) {
        node_orcamento *next = lista->next;
        free(lista);
        lista = next;
    }
}

void limpar_despesas() {
    node_despesa *despesa = lista_despesas;
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
void despesas_totais() {
    node_despesa *despesa = lista_despesas;
    int contagem = 0;
    if (despesa->orc.preco == 0) despesa = despesa->next;
    while (despesa != NULL && despesa->next != NULL) {
        if (despesa->next == NULL) {
            contagem += despesa->orc.preco;
            printf("Despesas totais do tipo %s : %d\n", despesa->orc.tipo, contagem);
            inserir_despesas_totais(despesa, contagem);
        } else if (strcasecmp(despesa->orc.tipo, despesa->next->orc.tipo) ==
                   0) { //se o próximo elemento for o mesmo tipo
            contagem += despesa->orc.preco;
        } else {//se o próximo elemento for um tipo diferente
            contagem += despesa->orc.preco;
            printf("Despesas totais do tipo %s : %d\n", despesa->orc.tipo, contagem);
            inserir_despesas_totais(despesa, contagem);
            contagem = 0;
        }
        despesa = despesa->next;
    }
}

//Aloca memória a uma nova lista onde inserir tipo da despesa (ex: ALIMENTAÇÃO) e o valor total das despesas desse tipo
void inserir_despesas_totais(node_despesa *despesa, int contagem) {
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
void desvio_despesas() {
    node_orcamento *l_orc = lista_orcamentos;
    node_despesa_total *l_desp_tot = lista_despesas_totais;
    node_desvio_orcamento *l_desv_orc = lista_desvio_orcamento;
    if (l_orc->orc.valor == 0) l_orc = l_orc->next;
    if (l_desp_tot->despesa.total == 0) l_desp_tot = l_desp_tot->next;
    printf("Os seguintes orçamentos sofreram um l_desv_orc superior a 10%%:\n");

    while (l_desp_tot != NULL && l_orc != NULL) {
        int desvio_despesa;
        int percentagem = (((l_desp_tot->despesa.total) * 100) / l_orc->orc.valor) - 100;
        if ((l_desp_tot->despesa.total - l_desv_orc->desvioOrc.desvio) >
            l_orc->orc.valor) { //ex: se despesas220-desvio20 > orc200
            printf("Tipo: %s - Valor: %d - Desvio: %d%% (+%d) - Orçamento inicial: %d\n", l_orc->orc.tipo,
                   l_desp_tot->despesa.total, percentagem,
                   l_desp_tot->despesa.total - l_orc->orc.valor, l_orc->orc.valor);
            desvio_despesa = l_desp_tot->despesa.total - l_orc->orc.valor;
            inserir_desvio_orcamento(desvio_despesa);
        }
        l_orc = l_orc->next;
        l_desp_tot = l_desp_tot->next;
    }
}

void inserir_desvio_orcamento(int desvio_despesa) {
    node_orcamento *lista = lista_orcamentos;
    node_desvio_orcamento *novo = calloc(sizeof(node_desvio_orcamento), 1);
    strcpy(novo->desvioOrc.orc, lista->orc.tipo);
    novo->desvioOrc.original = lista->orc.valor;
    novo->desvioOrc.desvio = desvio_despesa;
    node_desvio_orcamento *aux = lista_desvio_orcamento;
    while (aux->next != NULL) aux = aux->next;
    novo->next = aux->next;
    aux->next = novo;
}


//6. ESCREVER FICHEIROS DE SAÍDA
void escrever_despesas_totais(char *nome) {
    node_despesa_total *lista = lista_despesas_totais;
    FILE *fptr;
    fptr = fopen(nome, "w");
    if (fptr == NULL) {
        fprintf(stderr, "Erro a abrir ficheiro\n");
        exit(1);
    } else {
        while (lista != NULL) {
            if (lista->despesa.total == 0) lista = lista->next;
            fprintf(fptr, "VALOR TOTAL DA DESPESA %s: %d\n", lista->despesa.despesa, lista->despesa.total);
            lista = lista->next;
        }
    }
    fclose(fptr);
}

void escrever_desvio_orcamento(char *nome2) {
    node_desvio_orcamento *lista = lista_desvio_orcamento;
    int desvio_global = 0;
    FILE *fptr;
    fptr = fopen(nome2, "w");
    if (fptr == NULL) {
        fprintf(stderr, "Erro a abrir ficheiro\n");
        exit(1);
    } else {
        while (lista != NULL) {
            if (lista->desvioOrc.original == 0) lista = lista->next;
            int despesa_total = lista->desvioOrc.original + lista->desvioOrc.desvio;
            int percentagem = (((despesa_total) * 100) / lista->desvioOrc.original) - 100;
            fprintf(fptr, "ORCAMENTO INICIAL DE %s: %d\tORCAMENTO FINAL: %d\t\tDESVIO:%d (+%d%%)\n",
                    lista->desvioOrc.orc, lista->desvioOrc.original, despesa_total, lista->desvioOrc.desvio, percentagem);
            desvio_global += lista->desvioOrc.desvio;
            lista = lista->next;
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