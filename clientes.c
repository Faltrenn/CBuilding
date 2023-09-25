#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"
#include "formatacoes.h"
#include "validar.h"


void tela_menu_cliente(void) {
    int op = -1;
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
            "Cadastrar cliente",
            "Pesquisar cliente",
            "Atualizar cliente",
            "Excluir cliente",
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
            tela_cadastrar_cliente();
            break;
        case 2:
            tela_pesquisar_cliente();
            break;
        case 3:
            tela_alterar_cliente();
            break;
        case 4:
            tela_excluir_cliente();
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção invalida!\n");
        }
    }
}


void tela_cadastrar_cliente(void) {
    system("clear||cls");
    printf("\n");
    cabecalho2("Gestao de materiais de construcao");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = Cadastrar Cliente = = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Nome:                                                        ///\n");
    printf("///            CPF:                                                         ///\n");
    printf("///            Telefone:                                                   ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


void tela_pesquisar_cliente(void) {
    system("clear||cls");
    printf("\n");
    cabecalho2("Gestao de materiais de construcao");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = Pesquisar Cliente = = = = = = = =              ///\n");
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


void tela_alterar_cliente(void) {
    system("clear||cls");
    printf("\n");
    cabecalho2("Gestao de materiais de construcao");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = Alterar Cliente = = = = = = = = =              ///\n");
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


void tela_excluir_cliente(void) {
    system("clear||cls");
    printf("\n");
    cabecalho2("Gestao de materiais de construcao");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = Excluir Cliente = = = = = = = = =              ///\n");
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