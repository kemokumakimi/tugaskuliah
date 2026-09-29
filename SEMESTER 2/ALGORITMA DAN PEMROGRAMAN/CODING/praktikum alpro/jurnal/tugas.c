#include <stdio.h>
#include <stdlib.h>

void dolarkeyen()
{
    float dolar, rupiah, yen;
    printf("masukkan uang jojo (dalam dolar): ");
    scanf("%f", &dolar );
    rupiah = dolar * 15100.00;
    yen = rupiah / 114.00;
    printf("total uang si jojo: %.2f", yen);
}

int main()
{
    dolarkeyen();
    
    return 0;
}