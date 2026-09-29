#include <stdio.h>

int main()
{
    int n = 4, i, angka = 1, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= i; j++)
        {
            printf("%d ", angka);
            angka++;
        }
        printf("\n");
    }

    return 0;
}
