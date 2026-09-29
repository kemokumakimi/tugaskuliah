#include <stdio.h>
#include <stdlib.h>

void luas(int r){
    float luas;
    luas = 3.14 * (r * r);
    printf("Luas Lingakaran: %.2f\n", luas);
}
    
void keliling(int r){
    float keliling;
    keliling = 2 * 3.14 * r;
    printf("Keliling Lingkaran: %.2f", keliling);
}
    

int main()
{
    int jari;
    printf("Masukkan Jari-Jari Lingkaran: ");
    scanf("%d", &jari);
    printf("-------------------------\n");
    luas(jari);
    keliling(jari);
    
    return 0;
}