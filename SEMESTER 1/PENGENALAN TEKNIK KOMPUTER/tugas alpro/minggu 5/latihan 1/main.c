#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, angka = 1, i = 0, total = 0;

    printf("Masukkan Banyak cacah: ");
    scanf("%d", &n);

    while (i < n)
    {
        printf("%d ", angka);
        angka = angka + 2;
        i++;
        total = total + angka;
    }

    printf("\ntotal nya adalah %d", total);

    return 0;
}