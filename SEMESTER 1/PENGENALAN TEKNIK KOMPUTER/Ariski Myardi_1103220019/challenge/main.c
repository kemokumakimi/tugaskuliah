#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int harga, tanggal, kode_barang;
    float disc, total;
    char barang[20];
printf("(1)Baju\n(2)Jaket\n(3)Sepatu\n(4)Celana\n");
scanf("%d",&kode_barang); fflush(stdin);

switch(kode_barang){
case 1:
    harga=45;
    strcpy(barang,"Baju");
    printf("Masukkan tanggal transaksi: ");
    scanf("%d",&tanggal);
    switch(tanggal){
        case 12:
        disc=0.3;
        break;
        case 13 ... 31:
        disc=0.555;
        break;
        default:
        disc=0;
        break;
    }break;
case 2:
    harga=70;
    strcpy(barang,"Jaket");
    printf("Masukkan tanggal transaksi: ");
    scanf("%d",&tanggal);
    switch(tanggal){
        case 12:
        disc=0.2;
        break;
        case 13 ... 31:
        disc=0.6;
        break;
        default:
        disc=0;
        break;
}break;
case 3:
    harga=150;
    strcpy(barang,"Sepatu");
    printf("Masukkan tanggal transaksi: ");
    scanf("%d",&tanggal);
    switch(tanggal){
        case 12:
        disc=0.35;
        break;
        case 13 ... 31:
        disc=0.52;
        break;
        default:
        disc=0;
        break;
}break;
case 4:
    harga=75;
    strcpy(barang,"Celana");
    printf("Masukkan tanggal transaksi: ");
    scanf("%d",&tanggal);
    switch(tanggal){
        case 12:
        disc=0.4;
        break;
        case 13 ... 31:
        disc=0.525;
        break;
        default:
        disc=0;
        break;
    }break;
}
total=harga*(1-disc);
printf("Barang yang Anda beli %s, harga awal %d, dapat disc %.2f persen, total %.1f", barang, harga*10000, disc, total*100000);

return 0;
}