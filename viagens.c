#include "viagens.h"

No* criaNo(){
    return NULL;
}

Viagem* criaViagem(){
    return NULL;
}

Amigo* criaAmigo(){
    return NULL;
}

Amigo* insereAmigo(Amigo* l, char* nome, char* telefone, char* email){
    Amigo* aux=l, *novo;

    int verificador=0;
    /*
    O verificador e a variavel que contera o valor da funçao checaAmigos.
    Essa funçao tem como objetivo checar toda a lista de amigos, e verificar se o novo amigo a ser inserido
    ja existe. Caso exista alguem com mesmo nome, o verificador passara a valer 1. Caso contrario continuara com 0.
    */
    verificador=checaAmigos(l,nome);

    //CHECAGEM DO VERIFICADOR
    if(verificador==1){
        printf("PESSOA JA CADASTRADA!");
        return l;
    }
    else{
        novo=(Amigo*)malloc(sizeof(Amigo));

        //ADICIONA OS NOVOS ELEMENTOS
        strcpy(nome,novo->nome);
        strcpy(telefone,novo->telefone);
        strcpy(email,novo->email);

        //CASO A LISTA ESTEJA VAZIA
        if(aux==NULL){
            novo->ant=NULL;
            novo->prox=NULL;

            return novo;
        }

        else{
            while((aux->prox!=NULL)&&(strcmp(aux->nome,nome)>1)){
                aux=aux->prox;
            }
            if(aux->ant==NULL){
                aux->ant=novo;
                novo->prox=aux;
                novo->ant=NULL;
            }
            if(aux->prox==NULL){
                aux->prox=novo;
                novo->ant=aux;
                novo->prox=NULL;
            }
            else{
                novo->prox=aux->prox;
                aux->prox->ant=novo;
                aux->prox=novo;
                novo->ant=aux;
            }
        }
    }
    return l;
}

int checaAmigos(Amigo* l, char* nome){
    Amigo* aux=l;

    while((aux!=NULL)){
        if(strcmp(aux->nome,nome)==0){
            //CASO EXISTA ALGUEM COM O MESMO NOME NA LISTA, A FUNÇÃO RETORNARÁ 1 PARA O VERIFICADOR!
            return 1;
        }
        aux=aux->prox;
    }

    //CASO NÃO EXISTA NIGUEM COM O MESMO NOME, ENTÃO A FUNÇÃO RETORNARÁ 0 PARA O VERIFICADOR
    return 0;
}

Viagem* insereViagem(Viagem* l, char* cidade, char* pais, char* estado){
    Viagem* aux=l, *novo;

    int verificador=0;
    /*
    O verificador e a variavel que contera o valor da funçao checaViagem.
    Essa funçao tem como objetivo checar toda a lista de cidades, e verificar se a nova cidade a ser inserida
    ja existe. Caso exista alguma com mesmo nome, o verificador passara a valer 1. Caso contrario continuara com 0.
    */
    verificador=checaViagem(l,cidade);

    //CHECAGEM DO VERIFICADOR
    if(verificador==1){
        printf("CIDADE JA CADASTRADA!");
        return l;
    }
    else{
        novo=(Viagem*)malloc(sizeof(Viagem));

        //ADICIONA OS NOVOS ELEMENTOS
        strcpy(cidade,novo->cidade);
        strcpy(pais,novo->pais);
        strcpy(estado,novo->estado);

        //CASO A LISTA ESTEJA VAZIA
        if(aux==NULL){
            novo->ant=NULL;
            novo->prox=NULL;

            return novo;
        }

        else{
            while((aux->prox!=NULL)&&(strcmp(aux->cidade,cidade)>1)){
                aux=aux->prox;
            }
            if(aux->ant==NULL){
                aux->ant=novo;
                novo->prox=aux;
                novo->ant=NULL;
            }
            if(aux->prox==NULL){
                aux->prox=novo;
                novo->ant=aux;
                novo->prox=NULL;
            }
            else{
                novo->prox=aux->prox;
                aux->prox->ant=novo;
                aux->prox=novo;
                novo->ant=aux;
            }
        }
    }
    return l;
}

int checaViagem(Viagem* l, char* cidade){
    Viagem* aux=l;

    while(aux!=NULL){
        if(strcmp(aux->cidade,cidade)==0){
            //CIDADE REPETIDA
            return 1;
        }
        aux=aux->prox;
    }
    //NAO TEM CIDADES COM MESMO NOME
    return 0;
}


