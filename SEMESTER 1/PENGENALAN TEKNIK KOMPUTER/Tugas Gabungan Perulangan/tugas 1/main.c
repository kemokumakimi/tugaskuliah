#include <stdlib.h>
#include <stdio.h>

int main(){
    int i=1;
    int ganjil = 1;
    int isi, banyakderet=0;

    printf("Masukkan Angka N: ");
    scanf("%d",&isi);

    while(i<=isi){
        printf("%d ", ganjil);
        ganjil = ganjil + 2;
        i++;
        banyakderet=isi*isi;

    }

    printf("\n");
    printf("Jumlah Deret: %d", banyakderet);
}