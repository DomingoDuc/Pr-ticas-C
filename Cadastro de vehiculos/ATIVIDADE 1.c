/*
Atividade A1
T�cnicas de programa��o
Aluno: Domingo Duclos
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


// struct do carro

struct st_carros{

  char marca[10];
  char modelo[20];
  int  ano_fab;
  char placa[8];
  int  aux;


}carros[10];



int main (void){

setlocale(LC_ALL,"portuguese");
// Declara��o de variaveis
int i, j,
    op,
    ano_fab = 0;
char continua,
     mod[20],
     s, n, S, N;
int count1=0,
    count2=0,
    aux,
    retorno = 0,
    ano,
    z=0,
    y=0;


// Menu principal

 printf("\n\n\n");
    inicio:
    printf("|-------------------------------------------------------------------------------------|\n");
    printf("|                                      MENU PRINCIPAL                                 |\n");
    printf("|-------------------------------------------------------------------------------------|\n");
    printf("| Entre com a opcao desejada:                                                         |\n");
    printf("|                                                                                     |\n");
    printf("|  (1) : Listar ve�culos cadastrados.                                                 |\n");
    printf("|  (2) : Inserir um novo ve�culo.                                                     |\n");
    printf("|  (3) : Listar os ve�culos filtrando-se por ano de fabrica��o.                       |\n");
    printf("|  (4) : Listar os ve�culos com ano de fab. acima de um valor digitado pelo usuario.  |\n");
    printf("|  (5) : Listar os ve�culos filtrando-se pelo modelo.                                 |\n");
    printf("|  (6) : Terminar o programa.                                                         |\n");
    printf("|\n|  Opcao: ");
    scanf("   %d", &op);

/*====================================================================*/
/* -----------------Processos e saidas -------------------------------*/

    switch(op){

        case 1:

            printf("\n\n------- VE�CULOS CADASTRADOS----------\n\n");
            for(i=0;i<z;i++){
                printf("---- Carro %d -----\n\n", i+1);
                printf("Marca:.......... %s\n",carros[i].marca);
                printf("Modelo:......... %s\n",carros[i].modelo);
                printf("Ano fabrica��o:. %d\n\n",carros[i].ano_fab);
                fflush(stdin);
                printf("N�mero placa:... %s",carros[i].placa);
                printf("\n\n---------------------------------------\n");
            }

            printf("\nDeseja voltar ao men� de inicio? (s/n)\n");
            fflush(stdin);
            scanf("%c", &continua);
            getchar();
            if(continua == 's'|| continua == 'S'){
                goto inicio;
            }else{
                goto fim;
            }
            break;

        case 2:
        z=0;
        i=0;


                do{

                    printf("\n\n======== CADASTRO DE CARROS ===========\n\n");
                    printf("\n----Carro n�mero %d\n\n", i+1);
                    printf("Digite a marca......................: ");
                    fflush(stdin);
                    fgets(carros[i].marca, 10, stdin);

                    printf("Digite o modelo.....................: ");
                    fflush(stdin);
                    fgets(carros[i].modelo, 20, stdin);

                    printf("Digite o ano de fabrica��o..........: ");
                    fflush(stdin);
                    scanf("%d", &carros[i].ano_fab);
                    for(count1=1;count1<10;count1++){
                        for(count2= 0;count2 < 9; count2++){
                            if(carros[count1].ano_fab>carros[count2].ano_fab){
                               aux=carros[count2].ano_fab;
                               carros[count2].ano_fab = carros[count1].ano_fab;
                               carros[count1].ano_fab = aux;
                            }
                        }
                     }




                    printf("Digite a placa......................: ");
                    scanf("%s", &carros[i].placa);

                    getchar();
                    printf("\n");

                    printf("\nDeseja cadastrar mais um carro? (s/n)\n");
                    fflush(stdin);
                    scanf("%c", &continua);
                    getchar();

                    i++;
                    z++;

                    if(i>9){
                        printf("\n\n--------Cantidade m�xima de ve�culos ingressados!!-----\n\n");
                        goto inicio;
                    }else{

                    }


                }while(continua == 's');
                goto inicio;


            printf("Cantidade m�xima de ve�culos ingressados!!");
            goto inicio;

        break;

        case 3:

        printf("\n\n------- VE�CULOS ORDENADOS POR ANO ----------\n\n");
            for(i=0;i<z;i++){
                printf("---- Carro %d -----\n", i+1);
                printf("\nAno fabrica��o: %d",carros[i].ano_fab);
                fflush(stdin);
                printf("\n------------------------------------------\n");
            }
            printf("\nDeseja voltar ao men� de inicio? (s/n)\n");
            fflush(stdin);
            scanf("%c", &continua);
            getchar();
            if(continua == 's'|| continua == 'S'){
                goto inicio;
            }else{
                goto fim;
            }

        break;


        case 4:

            printf("\n\n-------------VE�CULOS A PARTIR DO ANO INGRESSADO--------\n\n");
            printf("Ingresse o ano: ");
            scanf("%d", &ano);
            printf("\n");
            for(int i=0; i<z; i++){

                if(carros[i].ano_fab >= ano){
                    printf("---- Carro %d -----\n", i+1);
                    fflush(stdin);
                    printf("Marca:........... %s",carros[i].marca);
                    printf("Modelo:.......... %s",carros[i].modelo);
                    printf("Ano fabrica��o:.. %d\n",carros[i].ano_fab);
                    fflush(stdin);
                    printf("N�mero placa:.... %s",carros[i].placa);
                    printf("\n----------------------------------------\n");
                    z++;
                }


            }
            if(z==0){
                printf("\n N�O FORAM ENCONTRADO VE�CULOS ACIMA DE %d \n\n",ano);
            }else{
               z=0;
            }
            printf("\nDeseja voltar ao men� de inicio? (s/n)\n");
            fflush(stdin);
            scanf("%c", &continua);
            getchar();
            if(continua == 's'|| continua == 'S'){
                goto inicio;
            }else{
                goto fim;
            }

        break;


        case 5:
            printf("\n\n-------------VE�CULOS POR MODELO--------\n\n");
            printf("Ingresse o modelo a ser pesqui�ado: ");
            scanf("%s", &mod);
            printf("modelo ingressado: %s\n", mod);

            for(i=0; i<z;i++){

                printf("modelos ingressados anteriormente - carro %d: %s\n",i+1 , carros[i].modelo);

                retorno = strcmp(carros[i].modelo,mod);
                printf("retorno: %d\n", retorno);

                if(retorno == 0){

                    printf("\nretorno: %d", retorno);
                    printf("---- Carro %d -----\n", i+1);
                    fflush(stdin);
                    printf("\nA marca do ve�culo �:... %s",carros[i].marca);
                    fflush(stdin);
                    printf("\nO modelo do ve�culo �:.. %s",carros[i].modelo);
                    fflush(stdin);
                    printf("\nO ano do ve�culo �:..... %d",carros[i].ano_fab);
                    printf("\nA placa do ve�culo �:... %s",carros[i].placa);
                    printf("\n\n =================================== \n\n");

                    y++;

                }
            }

            if (y==0){
                printf("\nN�O FOIENCONTRADO O MODELO: %s \n\n",mod);
            }else{
                y=0;
            }
            printf("\nDeseja voltar ao men� de inicio? (s/n)\n");
            fflush(stdin);
            scanf("%c", &continua);
            getchar();
            if(continua == 's'|| continua == 'S'){
                goto inicio;
            }else{
                goto fim;
            }



        break;

        case 6:
            goto fim;
        default:

            printf("\n Op��o n�o existe\n\n");
            printf("\nDeseja voltar ao men� de inicio? (s/n)\n");
            fflush(stdin);
            scanf("%c", &continua);
            getchar();
            if(continua == 's'|| continua == 'S'){
                goto inicio;
            }else{
                goto fim;
            }








    }
fim:
system("PAUSE");
return 0;
}
