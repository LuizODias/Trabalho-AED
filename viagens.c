#include "viagens.h"


                    ///QUANDO FIZEMOS, SÓ O GRUPO E DEUS SABIA O QUE ESTAVA ACONTECENDO NO CÓDIGO. AGORA, SÓ DEUS SABE.


///FUNÇÕES CRIA LISTA
Data* criaNo(){
    return NULL;
}
Deslocamento* criaDeslocamento(){
    return NULL;
}
Amigo* criaAmigo(){
    return NULL;
}

///FUNÇÕES DE INSERÇÃO DE AMIGO E DESLOCAMENTO
///Lista Linear Duplamente
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

    ///SE FOR INSERIDO NO INICIO
    if(l==p){
        novo->ant=NULL;
        novo->prox=l;
        if(l!=NULL)
            l->ant=novo;
        l=novo;
    }
    else{
        ///INSERIDO NO MEIO DA LISTA
        if(p!=NULL){
            novo->ant=p->ant;
            novo->prox=p;
            p->ant->prox=novo;
            p->ant=novo;
        }
        else{
            ///INSERIR NO FIM
            l=insereFim(l,nome,telefone,email);
        }
    }
    return l;
}
///COMPLEMENTO INSERE AMIGO
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
///Lista Linear Duplamente
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

///FUNÇÕES DE CHECAGEM
int checaAmigos(Amigo* l, char* nome){
    Amigo* aux=l;

    while((aux!=NULL)){
        if(strcmp(nome,aux->nome)==0){
            ///CASO EXISTA ALGUEM COM O MESMO NOME NA LISTA, A FUNÇÃO RETORNARÁ 1 PARA O VERIFICADOR!
            return 1;
        }
        aux=aux->prox;
    }

    ///CASO NÃO EXISTA NIGUEM COM O MESMO NOME, ENTÃO A FUNÇÃO RETORNARÁ 0 PARA O VERIFICADOR
    return 0;
}
int checaViagem(Deslocamento* l, char* cidade){
    Deslocamento* aux=l;

    while(aux!=NULL){
        if(strcmp(aux->cidade,cidade)==0){
            ///CIDADE REPETIDA
            return 1;
        }
        aux=aux->prox;
    }
    ///NAO TEM CIDADES COM MESMO NOME
    return 0;
}
int checaData(Data *l, int dia, int mes, int ano){
    Data *aux=l;

    ///CASO LISTA ESTEJA VAZIA
    if(aux==NULL){
        return 0;
    }

    do{
        if(aux->ano==ano){
            if(aux->mes==mes){
                if(aux->dia==dia){
                    ///DATA JA FOI CADASTRADA PREVIAMENTE
                    return 1;
                }
            }
        }
        aux=aux->prox;
    }while(aux!=l);

    ///NENHUMA DATA IGUAL
    return 0;
}
Viagens* checa_hora_repetida(Viagens* l,char *nome){
    if(l==NULL){
        return l;
    }
    else{
        Amigo* aux_amigo=l->lista_amigos, *another_aux_f;
        ///aux_amigo, PERCORRE A LISTA DOS AMIGOS
        ///another_aux_f, USADA POSTERIORMENTE, TAMBEM PARA SALVAR UMA LISTA DE AMIGOS
        Viagens* aux_viagens=l,*another_v;
        ///aux_viagens, USADA PARA PERCORRER A LISTA DE VIAGENS
        ///another_v, USADA POSTERIORMENTE PARA PERCORRER OUTRA LISTA DE VIAGENS
        int aux_retorno=0;
        ///aux_retorno, UTILIZADA PARA SALVAR O HORARIO DE RETORNO

        while(aux_viagens!=NULL){
            while(aux_amigo!=NULL){
                if(strcmp(aux_amigo->nome,nome)==0){
                    aux_retorno=aux_viagens->r_h;
                    another_v=aux_viagens->prox;
                    if(another_v!=NULL)
                        another_aux_f=another_v->lista_amigos;
                    else
                        return l;

                    while(another_v!=NULL){
                        while(another_aux_f!=NULL){
                            if(strcmp(another_aux_f->nome,nome)==0){
                                if(another_v->h_h-aux_retorno<=0){
                                    printf("%s ESTARA EM OUTRA VIAGEM NESSE MESMO HORARIO!\n\n",nome);
                                    if(another_aux_f->prox==NULL)
                                        another_v->lista_amigos=NULL;
                                    else
                                        another_v->lista_amigos=another_aux_f->prox;
                                    free(another_aux_f);
                                    return l;
                                }
                            }
                        another_aux_f=another_aux_f->prox;
                        }
                    another_v=another_v->prox;
                    if(another_v!=NULL)
                        another_aux_f=another_v->lista_amigos;
                    }
                }
            aux_amigo=aux_amigo->prox;
            }
        aux_viagens=aux_viagens->prox;
        if(aux_viagens!=NULL)
            aux_amigo=aux_viagens->lista_amigos;
        }
    }
    /*Para checar se já existe uma viagem no mesmo horario, a função funcionar da seguinte maneira:
                    https://36.media.tumblr.com/4a202ebaa00517728293daf8ba23faa4/tumblr_nyg3oyOMp81tjjrlqo1_1280.png
        Na imagem está retratando como a lista vai estar alocada. Inicialmente o nome da pessoa a ser inserido será salvo em uma variável.
        Será enviado para a função de checagem, o novo nome, a lista com todas as viagens. A função se inicia com as variavéis 'aux_amigo'
        apontando para a primeira lista de amigos, a variavel 'aux_viagens' aponta para o inicio da lista de viagens.
        Assim começa a percorrer, enquanto 'aux_viagem' não chegar no fim. Testa a primeira lista de amigos enquanto ela for diferente de NULL,
        ira percorrer com a variavel 'aux_amigo', se houver alguem com o mesmo nome a ser inserido, a variavel 'aux_retorno' ira
        salvar o horario de que a pessoa vai retornar. Apos salvar, a variavel 'another_v' salva a lista de viagem
        se iniciando no nó seguinte, a variavel 'another_aux_f' recebe a lista de amigos desse nó. Inicia a percorrer novamente, caso exista alguem
        com o mesmo nome a ser inserido, e feita a comparação, entre o horario que a pessoa vai viajar, com o horario de retorno da viagem anterior,
        caso seja menor ou igual a zero, a pessoa vai estar em viagem e não será possível ser alocada. Mas caso o horario seja possivel, a pessoa sera
        alocada normalmente.
    */
    return l;
}


