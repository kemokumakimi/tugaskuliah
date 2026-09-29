#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nama[21],alamat[31];
    printf("Masukkan Nama: ");
    fgets(nama,21,stdin); fflush(stdin);
    printf("Masukkan Alamat: ");
    fgets(alamat,31,stdin); fflush(stdin);
    printf("\nNama:%sAlamat:%s\n", nama, alamat);

    return 0;
}