#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nama[21],alamat[31];
    int nim;
    printf("Masukkan Nama kamu!: ");
    fgets(nama,21,stdin); fflush(stdin);
    printf("Masukkan NIM kamu!: ");
    scanf("%d",&nim);
    printf("Masukkan Alamat kamu!: ");
    fgets(alamat,31,stdin); fflush(stdin);
    printf("Nama: \nNIM: \n Alamat: \n");
    return 0;
}