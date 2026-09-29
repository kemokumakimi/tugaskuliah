#include <stdio.h>
#include <stdlib.h>

int main()
{
    float umur, pecahan, nomor, angka;
    printf("Masukkan Umur: ");
    scanf("%f",&umur);
    printf("Masukkan Bulan: ");
    scanf("%f", &angka);
    pecahan=angka/12;
    printf("nomor baju: ");
    scanf("%f", &nomor);
    printf("Umur %f, pecahan %f, Nomor %f", umur, pecahan, nomor);
    return 0;
}
