#include <stdlib.h>
#include <stdio.h>

int main(){
    int suku1, suku2, isi;
    int suku_n=0;
    int i = 1;
    int jumlah3=0, genap=0;

    printf("Masukkan Angka N: ");
    scanf("%d",&isi);

    suku1= 0;
    suku2= 1;

    do{
        if (i % 2 == 0){
            genap = genap+suku_n;
        }
		i++;
        printf("%d ", suku_n);
        suku_n = suku1+suku2;
        suku2 = suku1;
        suku1 = suku_n;
        
    }
    while(i<=isi);
    printf("\n");
    printf("Baris angka Kelipatan 3: ");
    suku1= 0;
    suku2= 1;
    suku_n=0;
    i = 1;
    do{
		i++;
        suku_n = suku1+suku2;
        suku2 = suku1;
        suku1 = suku_n;

        if(suku_n % 3 == 0){
            jumlah3 = jumlah3+suku_n;
            printf("%d ", suku_n);
        }
        
    }
    while(i<=isi);
    
    printf("\nTotal Suku Kelipatan 3: %d", jumlah3);
    printf("\n");
    printf("Total Suku genap: %d", genap);
}