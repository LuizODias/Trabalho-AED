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

struct viag{
    char cidade[30],horas[15],retorno[15];
    struct viag *ant, *prox;
    Amigo* lista_amigos;
};
typedef struct viag Viagens;

struct data{
    char data[10];
    struct data *ant, *prox;
    Viagens* lista_viagem;
};
typedef struct data Data;

//CRIA AS LISTAS

Data* criaNo();
Deslocamento* criaDeslocamento();
Amigo* criaAmigo();

//ADICIONAR DADOS
Amigo* insereAmigo(Amigo* l, char* nome, char* telefone, char* email);
Amigo* insereFim(Amigo* l, char* nome,char* telefone, char* email);
Deslocamento* insereDeslocamento(Deslocamento* l, char* cidade, char* pais, char* estado);
Data* insereData(Data* l, char* dia,Amigo* all_friends, Deslocamento* all_places);

//CHECAR ELEMENTOS REPETIDOS DA LISTA
int checaAmigos(Amigo* l, char* nome);
int checaViagem(Deslocamento* l, char* cidade);
int checaData(Data *l, char* dia);

//INSERIR NA VIAGEM
Amigo* amigoNaViagem(Amigo* l,Amigo* all_friends);
Viagens* insereViagem(Viagens* l,Amigo* all_friends, Deslocamento* all_places);
Viagens* insereViagemfim(Viagens* l, char* cidade, char* horas);
Data* insereData(Data* l, char* dia,Amigo* all_friends, Deslocamento* all_places);
Data* insere_na_mesma_data(Data* l, char* dia, Amigo* all_friends, Deslocamento* all_places);


void gravaArquivo(Data* l, FILE* entrada);


//IMPRESSAO
void imprimeAmigos(Amigo* p);
void imprimeDeslocamento(Deslocamento* p);
void imprimeViagem(Data* l);
