#include <stdio.h>
#include <stdlib.h>

int main() {
    int data, jumlah=0;
    printf("masukkan nilai: \n");
    scanf("%d", &data);
    while (data != 999){
        jumlah=jumlah + data;
        printf("masukkan nilai data untuk berhenti: ");
        scanf("%d", &data);
        printf("jumlah saat ini = %d\n", jumlah);
    }
    printf("Jumlah = %d \n", data);

return 0;
}