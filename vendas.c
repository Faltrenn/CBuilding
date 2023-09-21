#include <stdio.h>
#include <stdlib.h>
#include "vendas.h"
#include "formatacoes.h"
#include "validar.h"


void tela_menu_venda(void) {
    int op;
    while(op != 0) {
        system("clear||cls");
        printf("\n");
        cabecalho2("Modulo Materiais de Construcao");
        printf("///                                                                         ///\n");
        printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
        printf("///            = = = = = = = = Menu Materiais  = = = = = = = =              ///\n");
        printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
        printf("///                                                                         ///\n");

        char* opcoes[] = {
            "Cadastrar venda",
            "Pesquisar venda",
            "Atualizar venda",
            "Excluir venda",
            NULL
        };

        mostrar_opcoes(opcoes, 73);
        
        printf("///            0. Voltar ao menu anterior                                   ///\n");
        printf("///                                                                         ///\n");
        op = pegar_inteiro("///            Escolha a opção desejada: ", 1, "Opção inválida!");
        printf("///                                                                         ///\n");
        printf("///                                                                         ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("\n");

        switch (op) {
        case 1:
            tela_cadastrar_venda();
            break;
        case 2:
            tela_pesquisar_venda();
            break;
        case 3:
            tela_alterar_venda();
            break;
        case 4:
            tela_excluir_venda();
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção invalida!\n");
        }
    }
}


void tela_cadastrar_venda(void) {
    system("clear||cls");
    printf("\n");
    cabecalho2("Gestao de materiais de construcao");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Cadastrar Venda = = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Comprador:                                                   ///\n");
    printf("///            Produto:                                                     ///\n");
    printf("///            Quantidade:                                                  ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


void tela_pesquisar_venda(void) {
    system("clear||cls");
    printf("\n");
    cabecalho2("Gestao de materiais de construcao");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Pesquisar Venda = = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe o id:                                                ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


void tela_alterar_venda(void) {
    system("clear||cls");
    printf("\n");
    cabecalho2("Gestao de materiais de construcao");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Alterar Venda = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe o id:                                                ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


void tela_excluir_venda(void) {
    system("clear||cls");
    printf("\n");
    cabecalho2("Gestao de materiais de construcao");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Excluir Venda = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe o id:                                                ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}