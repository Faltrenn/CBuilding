#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "validar.h"

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
        }
    }
    getchar();
    return var;
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
