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
#include <stdbool.h>
#include <ctype.h>


void tela_menu_principal(void);
void tela_equipe(void);
void tela_sobre(char *desc);
void tela_menu_material(void);
void tela_cadastrar_material(void);
void tela_pesquisar_material(void);
void tela_alterar_material(void);
void tela_excluir_material(void);

void tela_menu_cliente(void);
void tela_cadastrar_cliente(void);
void tela_pesquisar_cliente(void);
void tela_alterar_cliente(void);
void tela_excluir_cliente(void);

void tela_menu_venda(void);
void tela_cadastrar_venda(void);
void tela_pesquisar_venda(void);
void tela_alterar_venda(void);
void tela_excluir_venda(void);

void tela_relatorios(void);

void cabecalho1(void);
void cabecalho2(char * titulo);
void mostrar_descricao(char *desc, int limite);
char* centralizar_texto(char * titulo, int tam, int horizontal);
char* cortar_string(char *str, int inicio, int fim);
char* pegar_valor(char* mensagem, int tamanho, char* mensagem_erro);
int pegar_inteiro(char* mensagem, int tamanho, char* mensagem_erro);
bool validar_inteiro(char* inteiro);
void mostrar_opcoes(char* opcoes[], int linha_tam);

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
        mostrar_opcoes(
            opcoes,
            73
        );
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


void mostrar_opcoes(char* opcoes[], int linha_tam) {
    int c = 0;
    while(opcoes[c] != NULL) {
        char* texto = malloc((17 + strlen(opcoes[c])) * sizeof(char));
        sprintf(texto, "            %d. %s", c+1, opcoes[c]);
        printf("///%s///\n", centralizar_texto(texto, linha_tam, -1));
        c++;
    }
}


bool validar_inteiro(char* numero) {
    for(int c = 0; c < strlen(numero); c++) {
        if(!isdigit(numero[c])) {
            return false;
        }
    }
    return true;
}

int pegar_inteiro(char* mensagem, int tamanho, char* mensagem_erro) {
    char* str = malloc(tamanho * sizeof(char));
    bool valido = false;
    while(!valido) {
        strcpy(str, pegar_valor(mensagem, tamanho, mensagem_erro));
        valido = validar_inteiro(str);
        if(!valido) {
            printf("%s",mensagem_erro);
        }
    }
    return atoi(str);
}


char* pegar_valor(char* mensagem, int tamanho, char* mensagem_erro) {
    bool valido = false;
    char* var = malloc(tamanho * sizeof(char));
    if(mensagem_erro == NULL) {
        mensagem_erro = "Valor invalido!\n";
    }
    while(!valido) {
        printf("%s", mensagem);
        valido = scanf("%s", var) == 1 && strlen(var) <= tamanho;
        if(!valido) {
            printf("///            %s", mensagem_erro);
            while(getchar() != '\n');
            printf("\n\t\t\t>>> Tecle <ENTER> para continuar...\n");
            getchar();
            for(int c =0; c < 5; c++){
                printf("\x1b[1A\x1b[2K");
            }
        }
    }
    getchar();
    return var;
}


