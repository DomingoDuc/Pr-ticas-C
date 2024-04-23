/*
Atividade A1
Técnicas de programação
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
// Declaração de variaveis
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
    printf("|  (1) : Listar veículos cadastrados.                                                 |\n");
    printf("|  (2) : Inserir um novo veículo.                                                     |\n");
    printf("|  (3) : Listar os veículos filtrando-se por ano de fabricação.                       |\n");
    printf("|  (4) : Listar os veículos com ano de fab. acima de um valor digitado pelo usuario.  |\n");
    printf("|  (5) : Listar os veículos filtrando-se pelo modelo.                                 |\n");
    printf("|  (6) : Terminar o programa.                                                         |\n");
    printf("|\n|  Opcao: ");
    scanf("   %d", &op);

/*====================================================================*/
/* -----------------Processos e saidas -------------------------------*/

    switch(op){

        case 1:

            printf("\n\n------- VEÍCULOS CADASTRADOS----------\n\n");
            for(i=0;i<z;i++){
                printf("---- Carro %d -----\n\n", i+1);
                printf("Marca:.......... %s\n",carros[i].marca);
                printf("Modelo:......... %s\n",carros[i].modelo);
                printf("Ano fabricação:. %d\n\n",carros[i].ano_fab);
                fflush(stdin);
                printf("Número placa:... %s",carros[i].placa);
                printf("\n\n---------------------------------------\n");
            }

            printf("\nDeseja voltar ao menú de inicio? (s/n)\n");
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
                    printf("\n----Carro número %d\n\n", i+1);
                    printf("Digite a marca......................: ");
                    fflush(stdin);
                    fgets(carros[i].marca, 10, stdin);

                    printf("Digite o modelo.....................: ");
                    fflush(stdin);
                    fgets(carros[i].modelo, 20, stdin);

                    printf("Digite o ano de fabricação..........: ");
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
                        printf("\n\n--------Cantidade máxima de veículos ingressados!!-----\n\n");
                        goto inicio;
                    }else{

                    }


                }while(continua == 's');
                goto inicio;


            printf("Cantidade máxima de veículos ingressados!!");
            goto inicio;

        break;

        case 3:

        printf("\n\n------- VEÍCULOS ORDENADOS POR ANO ----------\n\n");
            for(i=0;i<z;i++){
                printf("---- Carro %d -----\n", i+1);
                printf("\nAno fabricação: %d",carros[i].ano_fab);
                fflush(stdin);
                printf("\n------------------------------------------\n");
            }
            printf("\nDeseja voltar ao menú de inicio? (s/n)\n");
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

            printf("\n\n-------------VEÍCULOS A PARTIR DO ANO INGRESSADO--------\n\n");
            printf("Ingresse o ano: ");
            scanf("%d", &ano);
            printf("\n");
            for(int i=0; i<z; i++){

                if(carros[i].ano_fab >= ano){
                    printf("---- Carro %d -----\n", i+1);
                    fflush(stdin);
                    printf("Marca:........... %s",carros[i].marca);
                    printf("Modelo:.......... %s",carros[i].modelo);
                    printf("Ano fabricação:.. %d\n",carros[i].ano_fab);
                    fflush(stdin);
                    printf("Número placa:.... %s",carros[i].placa);
                    printf("\n----------------------------------------\n");
                    z++;
                }


            }
            if(z==0){
                printf("\n NÃO FORAM ENCONTRADO VEÍCULOS ACIMA DE %d \n\n",ano);
            }else{
               z=0;
            }
            printf("\nDeseja voltar ao menú de inicio? (s/n)\n");
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
            printf("\n\n-------------VEÍCULOS POR MODELO--------\n\n");
            printf("Ingresse o modelo a ser pesquiçado: ");
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
                    printf("\nA marca do veículo é:... %s",carros[i].marca);
                    fflush(stdin);
                    printf("\nO modelo do veículo é:.. %s",carros[i].modelo);
                    fflush(stdin);
                    printf("\nO ano do veículo é:..... %d",carros[i].ano_fab);
                    printf("\nA placa do veículo é:... %s",carros[i].placa);
                    printf("\n\n =================================== \n\n");

                    y++;

                }
            }

            if (y==0){
                printf("\nNÃO FOIENCONTRADO O MODELO: %s \n\n",mod);
            }else{
                y=0;
            }
            printf("\nDeseja voltar ao menú de inicio? (s/n)\n");
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

            printf("\n Opção não existe\n\n");
            printf("\nDeseja voltar ao menú de inicio? (s/n)\n");
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
