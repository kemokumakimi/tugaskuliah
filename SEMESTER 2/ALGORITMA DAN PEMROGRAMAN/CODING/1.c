#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int nilai;
    char nama[40];
    char indeks;
    char komentar[20];

    printf("Masukkan nama: ");
    fgets(nama, sizeof(nama) - 1, stdin);
    nama[strcspn(nama, "\n")] = '\0'; // Hapus newline

    printf("Masukkan nilai: ");
    if (scanf("%d", &nilai) != 1)
    {
        printf("Nilai tidak valid.\n");
        return 1;
    }

    switch (nilai)
    {
    case 0 ... 39:
        indeks = 'E';
        strcpy(komentar, "Tidak mencapai nilai minimum");
        break;
    case 40 ... 49:
        indeks = 'D';
        strcpy(komentar, "Kurang");
        break;
    case 50 ... 64:
        indeks = 'C';
        strcpy(komentar, "Cukup");
        break;
    case 65 ... 79:
        indeks = 'B';
        strcpy(komentar, "Baik");
        break;
    case 80 ... 100:
        indeks = 'A';
        strcpy(komentar, "Sangat baik");
        break;
    default:
        indeks = 'X';
        strcpy(komentar, "Nilai tidak valid");
    }

    printf("Nama: %s\n", nama);
    printf("Nilai: %d\n", nilai);
    printf("Indeks: %c\n", indeks);
    printf("Komentar: %s\n", komentar);

    return 0;
}
