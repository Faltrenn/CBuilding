#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "formatacoes.h"

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
    printf("///                Developed by @Faltrenn -- since Aug, 2023                ///\n");
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


void mostrar_opcoes(char* opcoes[], int linha_tam) {
    int c = 0;
    while(opcoes[c] != NULL) {
        char* texto = malloc((17 + strlen(opcoes[c])) * sizeof(char));
        sprintf(texto, "            %d. %s", c+1, opcoes[c]);
        printf("///%s///\n", centralizar_texto(texto, linha_tam, -1));
        c++;
    }
}
