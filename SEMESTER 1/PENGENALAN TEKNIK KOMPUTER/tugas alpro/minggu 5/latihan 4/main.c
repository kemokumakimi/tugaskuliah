#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    struct belanjaan
    {
        char nama[30];
        int jumlah, hargaSatuan;
    };
    int n, i = 0, total = 0;
    char ulang = 't';

    do
    {
        printf("Masukkan banyak data: ");
        scanf("%d", &n);
        fflush(stdin);
        struct belanjaan brg[n];
        for (i = 0; i < n; i++)
        {
            printf("Masukkan Nama Barang: ");
            fgets(brg[i].nama, 30, stdin);
            strtok(brg[i].nama, "\n");
            printf("Masukkan Jumlah Barang: ");
            scanf("%d", &brg[i].jumlah);
            fflush(stdin);
            printf("Masukkan Harga Barang: ");
            scanf("%d", &brg[i].hargaSatuan);
            fflush(stdin);
            total += brg[i].jumlah * brg[i].hargaSatuan;
        }
        for (i = 0; i < n; i++)
        {
            printf("Nama Barang %s, Jumlah %d, Harga Satuan: %d\n", brg[i].nama, brg[i].jumlah, brg[i].hargaSatuan);
        }

        printf("total belanjaan anda: %d", total);

        printf("\nApakah anda ingin membeli lagi? (y/t): ");
        scanf("%c", &ulang);
        fflush(stdin);

    } while (ulang == 'y');

    return 0;
}
