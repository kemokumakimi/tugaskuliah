#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

    float phi = 3.14;
    float r, hasil;

    printf("Masukkan jari-jari: ");
    scanf("%f", &r);
    hasil = phi * (r*r);
    printf("hasilnya adalah %f", hasil);


    return 0;
}