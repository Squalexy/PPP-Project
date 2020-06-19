#include "Declaracoes.h"

static node_orcamento *lista_orcamentos;
static node_despesa *lista_despesas;
static node_despesa_total *lista_despesas_totais;
static node_desvio_orcamento *lista_desvio_orcamento;

//Cria as listas, inicializando-as a NULL
void create_list_orcamento() {
    lista_orcamentos = calloc(sizeof(node_orcamento), 1);
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


//1. ORÇAMENTO
//Pede ao utilizador input de um orçamento, para depois inseri-lo na lista de orçamentos.
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

//Insere o orçamento na lista de orçamentos, por ordem alfabética de tipo de orçamento.
//É usado em conjunção com a função input_orcamento.
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

//Faz print de todos os orçamentos da lista de orçamentos.
void print_orcamento() {
    node_orcamento *lista = lista_orcamentos;
    if (lista->orc.valor == 0) lista = lista->next; //calloc cria um 0 na lista
    while (lista != NULL) {
        printf("TIPO: %s - ORÇAMENTO: %d \n", lista->orc.tipo, lista->orc.valor);
        lista = lista->next;
    }
}

//Pede ao utilizador dois inputs: o orçamento a ser atualizado e o valor que irá substituir o atual.
//De seguida, faz essa atualização.
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
    atualizar_lista_orcamento(tipo, preco);
}

//Atualiza o valor do orçamento na lista de orçamentos.
//É usado em conjunção com a função atualizar_orcamento.
void atualizar_lista_orcamento(char *tipo, int valor) {
    node_orcamento *lista = lista_orcamentos;
    while (lista != NULL) {
        if (strcasecmp(lista->orc.tipo, tipo) == 0) {
            lista->orc.valor = valor;
            break;
        }
        lista = lista->next;
    }
}


//2. DESPESAS
//Pede ao utilizador input de uma despesa, para depois inseri-lana lista de despesas.
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

//Insere a despesa na lista de despesas, por ordem alfabética de tipo de despesa.
//É usado em conjunção com a função input_despesas.
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

//Faz print de todas as despesas da lista de despesas.
void print_despesa() {
    node_despesa *despesa = lista_despesas;
    if (despesa->orc.preco == 0) despesa = despesa->next;
    while (despesa != NULL) {
        printf("DESCRIÇÃO: %s - ORÇAMENTO: %d  - TIPO: %s\n", despesa->orc.descricao, despesa->orc.preco,
               despesa->orc.tipo);
        despesa = despesa->next;
    }
}

//Pede ao utilizador dois inputs: a despesa a ser atualizada e o valor que irá substituir o atual.
//De seguida, faz essa atualização.
void atualizar_despesas() {
    char descricao[MAXTAMANHO];
    char valor[MAXTAMANHO];
    int preco;
    printf("Nome da descrição que quer atualizar: \n");
    fgets(descricao, MAXTAMANHO, stdin);
    descricao[strlen(descricao) - 1] = '\0';
    printf("Valor da descrição que quer atualizar: \n");
    fgets(valor, MAXTAMANHO, stdin);
    valor[strlen(valor) - 1] = '\0';
    preco = (int) strtol(valor, NULL, 0);
    atualizar_lista_despesas(descricao, preco);
}

//Atualiza o valor da despesa na lista de despesas.
//É usado em conjunção com a função atualizar_despesas.
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


//3. FICHEIROS
//Pede o nome de um ficheiro de orçamento existente.
//Abre e lê o ficheiro, inserindo o seu conteúdo numa lista de orçamentos.
void ler_orcamento() {
    char nome_fich[MAXTAMANHO];
    FILE *fptr = NULL;
    while (fptr == NULL) {
        printf("Insira o nome do FICHEIRO BINÁRIO de ORÇAMENTOS a ser ABERTO: ");
        if (get_one_line(stdin, nome_fich, MAXTAMANHO) == EOF) return;
        fptr = fopen(nome_fich, "rb");
        if (fptr == NULL) fprintf(stderr, "Ficheiro não existe. \n");
    }
    node_orcamento *aux = calloc(sizeof(node_orcamento), 1);
    limpar_orcamentos(0);
    while (fread(aux, sizeof(node_orcamento), 1, fptr)) {
        inserir_orcamento(aux->orc.tipo, aux->orc.valor);
    }
    free(aux);
    fclose(fptr);
}

//Pega na lista de orçamentos e escreve o seu conteúdo para um ficheiro.
//O nome do ficheiro é à escolha do utilizador.
void escrever_orcamento() {
    FILE *fptr = NULL;
    node_orcamento *aux = lista_orcamentos;
    char nome_fich[MAXTAMANHO];
    while (fptr == NULL) {
        printf("Insira o nome do FICHEIRO BINÁRIO de ORÇAMENTOS a ser ESCRITO: ");
        if (get_one_line(stdin, nome_fich, MAXTAMANHO) == EOF) return;
        fptr = fopen(nome_fich, "wb");
        if (fptr == NULL) fprintf(stderr, "Erro no ficheiro. \n");
    }
    while (aux != NULL) {
        if (aux->orc.valor == 0) aux = aux->next;
        fwrite(aux, sizeof(node_orcamento), 1, fptr);
        aux = aux->next;
    }
    fclose(fptr);
}

