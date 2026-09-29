#include <stdio.h>
#include <stdlib.h>

void persegipanjang(int p, int l, int *luaspersegipanjang)
{

    *luaspersegipanjang = p * l;
}

void persegi(int p, int l, int *luaspersegi)
{
    *luaspersegi = p * p;
}

int main()
{
    int pilihan, panjang, lebar, luas;
    printf("Masukkan Panjang: ");
    scanf("%d", &panjang);
    printf("Masukkan lebar: ");
    scanf("%d", &lebar);

    printf("masukkan pilihan hitung anda:\n1. luas persegi panjang \n2. luas persegi kotak\nmasukan: ");
    scanf("%d", &pilihan);

    switch (pilihan)
    {
    case 1:
        persegipanjang(panjang, lebar, &luas);
        break;

    case 2:
        persegi(panjang, lebar, &luas);
    default:
        break;
    }

    printf("maka luasnya adalah: %d", luas);

    return 0;
}