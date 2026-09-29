#include <stdio.h>
#include <string.h>

int main(){
    int i, nilai;
    i=1;
    while (i<=3)
    {
        printf("masukkan nilai 1-10: ");
        scanf("%d", &nilai);
        switch (nilai)
        {
        case 8 ... 10 : printf("Bagus \n"); break;
        case 4 ... 7 : printf("Cukup\n"); break;
        case 0 ... 3 : printf("Buruk\n"); break;
        }
        i++; 
    }
}