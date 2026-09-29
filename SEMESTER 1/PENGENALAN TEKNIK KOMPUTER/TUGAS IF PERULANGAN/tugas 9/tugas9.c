#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, N, nilai, cacahtampil, nomorbaris;
    i=1;
    printf("masukkan jumlah bilangan: \n");
    scanf("%d",&N);
    nilai=1;
    cacahtampil =1;
    nomorbaris=1;
    while (i<=N) {
    printf("%d",nilai);
    nilai=nilai+1;
        if ( nomorbaris==cacahtampil) {
            cacahtampil =1;
            printf("\n");
            nomorbaris= nomorbaris+1;
        } else{
            cacahtampil = cacahtampil +1;
        }
    i=i+1;
    }
   printf("\n");
}
