#include "viagens.h"

int main()
{
    Amigo *amigos;
    //*amigos, SALVA A LISTA DE TODOS AMIGOS
    Deslocamento *deslocamentos;
    //*deslocamentos, SALVA A LISTA DE TODOS DESLOCAMENTOS
    No *dias;
    //*dias, LISTA COM DIAS DAS VIAGENS

    amigos=criaAmigo();
    deslocamentos=criaDeslocamento();
    dias=criaNo();


    int opcao=0,verificador=0;
    //opcao, COLETA AS OPCOES DO USUARIO

    char informa1[50], informa2[50], informa3[50];
    //informa1,2,3, SALVARAO DADOS FORNECIDOS PELO USUARIO

    do{
        printf("1-INSERIR AMIGO\n");
        printf("2-INSERIR DESLOCAMENTO\n");
        printf("3-INSERIR VIAGEM\n");
        printf("4-CANCELAR VIAGEM\n");
        printf("5-DESISTENCIA DE AMIGO\n");
        printf("6-PESQUISAR VIAGENS POR INTEVALOS DE DIAS\n");
        printf("7-VIAGENS DE UM AMIGO\n");
        printf("8-SAIR\n");
        printf("OPCAO: ");
        scanf("%d",&opcao);
        system("cls");

        //APOS A COLETA DA OPCAO, INICIA O QUE DEVE SER FEITO
        switch(opcao){
            case 1:
                printf("NOME: ");
                setbuf(stdin,NULL);
                gets(informa1);
                /*
                O verificador e a variavel que contera o valor da funçao checaAmigos.
                Essa funçao tem como objetivo checar toda a lista de amigos, e verificar se o novo amigo a ser inserido
                ja existe. Caso exista alguem com mesmo nome, o verificador passara a valer 1. Caso contrario continuara com 0.
                */
                verificador=checaAmigos(amigos,informa1);
                if(verificador==0){
                    printf("TELEFONE: ");
                    setbuf(stdin,NULL);
                    gets(informa2);
                    printf("EMAIL: ");
                    setbuf(stdin,NULL);
                    gets(informa3);
                }
                else{
                    printf("NOME JA CADASTRADO!");
                    break;
                }
                //DADOS SAO ENVIADOS PARA FUNCAO
                amigos=insereAmigo(amigos,informa1,informa2,informa3);
                system("cls");
                break;
        }

    }while(opcao!=8);

    return 0;
}
