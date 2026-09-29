#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A,B,C,D,E;
    printf("Masukkan Nilai sisi= ");
    scanf("%d",&A);
    C=A*A;
    printf("Luas Persegi= %d\n",C);
    D=C*1/2;
    printf("Luas Segitiga= %d\n",D);
    E=C-D;
    printf("Jadi luas area merah adalah= %d",E);
    return 0;
}
