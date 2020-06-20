//PROGRAMA 1 - "1_gerar_despesas.c"

//O objetivo é gerar os 2 dados de entrada para serem usados no programa principal (programa 2):
//uma lista de orçamentos e uma lista de despesas.

//As listas são listas ligadas simples, baseadas em gestão dinâmica de memória.
//As listas são inicializadas a NULL através do uso de calloc (escolhido por ser mais prático para este projeto).

//Através de um menu de inputs, o utilizador escolhe a opcão que pretende para gerar ou alterar os dados de entrada.
//O utilizador pode escolher abrir um ficheiro binário já existente, criar um novo ficheiro binário de raíz, acrescentar elementos,
//retirar elementos, atualizar valores, entre outras coisas indicadas no menu de inputs.

//Uma vez que o utilizador criou os ficheiros binários (dados de entrada), ele prossegue para executar o programa 2.

//São usados 2 headers para o programa 1 e programa 2:
//"Declaracoes.h", onde são declaradas as funções, organizadas pelos seus respetivos grupos (para melhor visualização);
//"Estruturas.h", onde são criadas as estruturas e listas;

//Um dos problemas que se podem apresentar é o utilizador introduzir orçamentos ou despesas com valores que não sejam
//de tipo inteiro ou introduzir nomes que não sejam de tipo string. Nesse caso, o programa não irá comportar-se da forma
//inesperada.

//Caso o utilizador escolha uma opção sem ter uma lista válida para a efetuar, o programa avisa o utilizador através de
//um erro e redireciona-o para o menu de inputs. No caso do utilizador abrir um ficheiro binário vazio, o programa pára
//e o utilizador deve voltar a corrê-lo.
//Por exemplo, se o utilizador correr o programa e quiser logo fazer print de uma lista de orçamentos, sem ter sequer
//uma lista que contenha algum orçamento, o programa irá avisá-lo de que a lista que pretende ler encontra-se vazia.


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
            fprintf(stderr, "\nOpção inválida. Repita a escolha.\n");
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
                fprintf(stderr, "\nOpção inválida. Repita a escolha.\n");
        }
    }
}