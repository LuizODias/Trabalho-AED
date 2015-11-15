#include "viagens.h"

Data* criaNo(){
    return NULL;
}

Deslocamento* criaDeslocamento(){
    return NULL;
}

Amigo* criaAmigo(){
    return NULL;
}

//Lista Linear Duplamente
Amigo* insereAmigo(Amigo* l, char* nome, char* telefone, char* email){
    Amigo* aux=l, *novo;


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
        if(aux==l){
            novo->ant=NULL;
            novo->prox=l;
            if(l!=NULL){
                l->ant=novo;
            }
        }
        else{
            if(aux!=NULL){
                novo->ant=aux->ant;
                novo->prox=aux;
                aux->ant->prox=novo;
                aux->ant=novo;
            }
        }
    }
    return l;
}

int checaAmigos(Amigo* l, char* nome){
    Amigo* aux=l;

    while((aux!=NULL)){
        if(strcmp(strupr(nome),strupr(aux->nome))==0){
            //CASO EXISTA ALGUEM COM O MESMO NOME NA LISTA, A FUNÇÃO RETORNARÁ 1 PARA O VERIFICADOR!
            return 1;
        }
        aux=aux->prox;
    }

    //CASO NÃO EXISTA NIGUEM COM O MESMO NOME, ENTÃO A FUNÇÃO RETORNARÁ 0 PARA O VERIFICADOR
    return 0;
}

//Lista Linear Duplamente
Deslocamento* insereDeslocamento(Deslocamento* l, char* cidade, char* pais, char* estado){
    Deslocamento* aux=l, *novo;

    novo=(Deslocamento*)malloc(sizeof(Deslocamento));

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

    return l;
}

int checaViagem(Deslocamento* l, char* cidade){
    Deslocamento* aux=l;

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

//Lista duplamente
Viagens* amigoNaViagem(Viagens* l,Amigo* all_friends){
    int verificador=0, opcao=0;
    char nome[30];
    Amigo* novo;

    if(all_friends==NULL){
        printf("NENHUMA PESSO FOI CADASTRADA!");
        return NULL;
    }

    novo=(Amigo*)malloc(sizeof(Amigo));

    do{
        printf("AMIGO: ");
        setbuf(stdin,NULL);
        gets(nome);
        system("cls");

        verificador=checaAmigos(all_friends,nome);

        if(verificador==0){
            printf("PESSOA NAO FOI CADASTRADA!\n\n");
        }
    }while(verificador!=1);

    strcpy(nome,novo->nome);

    novo->ant=NULL;
    novo->prox=l->migs->prox;

    do{
        printf("INSERIR MAIS ALGUEM?\n");
        printf("1-SIM\n2-NAO\n");
        scanf("%d",&opcao);
        system("cls");

        if(opcao==1){
            l=amigoNaViagem(l,all_friends);
        }
    }while(opcao!=2);

    return l;
}

//Lista duplamente
Data* insereViagem(Data* l,Amigo* all_friends, Deslocamento* all_places){
    int verificador=0;
    char cidade[30],horas[10];
    Viagens* novo, *aux;

    if(all_places==NULL){
        printf("NENHUM LOCAL FOI CADASTRADO!");
        return NULL;
    }

    aux=l->viage;

    novo=(Viagens*)malloc(sizeof(Viagens));

    novo->migs=amigoNaViagem(novo->migs,all_friends);

    do{
        printf("CIDADE: ");
        setbuf(stdin,NULL);
        gets(cidade);
        system("cls");

        verificador=checaViagem(all_places,cidade);

        if(verificador==0){
            printf("CIDADE NAO FOI CADASTRADA!");
        }
    }while(verificador!=1);

    /*o printf continuara a aparece enquanto o usuario não digitar uma cidade que foi cadastrada previamente.
    A cidade que pretende viajar é enviada para função 'checaViagem' que retornará 0 caso não encontre nenhuma
    cidade com o mesmo nome. Caso haja alguma cidade já cadastrada, a função retornara 1, e assim o usuario
    podera prosseguir para a inserção de outros dados
    */

    printf("HORARIO DA VIAGEM: ");
    setbuf(stdin,NULL);
    gets(horas);

    strcpy(cidade,novo->cidade);
    strcpy(horas,novo->horas);

    //ATÉ AGORA OS DADOS FORAM COLETADOS, A PARTI DAQUI SERAO INSERIDOS DE ACORDO COM AS HORAS
    if(aux==NULL){
        novo->ant=NULL;
        novo->prox=NULL;
    }
    else{
        do{
            aux=aux->prox;
        }while((aux->prox!=NULL)&&(strcmp(aux->horas,horas)<0));

        if(aux->prox==NULL){
            aux->prox=novo;
            novo->ant=aux;
            novo->prox=NULL;
        }
        if(aux==l->viage){
            aux->ant=novo;
            novo->prox=aux;
            novo->ant=NULL;
        }
        else{
            aux->ant->prox=novo;
            novo->ant=aux->ant;
            novo->prox=aux;
            aux->ant=novo;
        }
    }
    return l;
}

//Lista Circular Duplamente
Data* insereData(Data* l, char* dia,Amigo* all_friends, Deslocamento* all_places){
    Data* novo, *aux=l;

    novo=(Data*)malloc(sizeof(Data));

    strcpy(dia,novo->data);

    novo->viage=insereViagem(novo->viage,all_friends,all_places);

    if(l==NULL){
        novo->prox=novo;
        novo->ant=novo;

        return novo;
    }
    else{
        do{
            aux=aux->prox;
        }while((aux!=l)&&(strcmp(aux->data,dia)<0));

        if(aux==l){
            aux->ant->prox=novo;
            novo->ant=aux->ant;
            novo->prox=aux;
            aux->ant=novo;
        }
        else{
            novo->prox=aux;
            novo->ant=aux->ant;
            aux->ant->prox=novo;
            aux->ant=novo;
        }
    }
    return l;
}

int checaData(Data *l, char* dia){
    Data *aux=l;

    do{
        if(strcmp(aux->data,dia)==0){
            //DATA REPETIDA
            return 1;
        }
        aux=aux->prox;
    }while(aux!=l);

    //NENHUMA DATA IGUAL
    return 0;
}


