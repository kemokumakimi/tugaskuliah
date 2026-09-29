#include <stdio.h>
#include <string.h>

int main(){
    int uang, harga, jumlah=0,pilih,sisa;
    char barang[10];
    printf("masukan jumlah uang anda: ");
    scanf("%d",&uang);
    while (uang >= 10000){
        printf("pilih: 1.beras 10K, 2.minyak 12K, 3.gula 15K: ");
        scanf("%d",&pilih);
        switch (pilih){
            case 1: strcpy(barang, "beras"); harga=10000; break;
            case 2: strcpy(barang, "minyak"); harga=12000; break;
            case 3: strcpy(barang, "gula"); harga=15000; break;            
        }
        jumlah=uang/harga;
        sisa=uang-(harga*jumlah);
        uang=sisa;
        printf("dibeli %s, harga=%d, jumlah=%d, sisa uang=%d \n",barang, harga, jumlah, sisa);
    }
}