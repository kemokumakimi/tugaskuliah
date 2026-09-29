#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,N,Total=0,Cacah=0;
    float Rata;
    printf("masukkan jumlah perulangan:");
    scanf("%d",&N);
    for (i=0;i<N;i++){
        printf("nilai saat ini = %d \n",i);
        if (i % 2 == 0) {
            Total=Total+i;
            Cacah=Cacah+1;
            printf("nilai genap maka di Cacah dan di Total\n");
            printf("Total = %d\n",Total);
            printf("Cacah = %d\n\n",Cacah);
        }else printf("nilai bukan genap, tidak perlu di Cacah dan di Total\n\n");
    }
    Rata=(float)Total/Cacah;
    printf("Rata-rata =%f:\n",Rata);
}