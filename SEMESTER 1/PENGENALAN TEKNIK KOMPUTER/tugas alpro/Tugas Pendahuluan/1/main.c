#include <stdio.h>

float luas(float r) 
{
    float luasling;
    luasling= 3.14 * r * r;
    return luasling;
}

int main()
{
    float r2;
    printf("Masukkan jari-jari lingkaran: ");
    scanf("%f", &r2);
    float hasil = luas(r2);

    printf("Luas Lingkaran adalah: %f", hasil);

    return 0;
}
// dibuat oleh: Ariski Myardi