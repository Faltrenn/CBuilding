#ifndef FORMAT_H
#define FORMAT_H

void cabecalho1(void);
void cabecalho2(char * titulo);
void mostrar_descricao(char *desc, int limite);
char* centralizar_texto(char * titulo, int tam, int horizontal);
char* cortar_string(char *str, int inicio, int fim);
void mostrar_opcoes(char* opcoes[], int linha_tam);

#endif
