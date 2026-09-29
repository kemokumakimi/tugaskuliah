#include <stdio.h>
#include <stdlib.h>

int main()
{
    int harga_roti, uang, roti, kembalian;
    printf("Harga roti: ");
    scanf("%d",&harga_roti);
    printf("Masukkan Nilai Uang: ");
    scanf("%d", &uang);
    roti=uang/harga_roti;
    kembalian=uang%harga_roti;
    if (roti>=1){
        printf("Dapat %d roti, kembalian %d", roti,kembalian);
    }
    else {
        printf("Tidak dapat roti,  dikembalikan semua");
    }
    return 0;
}