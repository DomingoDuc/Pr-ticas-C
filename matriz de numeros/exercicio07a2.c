#include <stdio.h>
#include <stdlib.h>


int main(){

int mat[5][7]={0}, i=1, k, l, c, num;


while(1){

    for(i=1;i<=4;i++){
        printf("\t-------------------------------------------------");
        putchar('\n');
        for(k=1;k<=6;k++){
            printf("\t|%3d", mat[i][k]);

        }
    printf("    |");
    putchar('\n');

    }
    printf("\t-------------------------------------------------");

    putchar('\n');
    printf("linha:  ");
    scanf("%d", &l);
    printf("coluna: ");
    scanf("%d",&c);
    printf("Agora ingresse um numero entre 0 e 999: ");
    scanf("%d", &num);
    system("CLS");

    if (num>0 || num<999){
      mat[l][c]=num;

    }

}
return 0;
}