//Pede o nome de um ficheiro de despesas existente.
//Abre e lê o ficheiro, inserindo o seu conteúdo numa lista de despesas.
void ler_despesas() {
    char nome_fich[MAXTAMANHO];
    FILE *fptr = NULL;
    while (fptr == NULL) {
        printf("Insira o nome do FICHEIRO BINÁRIO de DESPESAS a ser ABERTO: \n");
        if (get_one_line(stdin, nome_fich, MAXTAMANHO) == EOF) return;
        fptr = fopen(nome_fich, "rb");
        if (fptr == NULL) fprintf(stderr, "Ficheiro não existe. \n");
    }
    node_despesa *aux = calloc(sizeof(node_despesa), 1);
    limpar_despesas(0);
    while (fread(aux, sizeof(node_despesa), 1, fptr)) {
        inserir_despesa(aux->orc.descricao, aux->orc.preco, aux->orc.tipo);
    }
    free(aux);
    fclose(fptr);
}

//Pega na lista de despesas e escreve o seu conteúdo para um ficheiro.
//O nome do ficheiro é à escolha do utilizador.
void escrever_despesas() {
    FILE *fptr = NULL;
    node_despesa *aux = lista_despesas;
    char nome_fich[MAXTAMANHO];
    while (fptr == NULL) {
        printf("Insira o nome do FICHEIRO BINÁRIO de DESPESAS a ser ESCRITO: \n");
        if (get_one_line(stdin, nome_fich, MAXTAMANHO) == EOF) return;
        fptr = fopen(nome_fich, "wb");
        if (fptr == NULL) fprintf(stderr, "Erro no ficheiro. \n");
        while (aux != NULL) {
            if (aux->orc.preco == 0) aux = aux->next;
            fwrite(aux, sizeof(node_despesa), 1, fptr);
            aux = aux->next;
        }
    }
    fclose(fptr);
}


//4. DESPESAS TOTAIS E DESVIO DE ORÇAMENTO
//Insere na lista de despesas totais os nomes dos orçamentos e a soma total das despesas desses tipos de orçamentos.
//Compara sempre com o elemento a seguir para saber quando dar reset ao valor se o tipo de orçamento for diferente.
//(ex: ... -> ALIMENTAÇÃO -> ALIMENTAÇÃO -> TRANSPORTES (reset valor a 0) -> ...).
void despesas_totais() {
    node_despesa *despesa = lista_despesas;
    int contagem = 0;
    if (despesa->orc.preco == 0) despesa = despesa->next;
    while (despesa != NULL) {
        if (despesa->next == NULL) {
            contagem += despesa->orc.preco;
            inserir_despesas_totais(despesa, contagem);
        } else if (strcasecmp(despesa->orc.tipo, despesa->next->orc.tipo) ==
                   0) { //se o próximo elemento for o mesmo tipo
            contagem += despesa->orc.preco;
        } else { //se o próximo elemento for um tipo diferente
            contagem += despesa->orc.preco;
            inserir_despesas_totais(despesa, contagem);
            contagem = 0;
        }
        despesa = despesa->next;
    }
}

//Insere o nome de um orçamento e as suas despesas totais numa lista.
void inserir_despesas_totais(node_despesa *despesa, int contagem) {
    node_despesa_total *novo = calloc(sizeof(node_despesa_total), 1);
    strcpy(novo->despesa.despesa, despesa->orc.tipo);
    novo->despesa.total = contagem;
    node_despesa_total *aux = lista_despesas_totais;
    while (aux->next != NULL) aux = aux->next;
    novo->next = aux->next;
    aux->next = novo;
};

//Faz print de todas as despesas totais da lista de despesas totais.
void print_despesas_totais() {
    node_despesa_total *despesa_total = lista_despesas_totais;
    if (despesa_total->despesa.total == 0) despesa_total = despesa_total->next;
    while (despesa_total != NULL) {
        printf("Despesas totais do tipo %s : %d\n", despesa_total->despesa.despesa,
               despesa_total->despesa.total);
        despesa_total = despesa_total->next;
    }
}

