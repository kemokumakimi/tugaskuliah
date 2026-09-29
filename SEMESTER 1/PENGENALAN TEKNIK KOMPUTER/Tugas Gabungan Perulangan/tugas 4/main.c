#include <stdio.h>
int main() {
    int i,N, nilai, cacah, nomorbrs,baris;
    i=1;
    printf("masukkan jumlah  : ");
    scanf("%d", &N);
    nilai=1;
    cacah=1;
    nomorbrs=N/2+1;

    while(i<=10) {
    printf(" %d", nilai);
    nilai=nilai+2;

        if (nomorbrs==cacah) {
            cacah=1;
            printf("\n");
            nomorbrs=nomorbrs-1;


    }
     else
            cacah= cacah+1;

    i=i+1;
    }

    cacah=1;
    nomorbrs =2;
    i = 1;
    while(i<=9) {
    printf(" %d", nilai);
    nilai=nilai+2;

        if (nomorbrs==cacah) {
            cacah=1;
            printf("\n");
            nomorbrs=nomorbrs+1;


    }
     else
            cacah= cacah+1;

    i=i+1;
    }
}