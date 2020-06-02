typedef struct _orcamentado {
    char tipo[MAXTAMANHO];
    int valor;
} orcamentado;

//Lista dos orçamentos
typedef struct node_orcamento {
    orcamentado orc;
    struct node_orcamento *next;
} node_orcamento;

typedef struct _despesas {
    char descricao[MAXTAMANHO];
    int preco;
    char tipo[MAXTAMANHO];
} despesas;

//Lista das despesas
typedef struct node_despesa {
    despesas orc;
    struct node_despesa *next;
} node_despesa;

typedef struct _despesa_total {
    char despesa[MAXTAMANHO];
    int total;
} despesa_total;

//Lista das despesas totais calculadas
typedef struct node_despesa_total {
    despesa_total despesa;
    struct node_despesa_total *next;
} node_despesa_total;

typedef struct _desvio_orcamento {
    char orc[MAXTAMANHO];
    int original;
    int desvio;
} desvio_orcamento;

//Lista dos orçamentos com desvio superior a 10%
typedef struct node_desvio_orcamento {
    desvio_orcamento desvioOrc;
    struct node_desvio_orcamento *next;
} node_desvio_orcamento;