#include <stdio.h>
#include <stdlib.h>

int fungsi(int x)
{
    int f;
    f = (x * x) + 3 * (x)  -5;
    return f;
}

int main()
{
    int x;
    printf("Masukkan Nilai X: ");
    scanf("%d", &x);
    printf("hasilnya adalah: %d ", fungsi(x));
    return 0;
}