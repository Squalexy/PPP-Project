#include "Declaracoes.h"

int main() {

    char introduzir[MAXTAMANHO];
    int input = 0;
    node_orcamento *lista_orcamentos = create_list_orcamento(); //Cria desde já uma primeira lista, antes do programa começar a funcionar
    node_despesa *lista_despesas = create_list_despesa();
    node_despesa_total *lista_despesas_totais = create_list_despesa_total();
    node_desvio_orcamento *lista_desvio_orcamento = create_list_desvio_orcamento();

    FILE* config = NULL;
    char ficheiro1[MAXTAMANHO];
    char ficheiro2[MAXTAMANHO];

    config = fopen("config.txt","r");
    get_one_line(config,ficheiro1,MAXTAMANHO);
    get_one_line(config,ficheiro2,MAXTAMANHO);

    while (input != 3) {
        printf("Escolha o ficheiro que pretende abrir:\n");
        printf("1 - Orçamento\n");
        printf("2 - Despesas\n");
        printf("3 - Sair\n");

        fgets(introduzir, MAXTAMANHO, stdin);
        input = (int) strtol(introduzir, NULL, 10);

        switch (input) {
            case 1:
                ler_orcamento(lista_orcamentos);
                print_orcamento(lista_orcamentos);
                break;
            case 2:
                ler_despesas(lista_despesas);
                ler_orcamento(lista_orcamentos);
                //print_despesa(lista_despesas);
                despesas_totais(lista_despesas, lista_despesas_totais);
                desvio_despesas(lista_desvio_orcamento, lista_orcamentos, lista_despesas_totais);
                escrever_despesas_totais(lista_despesas_totais, ficheiro1);
                escrever_desvio_orcamento(lista_desvio_orcamento, ficheiro2);
                break;
            case 3:
                //limpar_despesas(lista_despesas);
                //limpar_orcamentos(lista_orcamentos);
                //free(lista_despesas);
                //free(lista_orcamentos);
                return 0;
            default:
                printf("Opção inválida. Repita a escolha. \n");
        }
    }
}