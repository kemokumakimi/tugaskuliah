#include <stdio.h>
#include <stdlib.h>

int main() {
    int x, y, jumlah=0, data;
    x=1; y=10;
    do {
        printf("masukkan jumlah data: \n");
        scanf("%d", &data);
        jumlah=jumlah+data;
        x=x+2;
        printf("Nilai X = %d, nilai jumlah = %d\n", x, jumlah);
    }
    while (x<y);
return 0;
}