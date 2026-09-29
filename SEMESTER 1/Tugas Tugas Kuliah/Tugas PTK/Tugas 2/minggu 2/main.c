#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Nomor;
    char Barang[20], alamat[30];
    printf("Masukkan Nomor: ");
    scanf("%d", &Nomor); fflush(stdin);
    printf("Masukkan Barang: ");
    fgets(Barang, 20, stdin);
    printf("Masukkan Alamat: ");
    fgets(alamat, 30, stdin);

    printf("\nNomor: %d\nBarang: %s Alamat: %s", Nomor, Barang, alamat);
    return 0;
}
