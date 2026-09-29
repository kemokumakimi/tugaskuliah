
{
    int kode;
    char nama[10], asal[15];
    int jumlahbeli, hargabeli, hargajual, terjual, sisa, untung;
} temp;

struct Buah buah[6], buah1[6] = {102, "Apel", "Malang", 25, 1750, 2000, 15, 0, 0, 103, "Jeruk", "Pontianak", 10, 1500, 3000, 10, 0, 0, 101, "Durian", "Lampung", 15, 10000, 20000, 7, 0, 0, 104, "Nanas", "Subang", 25, 3000, 5000, 8, 0, 0, 106, "Buah Naga", "DIY", 30, 2500, 3500, 15, 0, 0, 105, "Mangga", "Jawa Barat", 50, 2000, 4000, 25, 0, 0};

void SisaUntung(int n)
{
    for (int i = 0; i < n; i++)
    {
        buah[i].sisa= buah[i].jumlahbeli - buah[i].terjual;
        buah[i].untung = buah[i].terjual * (buah[i].hargajual - buah[i].hargabeli);
        printf("Sisa buah %s = %d - %d = %d\nUntung buah %s = %d*(%d - %d) = %d\n", buah[i].nama, buah[i].jumlahbeli, buah[i].terjual, buah[i].sisa, buah[i].nama, buah[i].terjual, buah[i].hargajual, buah[i].hargabeli, buah[i].untung);
    }
    
}

void OlahFile(int n, int mode)
{
    FILE *filedatabuah;

    if (mode == 1)
    {
        filedatabuah = fopen("data.txt", "w");
        fwrite(&buah1, sizeof(buah1), 1, filedatabuah);
        fclose(filedatabuah);
    }
    else if (mode == 2)
    {
        filedatabuah = fopen("data.txt", "r");
        fread(&buah, sizeof(buah), 1, filedatabuah);
        fclose(filedatabuah);
        for (int i = 0; i < n; i++)
        {
            printf("%d %s %s %d %d %d %d %d %d \n", buah[i].kode, buah[i].nama, buah[i].asal, buah[i].jumlahbeli, buah[i].hargabeli, buah[i].hargajual, buah[i].terjual, buah[i].sisa, buah[i].untung);
        }
    }
}

int main()
{
    int n;
    int mode;
    printf("Masukkan Jumlah data: ");
    scanf("%d", &n);