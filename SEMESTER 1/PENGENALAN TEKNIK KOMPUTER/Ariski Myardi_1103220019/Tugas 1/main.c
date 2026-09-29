#include <stdio.h>
#include <stdlib.h>

int main()
{
    char NAMA[15];
    char UMUR[15];
    int ANAKKE,SAUDARA,BANYAKSAUDARA;
    printf("Masukkan Nama: ");
    scanf("%s",NAMA);
    printf("Masukkan Umur: ");
    scanf("%s", UMUR);
    printf("Ada berapa saudara? ");
    scanf("%d",&SAUDARA);
    BANYAKSAUDARA=SAUDARA+1;
    printf("Anak ke? ");
    scanf("%d",&ANAKKE);
    printf("Saya %s, Umur %s tahun, saya anak-ke %d, dan mempunya %d saudara", NAMA,UMUR,ANAKKE,BANYAKSAUDARA);
    return 0;
}
