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
    char cidade[30];
    int h_h,h_m,r_h,r_m;
    struct viag *ant, *prox;
    Amigo* lista_amigos;
};
typedef struct viag Viagens;

struct data{
    int dia,mes,ano;
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


//CHECAR ELEMENTOS REPETIDOS DA LISTA
int checaAmigos(Amigo* l, char* nome);
int checaViagem(Deslocamento* l, char* cidade);
int checaData(Data *l, int dia, int mes, int ano);
Viagens* checa_hora_repetida(Viagens* l,char *nome);

//INSERIR NA VIAGEM
Amigo* recebe_amigo_atualizado(Amigo* l, char* nome);
Amigo* amigoNaViagem(Amigo* l,Amigo* all_friends,Viagens* viagens);
Viagens* insereViagem(Viagens* l,Amigo* all_friends, Deslocamento* all_places);
Viagens* insereViagemfim(Viagens* l, Viagens* novo);
Data* insereData(Data* l, int dia,int mes,int ano,Amigo* all_friends, Deslocamento* all_places);
Data* insere_na_mesma_data(Data* l, int dia, int mes,int ano, Amigo* all_friends, Deslocamento* all_places);
Data* insere_mais_um(Data* l,Amigo* amigos);


void gravaArquivo(Data* l, FILE* entrada);


//IMPRESSAO
void imprimeAmigos(Amigo* p);
void imprimeDeslocamento(Deslocamento* p);
void imprimeViagem(Data* l);
