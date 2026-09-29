#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i,N,ind;
    float bobot,tot=0,sks,IPK,sks2=0;
    char mk[100],indeks[100];
    printf("Masukkan jumlah matkul : ");
    scanf("%d",&N);fflush(stdin);

    while(i<N){
        printf("Masukkan Matkul : ");
        scanf("%s",mk);fflush(stdin);
        printf("Masukkan sks : ");
        scanf("%f",&sks);fflush(stdin);
        printf("masukkan indeks nilai (A/AB/B/BC/C/D/E): ");
        scanf("%s",indeks);fflush(stdin);
            if(strcmp(indeks,"A")==0){
                ind=1;
            }
            else if (strcmp(indeks,"AB")==0){
                ind=2;
            }else if (strcmp(indeks,"B")==0){
                ind=3;
            }else if (strcmp(indeks,"BC")==0){
                ind=4;
            }else if (strcmp(indeks,"C")==0){
                ind=5;
            }else if (strcmp(indeks,"D")==0){
                ind=6;
            }else if (strcmp(indeks,"E")==0){
                ind=7;
            }
            switch(ind){
                case 1 : bobot=4;break;
                case 2 : bobot=3.5;break;
                case 3 : bobot=3;break;
                case 4 : bobot=2.5;break;
                case 5 : bobot=2;break;
                case 6 : bobot=1;break;
                case 7 : bobot=0;break;
                }
            sks2=sks2+sks;
            tot=tot+(bobot*sks);
            i++;
            printf("%s %s %f\n",mk,indeks,bobot);
            }
    IPK=tot/sks2;
    printf("Total IPK = %.3f",IPK);
    return 0;
}
