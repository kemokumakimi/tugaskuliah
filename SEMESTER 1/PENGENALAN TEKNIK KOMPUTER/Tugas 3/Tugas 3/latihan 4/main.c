#include <stdio.h>
#include <stdlib.h>

main()
{
    char barang[20],alamat[30];
    
    printf("Nama Barang: ");
    fgets(barang,20,stdin); 
    printf("Masukkan Alamat: ");
    fgets(alamat,30,stdin); 
    
    printf("\nNama Barang:%sAlamat:%s ", barang, alamat);

    return 0;
}
