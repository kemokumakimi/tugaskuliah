#include <stdio.h>
#include <stdlib.h>

int main() {
    int i,N,total=0, cacah=0;
    float rata;
    printf("masukkan nilai N:\n");
    scanf("%d",&N);
    for (i=0;i<N;i++){
        printf("nilai i = %d\n",i);
        total=total+i;
        cacah=cacah+1;
        printf("total= %d \n cacah= %d \n", total, cacah);

    }
    rata=(float)total/cacah;
    printf("nilai rata-rata total = %f \n", rata);
return 0;
}   