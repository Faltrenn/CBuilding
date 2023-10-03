#include <stdbool.h>

#ifndef VALIDAR_H
#define VALIDAR_H

char* pegar_valor(char* mensagem, int tamanho, char* mensagem_erro);
int pegar_inteiro(char* mensagem, int tamanho, char* mensagem_erro);
bool validar_inteiro(char* inteiro);
char* cortar_string(char *str, int inicio, int fim);
int validar_cpf(char *cpf);

#endif