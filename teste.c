#include <string.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct pessoa {
    char *nome;
    int idade;
};

int main() {
    int tamanho = 3;
    char **arr = malloc(tamanho * sizeof(char)); 

    arr[0] = "Opa, ";
    arr[1] = "Boa ";
    arr[2] = "Noite";

    for(int c = 0; c < tamanho; c++) {
        printf("%s\n", arr[c]);
    }

    struct pessoa pessoa;   

    pessoa.nome = malloc(sizeof(char));
    strcpy(pessoa.nome, "Emanuel");
    pessoa.idade = 20;

    printf("%s\n", pessoa.nome);
    printf("%d\n", pessoa.idade);

    return 0;
}