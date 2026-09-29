
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Mahasiswa
{
    char nama[50];
    int nim;
    char kelas[20];
};

void bubblesort(struct Mahasiswa temp, struct Mahasiswa mahasiswa[], int n, int size)
{

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (mahasiswa[j].nim > mahasiswa[j + 1].nim)
            {
                temp = mahasiswa[j + 1];
                mahasiswa[j + 1] = mahasiswa[j];
                mahasiswa[j] = temp;
            }
        }
    }
}

void binarySearch(struct Mahasiswa mahasiswa[], int size, int n)
{

    int left = 0, right = size - 1, result = -1;
    int target = 0;

    printf("\nMasukkan NIM yang ingin dicari: ");
    scanf("%d", &target);

    while (left <= right)
    {

        int mid = (left + right) / 2;
        if (mahasiswa[mid].nim == target)
        {
            result = mid;
            break;
        }
        if (mahasiswa[mid].nim < target)
        {
            left = mid + 1;
        }
        else
            right = mid - 1;
        for (int i = 0; i < n; i++)
        {
            printf("mid terjadi pada: %d", mid);
        }
    }

    if (result != -1)
    {

        printf("\nNIM ditemukan pada posisi %d\n", result + 1);
        printf("Data Mahasiswa:\n");
        printf("Nama: %s\n", mahasiswa[result].nama);
        printf("NIM: %d\n", mahasiswa[result].nim);
        printf("Kelas: %s\n", mahasiswa[result].kelas);
    }
    else
    {
        printf("\nNIM tidak ditemukan\n");
    }
}

int main()
{

    int n, i, nim_cari;
    struct Mahasiswa temp;

    printf("Masukkan jumlah mahasiswa: ");
    scanf("%d", &n);
    fflush(stdin);
    struct Mahasiswa mahasiswa[n];
    int size = sizeof(mahasiswa) / sizeof(mahasiswa[0]);

    for (i = 0; i < n; i++)
    {
        printf("Mahasiswa ke-%d:\n", i + 1);
        printf("Nama: ");
        fgets(mahasiswa[i].nama, 50, stdin); strtok(mahasiswa[i].nama,"\n");
        printf("NIM: ");
        scanf("%d", &mahasiswa[i].nim);
        fflush(stdin);
        printf("Kelas: ");
        scanf(" %s", &mahasiswa[i].kelas); fflush(stdin);
    }

    bubblesort(temp, mahasiswa, n, size);
    binarySearch(mahasiswa, size, n);

    return 0;
}