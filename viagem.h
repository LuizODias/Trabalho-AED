#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct amigo{
    char nome[50], telefone[20], email[40];
    struct amigo *ant, *prox;
};
typedef struct amigo Amigo;

struct viagem{
    char cidade[30], estado[30], pais[30];
    struct viagem *ant, *prox;
};
typedef struct viagem Viagem;

struct no{
    char data[10];
    struct no *ant, *prox;
};
typedef struct no No;

No* criaNo();
Viagem* criaViagem();
Amigo* criaAmigo();


