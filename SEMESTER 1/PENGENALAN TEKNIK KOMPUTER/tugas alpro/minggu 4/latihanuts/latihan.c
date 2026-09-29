#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int jmlduit, pilmenu, batagor, harga1, harga2, harga3;
    char lanjut = 'y';

    printf("Masukkan Uang: ");
    scanf("%d", &jmlduit);
    printf("jumlah duit: %d\n", jmlduit);

    do
    {
        printf("\npilihan: 1. Batagor (1000), 2. Soto (2000), 3. Bakso (3000)\nPilih: ");
        scanf("%d", &pilmenu);

        switch (pilmenu)
        {
            case 1:
                harga1 = 1000;
                printf("Batagor: 1. Kuah  2. Kering: ");
                scanf("%d", &batagor);
                if (batagor == 1)
                {
                    printf("pengeluaran anda: Batagor kuah dengan harga 1000");
                }
                else if (batagor == 2)
                {
                    printf("pengeluaran anda: Batagor kering dengan harga 1000");
                }
                jmlduit = jmlduit - harga1;
                break;

            case 2:
                harga2 = 2000;
                printf("pengeluaran anda: Soto dengan harga 2000");
                jmlduit = jmlduit - harga2;
                break;

            case 3:
                harga3 = 3000;
                printf("pengeluaran anda: Bakso dengan harga 3000");
                jmlduit = jmlduit - harga3;
                break;

            default:
                break;
        }

        if (jmlduit > 1000)
        {
            printf("\nsisa uang anda %d. Pilih menu lain? (y/t): ", jmlduit);
            scanf(" %c", &lanjut);
        }
        else if (jmlduit < 1000)
        {
            printf("\nsisa uang anda %d, tidak bisa memilih lagi.\n", jmlduit);
            break;
        }

    } while (lanjut == 'y');


    printf("Terima Kasih sudah ke Warung kami");
    return 0;
}
