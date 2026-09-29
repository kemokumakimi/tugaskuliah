

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Mahasiswa {
    char nama[50];
    int nim;
    char kelas[20];
};

void sentinel(struct Mahasiswa mahasiswa[], int n, int nim, int *ix) {
    
    mahasiswa[n].nim = nim;
    
    int i = 0;
    while (mahasiswa[i].nim != nim) {
        i++;
    }

    if (i < n) {
        *ix = i;  
    } else {
        *ix = -1; 
    }
}

int main() {
    
    int n, i, nim_cari;
    int ix;

    printf("Masukkan jumlah mahasiswa: ");
    scanf("%d", &n); fflush(stdin);
    struct Mahasiswa mahasiswa[n];

    for (i = 0; i < n; i++) {
        printf("Mahasiswa ke-%d:\n", i + 1);
        printf("Nama: ");
        fgets(mahasiswa[i].nama, 50, stdin); strtok(mahasiswa[i].nama,"\n");
        printf("NIM: ");
        scanf("%d", &mahasiswa[i].nim); fflush(stdin);
        printf("Kelas: ");
        scanf(" %s", &mahasiswa[i].kelas); fflush(stdin);
    }

    printf("\nMasukkan NIM yang ingin dicari: ");
    scanf("%d", &nim_cari);

    sentinel(mahasiswa, n, nim_cari, &ix);

    if (ix != -1) {
        printf("\nNIM ditemukan pada posisi %d\n", ix + 1);
        printf("Data Mahasiswa:\n");
        printf("Nama: %s\n", mahasiswa[ix].nama);
        printf("NIM: %d\n", mahasiswa[ix].nim);
        printf("Kelas: %s\n", mahasiswa[ix].kelas);
    } else {
        printf("\nNIM tidak ditemukan\n");
    }

    return 0;
}