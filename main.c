#include "Declaracoes.h"

#define MAXTAMANHO 50


int main() {
    int input = 0;
    node_orcamento* lista_orcamentos = create_list_orcamento(); //Cria desde já uma primeira lista, antes do programa começar a funcionar
    node_despesa* lista_despesas = create_list_despesa();
    while(input != 11){
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
        scanf("%d", &input);

        switch(input){
            case 1:
                ler_orcamento(lista_orcamentos);
                break;
            case 2:
                ler_despesas(lista_despesas);
                break;
            case 3:
                input_orcamento(lista_orcamentos);
                break;
            case 4:
                input_despesas(lista_despesas);
                break;
            case 5:
                atualizar_orcamento(lista_orcamentos);
                break;
            case 6:
                atualizar_despesas(lista_despesas);
                break;
            case 7:
                print_orcamento(lista_orcamentos);
                break;
            case 8:
                print_despesa(lista_despesas);
                break;
            case 9:
                escrever_orcamento(lista_orcamentos);
                break;
            case 10:
                escrever_despesas(lista_despesas);
                break;
            case 11:
                limpar_despesas(lista_despesas);
                limpar_orcamentos(lista_orcamentos);
                free(lista_despesas);
                free(lista_orcamentos);
                return 0;
            default:
                printf("Opção inválida. Repita a escolha. \n");
        }
    }
    return 0;
}

//Função para introduzir um orçamento


/*

//Função para introduzir despesas
input_despesas(){
}

//Função para escrever no ficheiro binário o orçamento e as despesas
write_to_binary_file()

//Função para ler ficheiro binário
read_from_binary_file(){
}*/

//Função para imprimir lista de orçamento


/*
//Função para imprimir lista de despesas
lista_desp(){
}*/


// --------------------- FUNÇÕES --------------------- //

//1. Inserir um orçamento






