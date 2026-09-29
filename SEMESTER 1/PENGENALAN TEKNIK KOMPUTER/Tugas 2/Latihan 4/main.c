#include <stdio.h>
#include <stdlib.h>

int main()
{
    char huruf, awal, pilihan;
    huruf='a';
    scanf("%c", &awal); fflush(stdin);
    scanf("%c", &pilihan); fflush(stdin);
    printf("%c%c%c", huruf, awal, pilihan);
    return 0;
}
