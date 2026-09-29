#include <stdio.h>
#include <stdlib.h>

float cmkemeter(int cm)
{
    float meter;
    meter =(float) cm / 100;
    return meter;
}

int main()
{
    int cm;
    printf("Program Pengubah Cm ke Meter\n");
    printf("Masukkan Nilai cm: ");
    scanf("%d", &cm);
    printf("Hasilnya adalah: %f m", cmkemeter(cm));
    return 0;
}