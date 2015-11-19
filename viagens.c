#include "viagens.h"

//FUNÇÕES CRIA LISTA
Data* criaNo(){
    return NULL;
}
Deslocamento* criaDeslocamento(){
    return NULL;
}
Amigo* criaAmigo(){
    return NULL;
}

//FUNÇÕES DE INSERÇÃO DE AMIGO E DESLOCAMENTO
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

//FUNÇÕES DE CHECAGEM
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


//FUNÇÕES DE INSERÇÃO DE VIAGEM
//Lista duplamente
Amigo* amigoNaViagem(Amigo* l,Amigo* all_friends){
    int verificador=0, opcao=0;
    char nome[50];
    Amigo* novo;

    //CASO A LISTA DE AMIGOS FOR VAZIA, RETORNARA PARA FUNÇÃO ANTERIOR
    if(all_friends==NULL){
        printf("NENHUMA PESSOA FOI CADASTRADA!");
        return NULL;
    }

    novo=(Amigo*)malloc(sizeof(Amigo));

    //PERMANECERA NO LAÇO, ENQUANTO O USUARIO NAO DIGITAR UM NOME CADASTRADO PREVIAMENTE
    do{
        printf("AMIGO: ");
        setbuf(stdin,NULL);
        strupr(gets(nome));
        system("cls");

        //VERIFICA CASO USUARIO JA FOI INSERIDO
        verificador=checaAmigos(all_friends,nome);

        if(verificador==0){
            printf("PESSOA NAO FOI CADASTRADA!\n\n");
        }
    }while(verificador!=1);

    strcpy(novo->nome,nome);

    //INSERE NO INICIO
    novo->ant=NULL;
    novo->prox=l;

    //CASO O USUARIO QUISER INSERIR MAIS AMIGOS NA VIAGEM
    do{
        printf("INSERIR MAIS ALGUEM?\n");
        printf("1-SIM\n2-NAO\n");
        printf("OPCAO: ");
        scanf("%d",&opcao);
        system("cls");

        if(opcao==1){
            novo->prox=amigoNaViagem(l,all_friends);
        }
    }while(opcao!=2);

    return l;
}
//Lista duplamente
Viagens* insereViagem(Viagens* l,Amigo* all_friends, Deslocamento* all_places){
    int verificador=0;
    char cidade[30],horas[10],retorno[10];
    Viagens* novo, *aux;

    //CASO A LISTA DE LOCAIS CADASTRADOS ESTIVER VAZIA
    if(all_places==NULL){
        printf("NENHUM LOCAL FOI CADASTRADO!");
        return NULL;
    }

    novo=(Viagens*)malloc(sizeof(Viagens));

    //CHAMA A FUNÇÃO PARA INSERIR OS AMIGOS
    novo->lista_amigos=amigoNaViagem(novo->lista_amigos,all_friends);
    //APOS O PONTEIRO DA LISTA DE AMIGOS SER ATUALIZADO, COMEÇAR INSERÇÃO DE DADOS RELATIVOS A VIAGEM

    //aux, AUXILIAR QUE CONTERA A LISTA DE VIAGENS
    aux=l;

    do{
        printf("CIDADE: ");
        setbuf(stdin,NULL);
        strupr(gets(cidade));
        system("cls");

        verificador=checaViagem(all_places,cidade);

        if(verificador==0){
            printf("CIDADE NAO FOI CADASTRADA!");
        }
    }while(verificador!=1);

    /*o printf continuara a aparecer enquanto o usuario não digitar uma cidade que foi cadastrada previamente.
    A cidade que pretende viajar é enviada para função 'checaViagem' que retornará 0 caso não encontre nenhuma
    cidade com o mesmo nome. Caso haja alguma cidade já cadastrada, a função retornara 1, e assim o usuario
    podera prosseguir para a inserção de outros dados
    */

    printf("HORARIO DA VIAGEM: ");
    setbuf(stdin,NULL);
    gets(horas);

    printf("HORARIO DE RETORNO: ");
    setbuf(stdin,NULL);
    gets(retorno);
    system("cls");

    strcpy(novo->cidade,cidade);
    strcpy(novo->horas,horas);
    strcpy(novo->retorno,retorno);


    //ATÉ AGORA OS DADOS FORAM COLETADOS, A PARTIR DAQUI SERAO INSERIDOS DE ACORDO COM AS HORAS
    if(aux==NULL){
        novo->ant=NULL;
        novo->prox=NULL;

        return novo;
    }
    else{
        while((aux!=NULL)&&(strcmp(aux->horas,horas)<0)){
            aux=aux->prox;
        }

        if(aux==l){
            novo->ant=NULL;
            novo->prox=l;
            if(l!=NULL){
                l->ant=novo;
            }
            l=novo;
        }
        else{
            if(aux!=NULL){
                novo->ant=aux->ant;
                novo->prox=aux;
                aux->ant->prox=novo;
                aux->ant=novo;
            }
            else{
                l=insereViagemfim(l,cidade,horas);
            }
        }
        return l;
    }
}
//COMPLEMENTO insereViagem
Viagens* insereViagemfim(Viagens* l, char* cidade, char* horas){
    Viagens* aux=l;
    Viagens* novo=(Viagens*)malloc(sizeof(Viagens));

    strcpy(novo->cidade,cidade);
    strcpy(novo->horas,horas);

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
//Lista Circular Duplamente
Data* insereData(Data* l, char* dia,Amigo* all_friends, Deslocamento* all_places){
    Data* novo, *aux=l;

    novo=(Data*)malloc(sizeof(Data));

    strcpy(novo->data,dia);
    novo->lista_viagem=NULL;

    //CHAMA A FUNÇÃO PARA PODER INSERIR A VIAGEM
    novo->lista_viagem=insereViagem(novo->lista_viagem,all_friends,all_places);
    //RECEBE LISTA DE VIAGEM ATUALIZADA

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
    //APOS SER INSERIDO NO LOCAL CORRETO, RETORNA A LISTA ATUALIZADA
    return l;
}
//CASO JA EXISTA UMA MESMA DATA ALOCADA, A FUNÇÃO VIRA PRA CA, PARA NAO PRECISAR ALOCAR OUTRO ESPAÇO NA MEMORIA
Data* insere_na_mesma_data(Data* l, char* dia, Amigo* all_friends, Deslocamento* all_places){
    Data* aux=l;

    do{
        if(strcmp(aux->data,dia)==0){
            l->lista_viagem=insereViagem(l->lista_viagem,all_friends,all_places);
            return l;
        }
        aux=aux->prox;
    }while((aux!=l)&&(strcmp(aux->data,dia)!=0));

    return l;
}


void gravaArquivo(Data* l, FILE* entrada){
    Data* data=l;
    Viagens* viagem=l->lista_viagem;

}


//FUNÇÕES DE IMPRESSÃO
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
void imprimeViagem(Data* l){
    Data* p=l;
    Viagens* p1=p->lista_viagem;
    Amigo* p2=p1->lista_amigos;

    do{
        printf("%s\n",p->data);
        printf("%s as %s\n",p1->cidade, p1->horas);
        while(p2!=NULL){
            printf("%s, ",p2->nome);
            p2=p2->prox;
        }
        printf("\n---------------------------------------------------------\n");
        p=p->prox;
        p1=p->lista_viagem;
        p2=p1->lista_amigos;
    }while(p!=l);
}
