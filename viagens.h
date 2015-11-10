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


//CRIA AS LISTAS
No* criaNo();
Viagem* criaViagem();
Amigo* criaAmigo();

//ADICIONAR OS AMIGOS
Amigo* insereAmigo(Amigo* l, char* nome, char* telefone, char* email);

//CHECAR ELEMENTOS REPETIDOS DA LISTA
int checaAmigos(Amigo* l, char* nome);
int checaViagem(Viagem* l, char* cidade);
