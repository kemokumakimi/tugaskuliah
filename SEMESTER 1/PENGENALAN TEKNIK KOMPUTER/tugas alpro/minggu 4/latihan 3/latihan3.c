#include <stdio.h>


void hitungBonus(int umur, int lama_bekerja, int *bonus) {
    if (lama_bekerja >= 1 && umur >= 50) {
        *bonus = 1000000;
    } else if (lama_bekerja >= 5 || umur >= 50) {
        *bonus = 750000;
    } else {
        *bonus = 500000;
    }
}

void tampilBonus(int bonus) {
}


int main() {
    int umur, lama_bekerja, bonus;
    
    printf("Masukkan umur karyawan: ");
    scanf("%d", &umur);
    
    printf("Masukkan lama bekerja (dalam tahun): ");
    scanf("%d", &lama_bekerja);
    
    hitungBonus(umur, lama_bekerja, &bonus);
    
    printf("Bonus yang diterima karyawan: %d\n", bonus);
    
    
    return 0;
}
