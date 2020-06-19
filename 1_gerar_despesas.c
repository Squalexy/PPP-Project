#include "Declaracoes.h"

int main() {

    int validade;
    char introduzir[MAXTAMANHO];
    int input = 0;
    create_list_orcamento();
    create_list_despesa();

    while (1) {
        printf("\nEscolha uma opção: \n");
        printf("1 - Ler ficheiro de orçamento\n");
        printf("2 - Ler ficheiro de despesas\n");
        printf("3 - Introduzir orçamento\n");
        printf("4 - Introduzir despesas\n");
        printf("5 - Atualizar orçamento\n");
        printf("6 - Atualizar despesas\n");
        printf("7 - Print orçamento\n");
        printf("8 - Print despesas\n");
        printf("9 - Guardar orçamento\n");
        printf("10 - Guardar despesas\n");
        printf("11 - Sair\n");
        while(fgets(introduzir, MAXTAMANHO, stdin)){
            validade = 1;
            for (int i = 0; i < strlen(introduzir) - 1; i++){
                if (introduzir[i] < '0' || introduzir[i] > '9'){
                    validade = 0;
                    break;
                }
            }
            if (validade == 1) break;
            printf("\nEscolha uma opção: \n");
            printf("1 - Ler ficheiro de orçamento\n");
            printf("2 - Ler ficheiro de despesas\n");
            printf("3 - Introduzir orçamento\n");
            printf("4 - Introduzir despesas\n");
            printf("5 - Atualizar orçamento\n");
            printf("6 - Atualizar despesas\n");
            printf("7 - Print orçamento\n");
            printf("8 - Print despesas\n");
            printf("9 - Guardar orçamento\n");
            printf("10 - Guardar despesas\n");
            printf("11 - Sair\n");
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
                atualizar_orcamento();
                break;
            case 6:
                atualizar_despesas();
                break;
            case 7:
                print_orcamento();
                break;
            case 8:
                print_despesa();
                break;
            case 9:
                escrever_orcamento();
                break;
            case 10:
                escrever_despesas();
                break;
            case 11:
                limpar_despesas(1);
                limpar_orcamentos(1);
                return 0;
            default:
                printf("Opção inválida. Repita a escolha. \n");
        }
    }
}







