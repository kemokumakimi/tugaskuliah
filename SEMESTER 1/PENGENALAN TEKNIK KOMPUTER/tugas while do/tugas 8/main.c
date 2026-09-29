#include <stdio.h>
#include <stdlib.h>

int main() {
    int i=1;
    do {
        printf("masih ingin lanjutkan permainan?1.(Y)/2.(T) : \n");
        scanf("%d", &i);
        printf("jawaban anda %d\n", i);
    }
    while (i==1);
return 0;
}