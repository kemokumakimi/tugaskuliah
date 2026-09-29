#include <stdio.h>
#include <stdlib.h>

int main()
{
    int pilih,rumus1,alas,tinggi,jaw;
    printf("Selamat Datang\n");
    printf("Silahkan Pilih Rumus\n");
    printf("1. Rumus Segitiga\n");
    printf("2. Rumus Persegi\n");
    printf("3. Rumus Tabung\n")
    printf("Masukkan Nomor Pilihan\n");
    scanf("%d", &pilih);
    fflush(stdin);

    if (pilih==1)
    {
        printf("Rumus Segitiga Ready\n");
        printf("Masukkan Alas dan Tinggi\n");
        scanf("%d %d", &alas, &tinggi);
        jaw=alas*tinggi/2;
        printf("Jawabannya: %d", jaw);
    }
    else if (pilih==2)
    {
        printf("Rumus Luas Persegi Ready\n");
        printf("Masukkan Lebar dan Tinggi\n");
        scanf("%d %d", &alas, &tinggi);
        jaw=2*(alas*tinggi);
        printf("Jawabannya: %d", jaw);
    }
    else if (pilih==3)
    {
        printf("Rumus Tabung Ready\n");
        printf("Masukkan radius\n");
        scanf("%d", &alas);
        jaw=3,14*(alas*alas);
        printf("Jawabannya: %d", jaw);
    }
    else
    return 0;
}
