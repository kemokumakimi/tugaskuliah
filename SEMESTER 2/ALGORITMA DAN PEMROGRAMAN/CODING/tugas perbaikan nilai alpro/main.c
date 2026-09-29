#include <stdio.h>
#include <string.h>

struct Buah
{
    int kode;
    char nama[10], asal[15];
    int jumlahbeli, hargabeli, hargajual, terjual, sisa, untung;
} temp;
struct Buah buah[6], databuah[6] = {
    102, "Apel", "Malang", 20, 1750, 2000, 6, 0, 0,
    103, "Jeruk", "Pontianak", 10, 1500, 3000, 5, 0, 0, 
    101, "Durian", "Lampung", 15, 10000, 20000, 7, 0, 0, 
    104, "Nanas", "Subang", 25, 3000, 5000, 8, 0, 0, 
    106, "Buah Naga", "DIY", 30, 2500, 3500, 15, 0, 0, 
    105, "Mangga", "Jawa Barat", 50, 2000, 4000, 25, 0, 0};

void olahFile(int n, int mode)
{
    if (mode == 1)
    {
        FILE *filedatabuah;
        filedatabuah = fopen("databuah.txt", "w");
        fwrite(&databuah, sizeof(databuah), 1, filedatabuah);
        printf("Menulis File...\n");
        printf("Hasil pembacaan file: \n");
        for (int i = 0; i < n; i++)
        {
            printf("%d %s %s %d %d %d %d %d %d\n", buah[i].kode, buah[i].nama, buah[i].asal, buah[i].jumlahbeli, buah[i].hargajual, buah[i].terjual, buah[i].sisa, buah[i].untung);
        }
        
    }
    else if (mode == 2)
    {
        FILE *filedatabuah;
        filedatabuah = fopen("databuah.txt", "r");
        fread(&databuah, sizeof(databuah), 1, filedatabuah);
    }
}

int main()
{

    int mode;
    int n;
    printf("Masukkan Banyak Data: ");
    scanf("%d", &n);
    fflush(stdin);
    mode = 1;
    olahFile(n, mode);
    mode = 2;
    olahFile(n, mode);

        return 0;
}