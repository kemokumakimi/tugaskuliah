#include <stdio.h>
#include <stdlib.h>

main()
{
    char nama1[40],nama2[40],jeniskelamin1,jeniskelamin2;
    int nilai1, nilai2,jmlnilai;

    printf("Masukkan Nama Mahasiswa: ");
    fgets(nama1,40,stdin);
    printf("Masukkan Jenis Kelamin L/P: ");
    scanf("%c", &jeniskelamin1);
    fflush(stdin);
    printf("Masukkan Nilai mhs: ");
    scanf("%d", &nilai1);
    fflush(stdin);
    printf("Masukkan Nama Mahasiswa: ");
    fgets(nama2,40,stdin);
    printf("Masukkan Jenis Kelamin L/P:");
    scanf("%c", &jeniskelamin2);
    fflush(stdin);
    printf("Masukkan Nilai mhs: ");
    scanf("%d", &nilai2);
    fflush(stdin);
    printf("Data Mahasiswa-1: nama %s, jenis kelamin %c, nilai:%d, \nData Mahasiswa-2: nama %s, jenis kelamin %c, nilai:%d\nJumlah Nilai Mahasiswa adalah:%d", nama1,jeniskelamin1,nilai1,nama2,jeniskelamin2,nilai2,nilai1+nilai2);
    return 0;
}