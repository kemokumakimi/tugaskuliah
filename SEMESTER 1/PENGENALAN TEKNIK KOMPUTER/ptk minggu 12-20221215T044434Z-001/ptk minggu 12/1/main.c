#include <stdio.h>

int main(){
    char nilai ;

    printf("input nilai anda ( A - E): ");
    scanf("%c",&nilai);

    switch (nilai) {
        case 'A':
            printf("pertahankan! \n");
            break;
        case 'B':
            printf("Harus lebih baik lagi \n");
            break;
        case 'C':
            printf("perbanyak belajar \n");
            break;
        case 'D':
            printf("jangan keseringan main \n");
            break;
        case 'E':
            printf("kebanyakan bolos... \n");
            break;
        default:
            printf("maaf, format nilai tidak sesuai \n");
            
    }
}