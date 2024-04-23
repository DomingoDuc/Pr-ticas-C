#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include <time.h>

#define TAM 10

// ===================== DECLARAÇÃO DE FUNÇÕES =====================

int menu();
void listar();
void preencher();
struct cadastro{

    char nome[30];
    int  ano_nac;
    float  m_mes;

}cliente[10];


// ======================= FUNÇÃO PRINCIPAL============================

int main(void){

setlocale(LC_ALL,"portuguese");

preencher();

static int A;
int i, j, r, op;
char s, continua, nom[30];
int retn;
int num = 0;
float soma, aux, maior;

struct cliente *str = (struct cliente *)malloc(10 *sizeof(cliente));


 printf("\n\n\n");
    inicio:
    printf("|-------------------------------------------------------------------------------------|\n");
    printf("|                                      MENU PRINCIPAL                                 |\n");
    printf("|-------------------------------------------------------------------------------------|\n");
    printf("|   Entre com a opção desejada:                                                       |\n");
    printf("|   (1) : Cadastrar novo cliente                                                      |\n");
    printf("|   (2) : Remover cliente                                                             |\n");
    printf("|   (3) : Atualizar o montante de compras do cliente (do mês atual)                   |\n");
    printf("|   (4) : Zerar todos os montantes de compras (virada do mês)                         |\n");
    printf("|   (5) : Listar o cliente melhor comprador                                           |\n");
    printf("|   (6) : Exibir um montante de compras de um cliente específico                      |\n");
    printf("|   (7) : Sair do programa                                                            |\n");
    printf("|-------------------------------------------------------------------------------------|\n");
    printf("\n\t>> ");
    scanf("%d", &op);
    system("CLS");


    switch(op)
{
    case 1:
        i=TAM;
        r=0;
        A = 0;

        do{
        A++;
        str = realloc(str, 20* sizeof(cliente));
        printf("\n\n=======  CADASTRAR NOVO CLIENTE =========\n\n");

        printf("Ingresse o nome do cliente: ");
        fflush(stdin);
        fgets(cliente[i].nome,30,stdin);


        printf("Ingresse o ano de nascimento: ");
        fflush(stdin);
        scanf("%d", &cliente[i].ano_nac);
        fflush(stdin);

        printf("Ingresse o montante de gastos no mês atual: ");
        fflush(stdin);
        scanf("%f", &cliente[i].m_mes);

        i++;

        printf("\nDeseja cadastrar mais um cliente? (s/n)\n");
        fflush(stdin);
        scanf("%c", &continua);




        getchar();
         }while(continua == 's');
        system("CLS");
        goto inicio;


    break;

    case 2:

        do{
        num = 0;

        printf("\n\n=======  REMOVER CLIENTE =========\n\n");

        listar(A);

        printf("\nDigite o numero do cliente: \n\n ");
        scanf("%d", &num);
        num -=1;

        for(i=0; i<TAM;i++)
            {
               strcpy(cliente[num].nome, "\0");
            }

        cliente[num].ano_nac = 0;
        cliente[num].m_mes   = 0;

        fflush(stdin);

        system("cls");
        fflush(stdin);

        listar(A);
        puts("\n");
        printf("\nDeseja remover mais um cliente? (s/n)\n");
        fflush(stdin);
        scanf("%c", &continua);
        getchar();

         }while(continua == 's');
        system("CLS");
        goto inicio;

    break;

    case 3:

        do{
        num = 0;
        soma = 0;
        printf("\n\n=======  ATUALIZAR MONTANTE DE COMPRAS =========\n\n");
        listar(A);
        printf("\nDigite o numero de cliente: \n\n ");
        scanf("%d", &num);
        num -=1;
        system("cls");
        printf("Foi selecionado o cliente:    %s\n", cliente[num].nome);
        printf("Montante atual de este mês é: %.2f\n", cliente[num].m_mes);
        printf("Quanto deseja acresentar?\n");
        scanf("%f", &soma);

        cliente[num].m_mes += soma;

        printf("Montante atualizado para:     %.2f\n", cliente[num].m_mes);

        printf("\nDeseja atualizar mais um cliente? (s/n)\n");
        fflush(stdin);
        scanf("%c", &continua);
        getchar();

         }while(continua == 's');
        system("CLS");
        goto inicio;


    break;

    case 4:
        i =0;
        do{

        printf("\n\n=======  ZERAR MONTANTE DE COMPRAS =========\n\n");

        listar(A);

        printf("\nDigite o numero de cliente: \n\n ");
        scanf("%d", &num);
        num -=1;
        system("cls");
        printf("Foi selecionado o cliente:    %s\n", cliente[num].nome);
        printf("Montante atual de este mês é: %.2f\n", cliente[num].m_mes);
        cliente[i].m_mes = 0;

        printf("Monto zerado!!");

        printf("\nDeseja atualizar mais um cliente? (s/n)\n");
        fflush(stdin);
        scanf("%c", &continua);
        getchar();
         }while(continua == 's');
        system("CLS");
        goto inicio;


    break;

    case 5:

        r = 0;

        printf("\n\n=======  LISTAR O CLIENTE MELHOR COMPRADOR =========\n\n");

        for(i=0;i<TAM;i++)
        {
            if(cliente[i].m_mes>maior)
            {
                maior=cliente[i].m_mes;
                r=i;
            }
        }
        printf("\nNome do melhor comprador: %s", cliente[r].nome);
        printf("\nMontante: R$ %.2f", cliente[r].m_mes);


        puts("\n");
        system("pause");
        system("cls");
        goto inicio;

    break;


    case 6:
        do{
        i=TAM;

        printf("\n\n=======  EXIBIR UM MONTANTE DE COMPRAS DE UM CLIENTE ESPECIFICO =========\n\n");
        printf("Ingresse o nome do cliente: ");
        scanf("%s", nom);
        printf("\nnome ingressado: %s\n", nom);

        for(i=0;i<TAM;i++){

            retn = strcmp(cliente[i].nome,nom);
            r=i;
            if(retn == 0)
            {

                printf("Nome do cliente:           %s\n", cliente[r].nome);
                printf("Montante de compras atual: %.2f\n", cliente[r].m_mes);

            }
        }
        printf("\nDeseja pesquisar mais um cliente? (s/n)\n");
        fflush(stdin);
        scanf("%c", &continua);
        getchar();
        system("CLS");
        }while(continua == 's');
        system("CLS");
        goto inicio;

    break;

    case 7:

        i=TAM+1;
        system("CLS");
        printf("\n\n=======  SAIR DO PROGRAMA =========\n\n");


    break;
}

free(str);

return 0;
}

 // ======================== CORPO DAS FUNÇÕES ===========================

