#include <stdio.h>
#include <stdlib.h>

int main()
{
    int uang;
    printf("Masukkan Jumlah uang yang anda punya\n");
    scanf("%d", &uang);
    
    if (uang >= 1000){
        printf("belilah roti\n");
    }
    else if (uang >= 500){
        printf("belilah kerupuk\n");
    }
    else if (uang >= 100){
        printf("belilah permen\n");
    }
    else if (uang >= 50){
        printf("carilah duit");
    }
    else
    return 0;
}