void cabecalho1(void) {
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                 Centro de Ensino Superior do Seridó                     ///\n");
    printf("///               Departamento de Computação e Tecnologia                   ///\n");
    printf("///                  Disciplina DCT1106 -- Programação                      ///\n");
    printf("///    Projeto Sistema de Gestão Material para fornecedores de materiais    ///\n");
    printf("///                               de constução                              ///\n");
    printf("///              Developed by @Faltrenn -- since Aug, 2023                  ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
}

void cabecalho2(char *titulo) {
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///            = = = =%s= = = =          ///\n", centralizar_texto(titulo, 37, 0));
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///                Developed by @faltrenn -- since Aug, 2023                ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
}

char* centralizar_texto(char* texto, int tam, int horizontal) {
    int tam_texto = strlen(texto);

    for(int c = 0;c < tam_texto;c++) {
        if(texto[c] < 0) {
            tam++;
            c++;
        }
    }
    int pos;
    if(horizontal == 1) {
        pos = tam - tam_texto;
    } else if (horizontal == -1) {
        pos = 0;
    } else {
        pos = tam/2 - tam_texto/2;
    }

    char *str= malloc(tam * sizeof(char));
    for(int c = 0; c < tam; c++) {
        if(c >= pos && c < (pos + tam_texto)) {
            str[c] = texto[c-pos];
        } else {
            str[c] = ' ';
        }
    }
    return str;
}

void mostrar_descricao(char *desc, int limite) {
    int inicio_linha = 0;
    int aux = 0;
    char *linha = malloc(limite * sizeof(char));

    for(int c = 0; c < strlen(desc); c++) {
        if(desc[c] == ' ' || desc[c] == '\n' || desc[c] == '\0') {
            linha = malloc((strlen(desc) + 1) * sizeof(char));
            aux = c;
            char *str = cortar_string(desc, inicio_linha, c);
            strcpy(linha, str);
            free(str);
        }
        if (c % limite == 0 && c != 0) {
            printf("/// %s ///\n", centralizar_texto(linha, limite, 0));
            linha = NULL;
            inicio_linha = aux;
        }
    }
    if(linha != NULL) {
        printf("/// %s ///\n", centralizar_texto(linha, limite, 0));
    }
    free(linha);
}

void tela_menu_principal(void) {
    char op;
    system("clear||cls");
    printf("\n");
    cabecalho1();
    printf("///                                                                         ///\n");
    printf("///         = = = = = Sistema de Gestão de Materiais = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Módulo Materiais                                          ///\n");
    printf("///            2. Módulo Clientes                                           ///\n");
    printf("///            3. Módulo Vendas                                             ///\n");
    printf("///            4. Módulo Relatórios                                         ///\n");
    printf("///            5. Equipe                                                    ///\n");
    printf("///            6. Sobre                                                     ///\n");
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


char* cortar_string(char *str, int inicio, int fim) {
    char *nova_str = malloc((fim - inicio + 1) * sizeof(char));
    int c = 0;
    for(int i = inicio; i < fim; i++) {
        nova_str[c] = str[i];
        c++;
    }
    nova_str[c] = '\0';
    return nova_str;
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


void tela_menu_material(void) {
    char op;
    system("clear||cls");
    printf("\n");
    cabecalho2("Modulo Materiais de Construcao");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Menu Materiais  = = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Cadastrar material                                        ///\n");
    printf("///            2. Pesquisar material                                        ///\n");
    printf("///            3. Atualizar material                                        ///\n");
    printf("///            4. Excluir material                                          ///\n");
    printf("///            0. Voltar ao menu anterior                                   ///\n");
    printf("///                                                                         ///\n");
    printf("///            Escolha a opção desejada: ");
    scanf("%c", &op);
    getchar();
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
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


void tela_menu_cliente(void) {
    char op;
    system("clear||cls");
    printf("\n");
    cabecalho2("Modulo Materiais de Construcao");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Menu Materiais  = = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Cadastrar cliente                                         ///\n");
    printf("///            2. Pesquisar cliente                                         ///\n");
    printf("///            3. Atualizar cliente                                         ///\n");
    printf("///            4. Excluir cliente                                           ///\n");
    printf("///            0. Voltar ao menu anterior                                   ///\n");
    printf("///                                                                         ///\n");
    printf("///            Escolha a opção desejada: ");
    scanf("%c", &op);
    getchar();
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
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



void tela_menu_venda(void) {
    char op;
    system("clear||cls");
    printf("\n");
    cabecalho2("Modulo Materiais de Construcao");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Menu Materiais  = = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Cadastrar venda                                           ///\n");
    printf("///            2. Pesquisar venda                                           ///\n");
    printf("///            3. Atualizar venda                                           ///\n");
    printf("///            4. Excluir venda                                             ///\n");
    printf("///            0. Voltar ao menu anterior                                   ///\n");
    printf("///                                                                         ///\n");
    printf("///            Escolha a opção desejada: ");
    scanf("%c", &op);
    getchar();
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
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


void tela_relatorios(void) {
    char op;
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
