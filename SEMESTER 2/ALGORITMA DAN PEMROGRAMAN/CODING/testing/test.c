#include <stdio.h>
#include <string.h>

struct Buah
{
    int kode;
    char nama[10], asal[15];
    int jumlahbeli, hargabeli, hargajual, terjual, sisa, untung;
} temp;

struct Buah buah[6], buah1[6] = {102, "Apel", "Malang", 25, 1750, 2000, 15, 0, 0, 103, "Jeruk", "Pontianak", 10, 1500, 3000, 10, 0, 0, 101, "Durian", "Lampung", 15, 10000, 20000, 7, 0, 0, 104, "Nanas", "Subang", 25, 3000, 5000, 8, 0, 0, 106, "Buah Naga", "DIY", 30, 2500, 3500, 15, 0, 0, 105, "Mangga", "Jawa Barat", 50, 2000, 4000, 25, 0, 0};

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

void SisaUntung(int n)
{
    int totaluntung = 0;
    for (int i = 0; i < n; i++)
    {
        buah[i].sisa = buah[i].jumlahbeli - buah[i].terjual;
        buah[i].untung = buah[i].terjual * (buah[i].hargajual - buah[i].hargabeli);
        printf("Sisa buah %s = %d - %d = %d\nUntung buah %s = %d * (%d - %d) = %d\n", buah[i].nama, buah[i].jumlahbeli, buah[i].terjual, buah[i].sisa, buah[i].nama, buah[i].terjual, buah[i].hargajual, buah[i].hargabeli, buah[i].untung);
        totaluntung = totaluntung + buah[i].untung;
    }
    printf("Keuntungan total= %d\n\n", totaluntung);

    for (int i = 0; i < n; i++)
    {
        printf("%d %s %s %d %d %d %d %d %d \n", buah[i].kode, buah[i].nama, buah[i].asal, buah[i].jumlahbeli, buah[i].hargabeli, buah[i].hargajual, buah[i].terjual, buah[i].sisa, buah[i].untung);
    }
}

float ratarata(int n)
{
    float totalhargabeli = 0;
    float totalsisa = 0;
    float rata;

    for (int i = 0; i < n; i++)
    {
        if (buah[i].sisa != 0)
        {
            totalhargabeli += buah[i].hargabeli * buah[i].sisa;
            totalsisa = totalsisa + buah[i].sisa;
        }
    }
    rata = totalhargabeli / totalsisa;

    printf("\nMenghitung rata rata harga beli semua buah yang tersisa...\n");
    printf("Rata-rata harga beli semua buah yang masih ada adalah: %f \n\n", rata);
}

void urut(int n)
{

    int banyak = sizeof(buah) / sizeof(buah[0]);

    for (int step = 0; step < banyak - 1; step++)
    {
        for (int i = 0; i < banyak - step - 1; i++)
        {
            if (buah[i].kode > buah[i + 1].kode)
            {
                temp = buah[i];
                buah[i] = buah[i + 1];
                buah[i + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d %s %s %d %d %d %d %d %d \n", buah[i].kode, buah[i].nama, buah[i].asal, buah[i].jumlahbeli, buah[i].hargabeli, buah[i].hargajual, buah[i].terjual, buah[i].sisa, buah[i].untung);
    }
}

void cari(int n, int hargabeli, int *IX)
{
    int i = 0;
    while (i < n - 1 && buah[i].hargabeli != hargabeli)
    {
        i = i + 1;
    }
    if (buah[i].hargabeli == hargabeli){
        *IX = i;
        printf("%d %s %s %d %d %d %d %d %d \n", buah[*IX].kode, buah[*IX].nama, buah[*IX].asal, buah[*IX].jumlahbeli, buah[*IX].hargabeli, buah[*IX].hargajual, buah[*IX].terjual, buah[*IX].sisa, buah[*IX].untung);
    }
    else{
        *IX = -1;
    }

}
 
void ganti(int n, int jumlahkeuntungan, int hargabeli)
{
    for (int i = 0; i < n; i++)
    {
        if (buah[i].untung == jumlahkeuntungan)
        {
            printf("Data sebelum diganti\n");
            printf("%d %s %s %d %d %d %d %d %d \n", buah[i].kode, buah[i].nama, buah[i].asal, buah[i].jumlahbeli, buah[i].hargabeli, buah[i].hargajual, buah[i].terjual, buah[i].sisa, buah[i].untung);
            buah[i].hargabeli = hargabeli;
            printf("Data setelah diganti\n");
            printf("%d %s %s %d %d %d %d %d %d \n", buah[i].kode, buah[i].nama, buah[i].asal, buah[i].jumlahbeli, buah[i].hargabeli, buah[i].hargajual, buah[i].terjual, buah[i].sisa, buah[i].untung);
        }
        
    }
    
}

int main()
{
    int n;
    int mode;
    int hargabeli, ix;
    int jumlahkeuntungan;
    printf("Masukkan Jumlah data: ");
    scanf("%d", &n);
    fflush(stdin);
    struct Buah buah[n];
    mode = 1;
    OlahFile(n, mode);
    mode = 2;
    OlahFile(n, mode);
    printf("Perhitungan keuntungan:\n");
    SisaUntung(n);

    ratarata(n);

    urut(n);

    printf("\nBerapa harga beli buah yang ingin di cari: ");
    scanf("%d", &hargabeli);
    cari(n, hargabeli, &ix);

    printf("\nBuah dengan keuntungan berapa yang harga belinya akan di ganti? ");
    scanf("%d", &jumlahkeuntungan);
    printf("\nBuah dengan keuntungan %d akan diganti harga belinya menjadi berapa?", jumlahkeuntungan);
    scanf("%d", &hargabeli);
    ganti(n, jumlahkeuntungan, hargabeli);


    



    return 0;
}