//Guarda numa lista as despesas que têm um valor superior a 10% em relação ao orçamentado inicialmente.
//Ex: despesa 220, orçamento incial 150; desvio de 70 euros (46%);
void desvio_despesas() {
    node_orcamento *l_orc = lista_orcamentos;
    node_despesa_total *l_desp_tot = lista_despesas_totais;
    node_desvio_orcamento *l_desv_orc = lista_desvio_orcamento;
    if (l_orc->orc.valor == 0) l_orc = l_orc->next;
    if (l_desp_tot->despesa.total == 0) l_desp_tot = l_desp_tot->next;
    while (l_desp_tot != NULL && l_orc != NULL) {
        int desvio_despesa;
        desvio_despesa = l_desp_tot->despesa.total - l_orc->orc.valor;
        if (((desvio_despesa * 100) / l_orc->orc.valor) > 10) {
            inserir_desvio_orcamento(desvio_despesa, l_orc->orc);
        }
        l_orc = l_orc->next;
        l_desp_tot = l_desp_tot->next;
    }
}

//Insere numa lista as despesas que sofreram um desvio superior a 10% do orçamentado inicialmente.
void inserir_desvio_orcamento(int desvio_despesa, orcamentado o) {
    node_desvio_orcamento *novo = calloc(sizeof(node_desvio_orcamento), 1);
    strcpy(novo->desvioOrc.orc, o.tipo);
    novo->desvioOrc.original = o.valor;
    novo->desvioOrc.desvio = desvio_despesa;
    node_desvio_orcamento *aux = lista_desvio_orcamento;
    while (aux->next != NULL) aux = aux->next;
    novo->next = aux->next;
    aux->next = novo;
}

//Faz print de todos os desvios de orçamento da lista de desvio orcamento.
void print_desvio_orcamento() {
    node_desvio_orcamento *desvio = lista_desvio_orcamento;
    if (desvio->desvioOrc.desvio == 0) desvio = desvio->next;
    while (desvio != NULL) {
        int percentagem = ((desvio->desvioOrc.desvio) * 100) / desvio->desvioOrc.original;
        printf("Tipo: %s - Valor: %d - Desvio: %d%% (+%d) - Orçamento inicial: %d\n", desvio->desvioOrc.orc,
               desvio->desvioOrc.original + desvio->desvioOrc.desvio, percentagem, desvio->desvioOrc.desvio,
               desvio->desvioOrc.original);
        desvio = desvio->next;
    }
}

//5. FICHEIROS DE SAÍDA
//Pega no conteúdo da lista com as despesas totais de cada orçamento e escreve-o num ficheiro.
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

//Pega no conteúdo da lista com as despesas cujo desvio é superior a 10% e escreve-o num ficheiro.
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
            fprintf(fptr, "%s\tORCAMENTO INICIAL: %d\tORCAMENTO FINAL: %d\tDESVIO:%d (+%d%%)\n",
                    lista->desvioOrc.orc, lista->desvioOrc.original, despesa_total, lista->desvioOrc.desvio,
                    percentagem);
            desvio_global += lista->desvioOrc.desvio;
            lista = lista->next;
        }
    }
    fprintf(fptr, "\nDESVIO GLOBAL: %d\n", desvio_global);
    fclose(fptr);
}


//6. LIMPEZA DE LISTAS
//Limpa a lista de orçamentos (liberta a memória alocada).
void limpar_orcamentos(char clear_header) {
    node_orcamento *lista = lista_orcamentos;
    node_orcamento *copia = lista;
    lista = lista->next;
    copia->next = NULL;
    while (lista != NULL) {
        node_orcamento *next = lista->next;
        free(lista);
        lista = next;
    }
    if (clear_header) free(lista_orcamentos);

}

//Limpa a lista de despesas (liberta a memória alocada).
void limpar_despesas(char clear_header) {
    node_despesa *despesa = lista_despesas;
    node_despesa *copia = despesa;
    despesa = despesa->next;
    copia->next = NULL;
    while (despesa != NULL) {
        node_despesa *next = despesa->next;
        free(despesa);
        despesa = next;
    }
    if (clear_header) free(lista_orcamentos);
}

//Limpa a lista de despesas totais (liberta a memória alocada).
void limpar_despesas_totais(char clear_header) {
    node_despesa_total *despesa_total = lista_despesas_totais;
    node_despesa_total *copia = despesa_total;
    despesa_total = despesa_total->next;
    copia->next = NULL;
    while (despesa_total != NULL) {
        node_despesa_total *next = despesa_total->next;
        free(despesa_total);
        despesa_total = next;
    }
}

//Limpa a lista de desvio de orçamento (liberta a memória alocada).
void limpar_desvio_orcamento(char clear_header) {
    node_desvio_orcamento *desvio_despesas = lista_desvio_orcamento;
    node_desvio_orcamento *copia = desvio_despesas;
    desvio_despesas = desvio_despesas->next;
    copia->next = NULL;
    while (desvio_despesas != NULL) {
        node_desvio_orcamento *next = desvio_despesas->next;
        free(desvio_despesas);
        desvio_despesas = next;
    }
}


//7. FICHEIROS NO GERAL
//Função para obter a próxima linha do input.
int get_one_line(FILE *fich, char *linha, int lim) {
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