char name[50];
Viagens* mesma_viagem;
///FUNÇÕES DE INSERÇÃO DE VIAGEM
Amigo* recebe_amigos_atualizado(Amigo* l, char* nome){
    Amigo* novo=(Amigo*)malloc(sizeof(Amigo));

    strcpy(novo->nome,nome);

    ///INSERE NO INICIO
    novo->ant=NULL;
    novo->prox=l;
    l=novo;

    return l;
}
///Lista duplamente
Amigo* amigoNaViagem(Amigo* l,Amigo* all_friends,Viagens* viagens){
    int verificador=0;

    ///CASO A LISTA DE AMIGOS FOR VAZIA, RETORNARA PARA FUNÇÃO ANTERIOR
    if(all_friends==NULL){
        printf("NENHUMA PESSOA FOI CADASTRADA!\n\n");
        return NULL;
    }

    ///PERMANECERA NO LAÇO, ENQUANTO O USUARIO NAO DIGITAR UM NOME CADASTRADO PREVIAMENTE
    do{
        printf("AMIGO: ");
        setbuf(stdin,NULL);
        strupr(gets(name));
        system("cls");

        ///VERIFICA CASO USUARIO JA FOI INSERIDO
        verificador=checaAmigos(all_friends,name);

        if(verificador==0){
            printf("PESSOA NAO FOI CADASTRADA!\n\n");
        }
    }while(verificador!=1);

    l=recebe_amigos_atualizado(l,name);

    return l;
}
///Lista duplamente
Viagens* insereViagem(Viagens* l,Amigo* all_friends, Deslocamento* all_places){
    int verificador=0,h_h=0,h_m=0,r_h=0,r_m=0;
    ///verificador, VERIFICARA SE JÁ FOI CADASTRADO
    ///h_h, HORA DE IDA DA VIAGEM
    ///h_r, HORA DE RETORNO DA VIAGEM
    ///h_m, MINUTOS DA VIAGEM DE IDA
    ///r_m, MINUTOS DA VIAGEM DE RETORNO

    char cidade[30];
    Viagens* novo, *aux;

    ///CASO A LISTA DE LOCAIS CADASTRADOS ESTIVER VAZIA
    if(all_places==NULL){
        printf("NENHUM LOCAL FOI CADASTRADO!\n\n");
        return NULL;
    }

    novo=(Viagens*)malloc(sizeof(Viagens));

    ///aux, AUXILIAR QUE CONTERA A LISTA DE VIAGENS
    aux=l;

    do{
        printf("CIDADE: ");
        setbuf(stdin,NULL);
        strupr(gets(cidade));
        system("cls");

        verificador=checaViagem(all_places,cidade);

        if(verificador==0){
            printf("CIDADE NAO FOI CADASTRADA!\n");
        }
    }while(verificador!=1);

    /*o printf continuara a aparecer enquanto o usuario não digitar uma cidade que foi cadastrada previamente.
    A cidade que pretende viajar é enviada para função 'checaViagem' que retornará 0 caso não encontre nenhuma
    cidade com o mesmo nome. Caso haja alguma cidade já cadastrada, a função retornara 1, e assim o usuario
    podera prosseguir para a inserção de outros dados
    */
    do{
    printf("HORARIO DA VIAGEM(hh:mm): ");
    scanf("%d:%d",&h_h,&h_m);
    }while((h_h<=0)||(h_h>=24)||(h_m<0)||(h_m>=60));
    /*CONTINUARA PEDINDO PRA INSERIR ENQUANTO:
        HORAS MENORES DO QUE 0;
        HORAS MAIORES OU IGUAIS DO QUE 24;
        MINUTOS MENORES QUE 0;
        MINUTOS MAIORES OU IGUAIS QUE 60;
    */
    do{
        do{
            printf("HORARIO DE RETORNO(hh:mm): ");
            scanf("%d:%d",&r_h,&r_m);
            system("cls");
        }while((r_h<=0)||(r_h>=24)||(r_m<0)||(r_m>=60));
        ///CONTINUARA ENQUANTO OCORRER A MESMA COISA QUE ANTERIORMENTE
        if((r_h-h_h)<0)
            printf("HORARIO IMPOSSIVEL!\n");
        ///CASO A HORA DE RETORNO SEJA MENOR QUE A DE IDA, O HORARIO SERA IMPOSSIVEL, EX: ida 14:30, retorno 12:20
    }while((r_h-h_h)<0);

    strcpy(novo->cidade,cidade);
    novo->h_h=h_h;
    novo->h_m=h_m;
    novo->r_h=r_h;
    novo->r_m=r_m;
    ///SALVA O NOME DA CIDADE E OS HORARIOS


    ///ATÉ AGORA OS DADOS FORAM COLETADOS, A PARTIR DAQUI SERAO INSERIDOS DE ACORDO COM AS HORAS
    if(aux==NULL){
        novo->ant=NULL;
        novo->prox=NULL;

        novo->lista_amigos=NULL;

        ///CHAMA A FUNÇÃO PARA INSERIR OS AMIGOS
        novo->lista_amigos=amigoNaViagem(novo->lista_amigos,all_friends,l);

        mesma_viagem=novo;
        return novo;
    }
    else{
        while((aux!=NULL)&&(aux->h_h-h_h)<0){
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
                l=insereViagemfim(l,novo);
            }
        }

        novo->lista_amigos=NULL;

        ///CHAMA A FUNÇÃO PARA INSERIR OS AMIGOS
        novo->lista_amigos=amigoNaViagem(novo->lista_amigos,all_friends,l);

    mesma_viagem=novo;
    return l;
    }
}
///COMPLEMENTO insereViagem
Viagens* insereViagemfim(Viagens* l, Viagens* novo){
    Viagens* aux=l;

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
///Lista Circular Duplamente
Data* insereData(Data* l, int dia,int mes,int ano,Amigo* all_friends, Deslocamento* all_places){
    int opcao=0;
    Data* novo, *aux=l;

    novo=(Data*)malloc(sizeof(Data));

    novo->dia=dia;
    novo->mes=mes;
    novo->ano=ano;
    novo->lista_viagem=NULL;

    ///CHAMA A FUNÇÃO PARA PODER INSERIR A VIAGEM
    novo->lista_viagem=insereViagem(novo->lista_viagem,all_friends,all_places);
    ///RECEBE LISTA DE VIAGEM ATUALIZADA

    if(l==NULL){
        novo->prox=novo;
        novo->ant=novo;

        return novo;
    }
    else{
        do{
            aux=aux->prox;
        }while((aux!=l)&&(aux->ano<ano));
        do{
            aux=aux->prox;
        }while((aux!=l)&&(aux->mes<mes));
        do{
            aux=aux->prox;
        }while((aux!=l)&&(aux->dia<dia));

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
    do{
        printf("INSERIR MAIS ALGUEM?\n");
        printf("1-SIM\n2-NAO\n");
        printf("OPCAO: ");
        scanf("%d",&opcao);
        system("cls");

        if(opcao==1)
            mesma_viagem->lista_amigos=amigoNaViagem(mesma_viagem->lista_amigos,all_friends,l->lista_viagem);
    }while(opcao!=2);

    ///APOS SER INSERIDO NO LOCAL CORRETO, RETORNA A LISTA ATUALIZADA
    return l;
}
///CASO JA EXISTA UMA MESMA DATA ALOCADA, A FUNÇÃO VIRA PRA CA, PARA NAO PRECISAR ALOCAR OUTRO ESPAÇO NA MEMORIA
Data* insere_na_mesma_data(Data* l, int dia, int mes,int ano, Amigo* all_friends, Deslocamento* all_places){
    int opcao=0;
    Data* aux=l;

    do{
        if(aux->ano==ano){
            if(aux->mes==mes){
                if(aux->dia==dia){
                    l->lista_viagem=insereViagem(l->lista_viagem,all_friends,all_places);
                    do{
                        l->lista_viagem=checa_hora_repetida(l->lista_viagem,name);
                        printf("INSERIR MAIS ALGUEM?\n");
                        printf("1-SIM\n2-NAO\n");
                        printf("OPCAO: ");
                        scanf("%d",&opcao);
                        system("cls");

                        if(opcao==1)
                            mesma_viagem->lista_amigos=amigoNaViagem(mesma_viagem->lista_amigos,all_friends,l->lista_viagem);
                    }while(opcao!=2);

                    return l;
                }
            }
        }
        aux=aux->prox;
    }while((aux!=l));

    return l;
}
///INSERIR MAIS UM
Data* insere_mais_um(Data* l,Amigo* amigos){
    l->lista_viagem->lista_amigos=amigoNaViagem(l->lista_viagem->lista_amigos,amigos,l->lista_viagem);
    return l;
}

void gravaArquivo(Data* l, FILE* entrada){
    Data* data=l;
    Viagens* viagem=l->lista_viagem;

}


///FUNÇÕES DE IMPRESSÃO
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
        printf("%d/%d/%d\n",p->dia,p->mes,p->ano);
        while(p1!=NULL){
            if(p1!=NULL)
                p2=p1->lista_amigos;
            if(p2!=NULL){
                printf("%s. SAI AS %d:%d E RETORNA AS %d:%d\n",p1->cidade,p1->h_h,p1->h_m,p1->r_h,p1->r_m);
                while(p2!=NULL){
                    printf("%s, ",p2->nome);
                    p2=p2->prox;
                }
                printf("\n-------------------\n");
            }
            p1=p1->prox;
        }
        printf("\n---------------------------------------------------------\n");
        p=p->prox;
        p1=p->lista_viagem;
        p2=p1->lista_amigos;
    }while(p!=l);
}
