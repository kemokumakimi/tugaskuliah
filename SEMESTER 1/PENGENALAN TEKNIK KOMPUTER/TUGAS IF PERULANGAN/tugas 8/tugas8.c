#include <stdio.h>
#include <stdlib.h>

int main()
{
    int j,N;
    char jenis_kelamin;
    printf("masukkan jumlah perulangan:");
    scanf("%d",&N);
    fflush(stdin);
    for (j=1;j<=N; j++) {
        printf("masukkan jenis kelamin L/P:");
        scanf("%c",&jenis_kelamin);
        fflush(stdin);
        if (jenis_kelamin=='L'){
            printf("Asrama Putra \n");
            printf("Gender anda Laki-laki \n");}
        else
            printf("Asrama Putri\n");
}
}