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
    int num = atoi(str);
    free(str);
    getchar();
    return num;
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

// Função tirada de: https://gist.github.com/eduardoedson/8f991b6d234a9ebdcbe3
int validar_cpf(char *cpf)
{
    int i, j, digito1 = 0, digito2 = 0;
    if(strlen(cpf) != 11)
        return 0;
    else if((strcmp(cpf,"00000000000") == 0) || (strcmp(cpf,"11111111111") == 0) || (strcmp(cpf,"22222222222") == 0) ||
            (strcmp(cpf,"33333333333") == 0) || (strcmp(cpf,"44444444444") == 0) || (strcmp(cpf,"55555555555") == 0) ||
            (strcmp(cpf,"66666666666") == 0) || (strcmp(cpf,"77777777777") == 0) || (strcmp(cpf,"88888888888") == 0) ||
            (strcmp(cpf,"99999999999") == 0))
        return 0;
    else
    {
        for(i = 0, j = 10; i < strlen(cpf)-2; i++, j--)
            digito1 += (cpf[i]-48) * j;
        digito1 %= 11;
        if(digito1 < 2)
            digito1 = 0;
        else
            digito1 = 11 - digito1;
        if((cpf[9]-48) != digito1)
            return 0;
        else
        {
            for(i = 0, j = 11; i < strlen(cpf)-1; i++, j--)
                    digito2 += (cpf[i]-48) * j;
        digito2 %= 11;
        if(digito2 < 2)
            digito2 = 0;
        else
            digito2 = 11 - digito2;
        if((cpf[10]-48) != digito2)
            return 0;
        }
    }
    return 1;
}
