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
    Amigo *novo,*p;
    p=l;

    while((p!=NULL)&&(strcmp(p->nome,nome)<0)){
        p=p->prox;
    }

    novo=(Amigo*)malloc(sizeof(Amigo));

    strcpy(novo->nome,nome);
    strcpy(novo->telefone,telefone);
    strcpy(novo->email,email);

    //SE FOR INSERIDO NO INICIO
    if(l==p){
        novo->ant=NULL;
        novo->prox=l;
        if(l!=NULL)
            l->ant=novo;
        l=novo;
    }
    else{
        //INSERIDO NO MEIO DA LISTA
        if(p!=NULL){
            novo->ant=p->ant;
            novo->prox=p;
            p->ant->prox=novo;
            p->ant=novo;
        }
        else{
            //INSERIR NO FIM
            l=insereFim(l,nome,telefone,email);
        }
    }
    return l;
}
//COMPLEMENTO INSERE AMIGO
Amigo* insereFim(Amigo* l, char* nome,char* telefone, char* email){
    Amigo* aux,*novo;
    aux=l;

    novo=(Amigo*)malloc(sizeof(Amigo));

    strcpy(novo->nome,nome);
    strcpy(novo->telefone,telefone);
    strcpy(novo->email,email);

    if(l==NULL){
        novo->ant=NULL;
        novo->prox=l;
        return l;
    }

    while(aux->prox!=NULL){
        aux=aux->prox;
    }

    novo->ant=aux;
    novo->prox=NULL;
    aux->prox=novo;

    return l;
}


int checaAmigos(Amigo* l, char* nome){
    Amigo* aux=l;

    while((aux!=NULL)){
        if(strcmp(nome,aux->nome)==0){
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
    Deslocamento* novo;

    novo=(Deslocamento*)malloc(sizeof(Deslocamento));

    strcpy(novo->cidade,cidade);
    strcpy(novo->estado,estado);
    strcpy(novo->pais,pais);

    novo->ant=NULL;
    novo->prox=l;
    if(l!=NULL)
        l->ant=novo;

    return novo;
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

    printf("Sim!To no amigo\n");
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
    novo->prox=l;

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

    aux=l->lista_viagem;
    printf("Sim!To na viagem\n");
    novo=(Viagens*)malloc(sizeof(Viagens));

    novo->lista_amigos=amigoNaViagem(novo->lista_amigos,all_friends);

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
        if(aux==l->lista_viagem){
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
    printf("Sim!To na data\n");
    novo->lista_viagem=insereViagem(novo->lista_viagem,all_friends,all_places);

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

    //CASO LISTA ESTEJA VAZIA
    if(aux==NULL){
        return 0;
    }

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

void gravaArquivo(Data* l, FILE* entrada){
    Data* data=l;
    Data* viagem=l->lista_viagem;

}

void imprimeAmigos(Amigo* p){
    Amigo* aux=p;

    while(aux!=NULL){
        printf("%s\n",aux->nome);
        printf("%s\n",aux->email);
        printf("%s\n",aux->telefone);
        printf("--------------------------------------------------\n\n");
        aux=aux->prox;
    }
}

void imprimeDeslocamento(Deslocamento* p){
    Deslocamento* aux=p;

    while(aux!=NULL){
        printf("%s\n",aux->cidade);
        printf("%s\n",aux->estado);
        printf("%s\n",aux->pais);
        printf("--------------------------------------------------\n\n");
        aux=aux->prox;
    }
}

