#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    
    int alas,tinggi, hasil;
    int n;
   
    printf("--Menghitung Luas Segitiga--");
    printf("\nmau input berapa kali?: ");
    scanf("%d", &n);

for ( int i = 0; i < n; i++)
{
   
    printf("\nmasukkan alas: ");
    scanf("%d", &alas);
    printf("masukkan tinggi: ");
    scanf("%d", &tinggi);
    hasil= 0.5 * (alas * tinggi);
    printf("luasnya adalah: %d",hasil);    
    
}



    return 0;
}
