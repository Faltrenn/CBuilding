///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///             Developed by @faltrenn -- since Aug, 2023                   ///
///////////////////////////////////////////////////////////////////////////////
///                                Semana 2                                 ///
///                  Projeto Sistema de Gestão Escolar                      ///
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validar.c"
#include "formatacoes.c"
#include "clientes.c"
#include "materiais.c"
#include "vendas.c"


void tela_menu_principal(void);
void tela_equipe(void);
void tela_sobre(char *desc);

void tela_relatorios(void);

int main(void) {
    int op = -1;
    while(op != 0) {
        system("clear||cls");
        printf("\n");
        cabecalho1();
        printf("///                                                                         ///\n");
        printf("///         = = = = = Sistema de Gestão de Materiais = = = = =              ///\n");
        printf("///                                                                         ///\n");
        char* opcoes[] = {
            "Módulo Materiais",
            "Módulo Clientes",
            "Módulo Vendas",
            "Módulo Relatórios",
            "Equipe",
            "Sobre",
            NULL
        };
        mostrar_opcoes(opcoes, 73);
        printf("///            0. Sair                                                      ///\n");
        printf("///                                                                         ///\n");
        op = pegar_inteiro("///            Escolha a opção desejada: ", 1, "Opção invalida!\n");
        printf("///                                                                         ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");

        switch (op)
        {
        case 1:
            tela_menu_material();
            break;
        case 2:
            tela_menu_cliente();
            break;
        case 3:
            tela_menu_venda();
            break;
        case 4:
            tela_relatorios();
            break;
        case 5:
            tela_equipe();
            break;
        case 6:
            tela_sobre("Programa de Gestão de Materiais de Construção que visa facilitar o controle de estoque e vendas de uma loja de materiais de construção.");
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção invalida!\n");
        }
    }
    return 0;
}


void tela_menu_principal(void) {
    char op;
    system("clear||cls");
    printf("\n");
    cabecalho1();
    printf("///                                                                         ///\n");
    printf("///         = = = = = Sistema de Gestão de Materiais = = = = =              ///\n");
    printf("///                                                                         ///\n");
    
    char* opcoes[] = {
        "Módulo Materiais",
        "Módulo Clientes",
        "Módulo Vendas",
        "Módulo Relatórios",
        "Equipe",
        "Sobre",
        NULL
    };

    mostrar_opcoes(opcoes, 73);

    printf("///            0. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///            Escolha a opção desejada: ");
    scanf("%c", &op);
    getchar();
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void tela_sobre(char *desc) {
    system("clear||cls");
    printf("\n");
    cabecalho1();
    printf("///                                                                         ///\n");
    printf("///            = = = = = Sistema de Gestão Escolar = = = = =                ///\n");
    printf("///                                                                         ///\n");

    mostrar_descricao(desc, 71);

    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


void tela_equipe(void) {
    system("clear||cls");
    printf("\n");
    cabecalho1();
    printf("///                                                                         ///\n");
    printf("///          = = = = = Sistema de gestão de materiais = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///          Este projeto exemplo foi desenvolvido por:                     ///\n");
    printf("///                                                                         ///\n");
    printf("///          Emanuel Alves de Medeiros                                      ///\n");
    printf("///          E-mail: emanuelalvesps5@gmail.com                              ///\n");
    printf("///          Git: https://github.com/Faltrenn/CBuilding.git                 ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}
