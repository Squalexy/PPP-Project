#include "Declaracoes.h"

int main() {

    int validade;
    char introduzir[MAXTAMANHO];
    int input = 0;
    create_list_orcamento();
    create_list_despesa();

    while (1) {
        printf("\nEscolha uma opção: \n");
        printf("1.\tAbrir ficheiro de orçamento\n");
        printf("2.\tAbrir ficheiro de despesas\n");
        printf("3.\tIntroduzir orçamento\n");
        printf("4.\tIntroduzir despesa\n");
        printf("5.\tRemover orçamento\n");
        printf("6.\tRemover despesa\n");
        printf("7.\tAtualizar orçamento\n");
        printf("8.\tAtualizar despesa\n");
        printf("9.\tPrint orçamentos\n");
        printf("10.\tPrint despesas\n");
        printf("11.\tGuardar orçamentos num ficheiro\n");
        printf("12.\tGuardar despesas num ficheiro\n");
        printf("13.\tSair\n");
        while (fgets(introduzir, MAXTAMANHO, stdin)) {
            validade = 1;
            for (int i = 0; i < strlen(introduzir) - 1; i++) {
                if (introduzir[i] < '0' || introduzir[i] > '9') {
                    validade = 0;
                    break;
                }
            }
            if (validade == 1) break;
            fprintf(stderr, "\nOpção inválida. Repita a escolha\n.");
            printf("\nEscolha uma opção: \n");
            printf("1.\tAbrir ficheiro de orçamento\n");
            printf("2.\tAbrir ficheiro de despesas\n");
            printf("3.\tIntroduzir orçamento\n");
            printf("4.\tIntroduzir despesa\n");
            printf("5.\tRemover orçamento\n");
            printf("6.\tRemover despesa\n");
            printf("7.\tAtualizar orçamento\n");
            printf("8.\tAtualizar despesa\n");
            printf("9.\tPrint orçamentos\n");
            printf("10.\tPrint despesas\n");
            printf("11.\tGuardar orçamentos num ficheiro\n");
            printf("12.\tGuardar despesas num ficheiro\n");
            printf("13.\tSair\n");
        }
        input = (int) strtol(introduzir, NULL, 10);
        switch (input) {
            case 1:
                ler_orcamento();
                break;
            case 2:
                ler_despesas();
                break;
            case 3:
                input_orcamento();
                break;
            case 4:
                input_despesas();
                break;
            case 5:
                input_remover_orcamento();
                break;
            case 6:
                input_remover_despesas();
                break;
            case 7:
                atualizar_orcamento();
                break;
            case 8:
                atualizar_despesas();
                break;
            case 9:
                print_orcamento();
                break;
            case 10:
                print_despesa();
                break;
            case 11:
                escrever_orcamento();
                break;
            case 12:
                escrever_despesas();
                break;
            case 13:
                limpar_despesas(1);
                limpar_orcamentos(1);
                return 0;

            default:
                printf("Opção inválida. Repita a escolha. \n");
        }
    }
}







