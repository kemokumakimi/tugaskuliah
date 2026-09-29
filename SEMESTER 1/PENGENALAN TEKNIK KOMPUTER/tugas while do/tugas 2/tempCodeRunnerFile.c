#include <stdio.h>
#include <stdlib.h>

int main() {
    int data, jumlah=0;
    printf("Masukkan Nilai: \n");
    scanf("%d", &data);
    while ((data >= 0) && (data <= 100)){
        printf("masukkan nilai (variabel data) untuk berhenti: \n");
        jumlah = jumlah + data;
        scanf("%d", &data); 
        printf("Jumlah TOTAL saat ini = %d , isi variabel data = %d\n", jumlah, data);
    }
    printf("Jumlah= %d\n", data);

return 0;
}