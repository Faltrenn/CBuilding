#include <stdbool.h>

#ifndef VALID_H
#define VALID_H

char* pegar_valor(char* mensagem, int tamanho, char* mensagem_erro);
int pegar_inteiro(char* mensagem, int tamanho, char* mensagem_erro);
bool validar_inteiro(char* inteiro);

#endif