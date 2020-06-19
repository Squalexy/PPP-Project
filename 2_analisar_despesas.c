#include "Declaracoes.h"

int main() {

    int validade;
    char introduzir[MAXTAMANHO];
    int input = 0;
    create_list_orcamento();
    create_list_despesa();
    create_list_despesa_total();
    create_list_desvio_orcamento();

    FILE *config = NULL;
    char ficheiro1[MAXTAMANHO];
    char ficheiro2[MAXTAMANHO];

    config = fopen("config.txt", "r");
    get_one_line(config, ficheiro1, MAXTAMANHO);
    get_one_line(config, ficheiro2, MAXTAMANHO);

    while (1) {
        printf("Escolha uma opção: \n");
        printf("1 - Calcular despesas totais\n");
        printf("2 - Calcular desvio de orçamento\n");
        printf("3 - Print despesas totais\n");
        printf("4 - Print desvio de orçamento\n");
        printf("5 - Guardar despesas totais num ficheiro\n");
        printf("6 - Guardar desvio de orçamento num ficheiro\n");
        printf("7 - Sair\n");
        while (fgets(introduzir, MAXTAMANHO, stdin)) {
            validade = 1;
            for (int i = 0; i < strlen(introduzir) - 1; i++) {
                if (introduzir[i] < '0' || introduzir[i] > '9') {
                    validade = 0;
                    break;
                }
            }
            if (validade == 1) break;
            printf("Opção inválida. Repita a escolha. \n");
            printf("Escolha uma opção: \n");
            printf("1 - Calcular despesas totais\n");
            printf("2 - Calcular desvio de orçamento\n");
            printf("3 - Print despesas totais\n");
            printf("4 - Print desvio de orçamento\n");
            printf("5 - Guardar despesas totais num ficheiro\n");
            printf("6 - Guardar desvio de orçamento num ficheiro\n");
            printf("7 - Sair\n");
        }
        input = (int) strtol(introduzir, NULL, 10);
        switch (input) {
            case 1:
                ler_despesas();
                despesas_totais();
                break;
            case 2:
                ler_orcamento();
                desvio_despesas();
                break;
            case 3:
                print_despesas_totais();
                break;
            case 4:
                printf("Os seguintes orçamentos sofreram um l_desv_orc superior a 10%%:\n");
                print_desvio_orcamento();
                break;
            case 5:
                escrever_despesas_totais(ficheiro1);
                break;
            case 6:
                escrever_desvio_orcamento(ficheiro2);
                break;
            case 7:
                limpar_orcamentos(1);
                limpar_despesas(1);
                limpar_despesas_totais(1);
                limpar_desvio_orcamento(1);
                return 0;

            default:
                printf("Opção inválida. Repita a escolha. \n");
        }
    }
}