#include <stdio.h>
#include <stdlib.h>

int main() {
    int x, y, data, jumlah=0;
    x = 1, y=10;
    while ( x < y ){
        printf("masukkan nilai: ");
        scanf("%d", &data);
        jumlah=jumlah + data;
        x=x + 2;
        printf("nilai x saat ini = %d, total nilai yang di masukkan = %d \n", x , jumlah);
    }
  	
return 0;
}