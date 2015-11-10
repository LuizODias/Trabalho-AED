#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct amigo{
    char nome[50], telefone[20], email[40];
    struct amigo *ant, *prox;
};
typedef struct amigo Amigo;

struct deslocamento{
    char cidade[30], estado[30], pais[30];
    struct deslocamento *ant, *prox;
};
typedef struct deslocamento Deslocamento;

struct no{
    char data[10];
    struct no *ant, *prox;
};
typedef struct no No;


//CRIA AS LISTAS
No* criaNo();
Deslocamento* criaDeslocamento();
Amigo* criaAmigo();

//ADICIONAR OS AMIGOS
Amigo* insereAmigo(Amigo* l, char* nome, char* telefone, char* email);
Deslocamento* insereDeslocamento(Deslocamento* l, char* cidade, char* pais, char* estado);

//CHECAR ELEMENTOS REPETIDOS DA LISTA
int checaAmigos(Amigo* l, char* nome);
int checaViagem(Deslocamento* l, char* cidade);
