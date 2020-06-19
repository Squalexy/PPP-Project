//STRUCT do ORÇAMENTO
typedef struct _orcamentado {
    char tipo[MAXTAMANHO];
    int valor;
} orcamentado;

//LISTA dos ORÇAMENTOS
typedef struct node_orcamento {
    orcamentado orc;
    struct node_orcamento *next;
} node_orcamento;

//STRUCT da DESPESA
typedef struct _despesas {
    char descricao[MAXTAMANHO];
    int preco;
    char tipo[MAXTAMANHO];
} despesas;

//LISTA das DESPESAS
typedef struct node_despesa {
    despesas orc;
    struct node_despesa *next;
} node_despesa;

//STRUCT da DESPESA TOTAL
typedef struct _despesa_total {
    char despesa[MAXTAMANHO];
    int total;
} despesa_total;

//LISTA das DESPESAS TOTAIS
typedef struct node_despesa_total {
    despesa_total despesa;
    struct node_despesa_total *next;
} node_despesa_total;

//STRUCT do DESVIO DE ORÇAMENTO
typedef struct _desvio_orcamento {
    char orc[MAXTAMANHO];
    int original;
    int desvio;
} desvio_orcamento;

//LISTA dos DESVIOS DE ORÇAMENTOS
typedef struct node_desvio_orcamento {
    desvio_orcamento desvioOrc;
    struct node_desvio_orcamento *next;
} node_desvio_orcamento;