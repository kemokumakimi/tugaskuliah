#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int duit, pilihan, pilbatagor, hargaMenu, total = 0;
    char lanjut = 't';

    printf("Masukkan Jumlah duit: ");
    scanf("%d", &duit);
    do
    {

        printf("pilihan 1. Batagor(1000), 2. Soto (2000), 3. Bakso (3000)");
        printf("\npilih: ");
        scanf("%d", &pilihan);
        fflush(stdin);
        switch (pilihan)
        {
        case 1:
            printf("Batagor:\n1. Kuah\n2. Kering\n ");
            scanf("%d", &pilbatagor);
            fflush(stdin);
            if (pilbatagor == 1)
            {
                printf("Pengeluaran Anda : Batagor kuah dengan harga 1000");
                hargaMenu = 1000;
            }
            else if (pilbatagor == 2)
            {
                printf("Pengeluaran Anda : Batagor kering dengan harga 1000");
                hargaMenu = 1000;
            }

            break;
        case 2:
            printf("Pengeluaran Anda : Soto dengan harga 2000");
            hargaMenu = 2000;

            break;

        case 3:
            printf("Pengeluaran Anda : Bakso dengan harga 3000");
            hargaMenu = 3000;
            break;
        }

        duit = duit - hargaMenu;

        if (duit < 0)
        {
            printf("\nuang anda sudah habis:(");
            lanjut = 't';
        }
        else if (duit < 1000)
        {
            printf("\nsisa uang anda: %d", duit);
            fflush(stdin);
            printf("uang anda sudah habis, tidak bisa memilih lagi.");
            lanjut = 't';
        }
        else
        {
            printf("\nsisa uang anda: %d", duit);
            fflush(stdin);
            printf("\nPilih menu lain? (y/t): ");
            scanf("%c", &lanjut);
            fflush(stdin);
        }

    } while (lanjut == 'y');

    return 0;
}