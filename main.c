#include "viagens.h"

int main()
{
    FILE *entrada;

    entrada=fopen("Arquivo_das_viagens.txt","a+");

    Amigo *amigos;
    //*amigos, SALVA A LISTA DE TODOS AMIGOS

    Deslocamento *deslocamentos;
    //*deslocamentos, SALVA A LISTA DE TODOS DESLOCAMENTOS

    Data *dias;
    //*dias, LISTA COM DIAS DAS VIAGENS

    amigos=criaAmigo();
    deslocamentos=criaDeslocamento();
    dias=criaNo();

    int opcao=0,verificador=0, verificador2=0, info1=0,info2=0,info3=0,k=0;
    /*opcao, COLETA AS OPCOES DO USUARIO
      verificadores, IRAO COLETAR CERTAS INFORMACOES PARA SEREM VERIFICADAS
    */

    char informa1[50], informa2[50], informa3[50];
    //informa1,2,3, SALVARAO DADOS FORNECIDOS PELO USUARIO

    do
    {
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
        switch(opcao)
        {
        //CASE 1 E PARA INSERÇÃO DE PESSOAS
        case 1:
            printf("NOME: ");
            setbuf(stdin,NULL);
            strupr(gets(informa1));
            /*
            O verificador e a variavel que contera o valor da funçao checaAmigos.
            Essa funçao tem como objetivo checar toda a lista de amigos, e verificar se o novo amigo a ser inserido
            ja existe. Caso exista alguem com mesmo nome, o verificador passara a valer 1. Caso contrario continuara com 0.
            */
            verificador=checaAmigos(amigos,informa1);
            if(verificador==0)
            {
                printf("TELEFONE: ");
                setbuf(stdin,NULL);
                gets(informa2);
                printf("EMAIL: ");
                setbuf(stdin,NULL);
                gets(informa3);
            }
            else
            {
                printf("NOME JA CADASTRADO!\n\n");
                break;
            }
            //DADOS SAO ENVIADOS PARA FUNCAO
            amigos=insereAmigo(amigos,informa1,informa2,informa3);
            system("cls");
            break;

        //CASE 2 E PARA A INSERÇÃO DE DESLOCAMENTOS
        case 2:
            //Pergunta para verificar se é uma viagem para o exterior, tais casos afetarao a inserção da informação
            printf("VIAGEM PARA EXTERIOR?\n");
            printf("1-SIM\n2-NAO\n");
            printf("OPCAO: ");
            scanf("%d",&verificador2);
            system("cls");

            //CASO SEJA UMA VIAGEM PARA O EXTERIOR
            if(verificador2==1)
            {
                printf("NOME CIDADE: ");
                setbuf(stdin,NULL);
                strupr(gets(informa1));

                /*
                O verificador e a variavel que contera o valor da funçao checaViagem.
                Essa funçao tem como objetivo checar toda a lista de cidades, e verificar se a nova cidade a ser inserida
                ja existe. Caso exista alguma com mesmo nome, o verificador passara a valer 1. Caso contrario continuara com 0.
                */
                verificador=checaViagem(deslocamentos,informa1);

                if(verificador==0)
                {
                    printf("PAIS: ");
                    setbuf(stdin,NULL);
                    strupr(gets(informa2));

                    //POR SER VIAGEM AO EXTERIOR, NÃO É NECESSARIO O NOME DO ESTADO, QUE SERA SUBSTITUIDO POR -
                    strcpy(informa3,"-");

                    //ENVIO DE DADOS PARA INSERÇÃO
                    deslocamentos=insereDeslocamento(deslocamentos,informa1,informa2,informa3);
                    system("cls");
                }
                else
                {
                    printf("CIDADE JA CADASTRADA!\n\n");
                    break;
                }
            }

            //CASO NÃO SEJA UMA VIAGEM PARA EXTERIOR
            else
            {
                printf("NOME CIDADE: ");
                setbuf(stdin,NULL);
                strupr(gets(informa1));

                /*
                O verificador e a variavel que contera o valor da funçao checaViagem.
                Essa funçao tem como objetivo checar toda a lista de cidades, e verificar se a nova cidade a ser inserida
                ja existe. Caso exista alguma com mesmo nome, o verificador passara a valer 1. Caso contrario continuara com 0.
                */
                verificador=checaViagem(deslocamentos,informa1);

                if(verificador==0)
                {
                    printf("ESTADO: ");
                    setbuf(stdin,NULL);
                    strupr(gets(informa3));

                    strcpy(informa2,"BRASIL");

                    //ENVIA DADOS PARA SEREM INSERIDOS
                    deslocamentos=insereDeslocamento(deslocamentos,informa1,informa2,informa3);
                    system("cls");
                }
                else
                {
                    printf("CIDADE JA CADASTRADA!\n\n");
                    break;
                }
            }
            break;

            //CASE 3 E PARA O CADASTRAMENTO DE VIAGENS
            case 3:

                printf("DIA(dd/mm/aaaa): ");
                scanf("%d/%d/%d",&info1,&info2,&info3);

                /*
                O verificador e a variavel que contera o valor da funçao checaData.
                Essa funçao tem como objetivo checar toda a lista de datas, e verificar se a nova data a ser inserida
                ja existe. Caso exista alguma no mesmo dia, o verificador passara a valer 1. Caso contrario continuara com 0.
                */

                verificador=checaData(dias,info1,info2,info3);

                if(verificador==0){
                    dias=insereData(dias,info1,info2,info3,amigos,deslocamentos);
                    if(k==0){
                        do{
                            k++;
                            printf("INSERIR MAIS ALGUEM?\n");
                            printf("1-SIM\n2-NAO\n");
                            printf("OPCAO: ");
                            scanf("%d",&verificador2);
                            system("cls");
                            if(verificador2==1)
                                dias=insere_mais_um(dias,amigos);
                        }while(verificador2!=2);
                    }
                }
                if(verificador==1){
                    dias=insere_na_mesma_data(dias,info1,info2,info3,amigos,deslocamentos);
                }
                break;

            case 4:
                imprimeAmigos(amigos);
                printf("\n\n\n");
                imprimeDeslocamento(deslocamentos);
                printf("\n\n\n");
                break;
            case 5:
                imprimeViagem(dias);
                break;
        }
    }while(opcao!=8);

return 0;
}

