#include <stdio.h>

int main(void)
{
    float hsl_ujian;
    int nilai;


    printf("masukan nilai ujian kalkulus anda: ");
    scanf("%f",&hsl_ujian);

        nilai=hsl_ujian*100;

    switch (nilai) {
        case 8001 ... 10000:
            printf("Nilai A \n");
            break;
        case 7001 ... 8000:
            printf("nilai AB \n");
            break;
        case 6501 ... 7000:
            printf("Nilai B \n");
            break;
        case 6001 ... 6500:
            printf("nilai BC \n");
            break;
        case 5001 ... 6000:
            printf("Nilai C \n");
            break;
        case 4001 ... 5000:
            printf("Nilai D \n");
            break;

        default: printf("indeks E \n");
            break;
    }

}
