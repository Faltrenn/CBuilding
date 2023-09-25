#include <stdio.h>
#include <stdlib.h>
#include "validar.h"
#include "materiais.h"
#include "formatacoes.h"

void tela_menu_material(void) {
    int op = -1;
    while (op != 0) {
        system("clear||cls");
        printf("\n");
        cabecalho2("Modulo Materiais de Construcao");
        printf("///                                                                         ///\n");
        printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
        printf("///            = = = = = = = = Menu Materiais  = = = = = = = =              ///\n");
        printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
        printf("///                                                                         ///\n");

        char* opcoes[] = {
            "Cadastrar material",
            "Pesquisar material",
            "Atualizar material",
            "Excluir material",
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
            tela_cadastrar_material();
            break;
        case 2:
            tela_pesquisar_material();
            break;
        case 3:
            tela_alterar_material();
            break;
        case 4:
            tela_excluir_material();
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção invalida!\n");
        }
    }
}


void tela_cadastrar_material(void) {
    system("clear||cls");
    printf("\n");
    cabecalho2("Gestao de materiais de construcao");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = Cadastrar Material  = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Nome:                                                        ///\n");
    printf("///            Marca:                                                       ///\n");
    printf("///            Categoria:                                                   ///\n");
    printf("///            Quantidade:                                                  ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


void tela_pesquisar_material(void) {
    system("clear||cls");
    printf("\n");
    cabecalho2("Gestao de materiais de construcao");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = Pesquisar Material  = = = = = = =              ///\n");
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


void tela_alterar_material(void) {
    system("clear||cls");
    printf("\n");
    cabecalho2("Gestao de materiais de construcao");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = Alterar Material  = = = = = = = =              ///\n");
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


void tela_excluir_material(void) {
    system("clear||cls");
    printf("\n");
    cabecalho2("Gestao de materiais de construcao");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = Excluir Material  = = = = = = = =              ///\n");
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


void tela_relatorios(void) {
    char op = -1;
    system("clear||cls");
    printf("\n");
    cabecalho2("Gestao de materiais de construcao");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = = Relatórios  = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Materiais                                                 ///\n");
    printf("///            2. Clientes                                                  ///\n");
    printf("///            3. Vendas                                                    ///\n");
    printf("///            0. Voltar ao menu anterior                                   ///\n");
    printf("///                                                                         ///\n");
    printf("///            Escolha a opção desejada: ");
    scanf("%c", &op);
    getchar();
}