void listar(int A)
{

int i;
printf("\n");
printf("\n=========== LISTA DE CLIENTES =================\n");
fflush(stdin);
for(i=0;i<TAM+A;i++)
{
    printf("\n------ Cliente: [%d]-------", i+1);
    printf("\n\n- Nome: ..................%s\n- Ano de nacimento: ......%d\n- Gastos no mês atual: ...%.2f",
           cliente[i].nome, cliente[i].ano_nac, cliente[i].m_mes);
    printf("\n");
}

}

void preencher(){

    int i;

     for(i=0;i<10;i++){
        strcpy(cliente[0].nome, "Pedro" );
        strcpy(cliente[1].nome, "Tom");
        strcpy(cliente[2].nome, "Carlo");
        strcpy(cliente[3].nome, "John");
        strcpy(cliente[4].nome, "Samuel");
        strcpy(cliente[5].nome, "Sandra");
        strcpy(cliente[6].nome, "Diego");
        strcpy(cliente[7].nome, "Jorge");
        strcpy(cliente[8].nome, "Fernanda");
        strcpy(cliente[9].nome, "Julia");


    }

    cliente[0].ano_nac = 1945;
    cliente[1].ano_nac = 1956;
    cliente[2].ano_nac = 1936;
    cliente[3].ano_nac = 1978;
    cliente[4].ano_nac = 1904;
    cliente[5].ano_nac = 1989;
    cliente[6].ano_nac = 2003;
    cliente[7].ano_nac = 1856;
    cliente[8].ano_nac = 1948;
    cliente[9].ano_nac = 1999;

    cliente[0].m_mes =  14.67;
    cliente[2].m_mes =  445.70;
    cliente[1].m_mes =  990.10;
    cliente[3].m_mes =  56.00;
    cliente[4].m_mes =  24.50;
    cliente[5].m_mes =  568.00;
    cliente[6].m_mes =  1200.00;
    cliente[7].m_mes =  45.70;
    cliente[8].m_mes =  4450.00;
    cliente[9].m_mes =  12.45;

}


