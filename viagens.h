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

struct data{
    char data[10];
    struct data *ant, *prox;
};
typedef struct data Data;


//CRIA AS LISTAS
Data* criaNo();
Deslocamento* criaDeslocamento();
Amigo* criaAmigo();

//ADICIONAR DADOS
Amigo* insereAmigo(Amigo* l, char* nome, char* telefone, char* email);
Deslocamento* insereDeslocamento(Deslocamento* l, char* cidade, char* pais, char* estado);
Data* insereData(Data* l, char* dia);

//CHECAR ELEMENTOS REPETIDOS DA LISTA
int checaAmigos(Amigo* l, char* nome);
int checaViagem(Deslocamento* l, char* cidade);
int checaData(Data *l, char* dia);
