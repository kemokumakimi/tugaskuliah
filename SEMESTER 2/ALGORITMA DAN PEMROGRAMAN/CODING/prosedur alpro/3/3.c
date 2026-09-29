#include <stdio.h>
#include <stdlib.h>

void baca(int n, int x[n])
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("masukkan data ke %d: ", i + 1);
        scanf("%d", &x[i]);
    }
}

void datamax(int n, int x[n]){
    int datamax, cacah=0;
    printf("masukkan datamax: ");
    scanf("%d", &datamax);
    for (int i = 0; i < n; i++)
    {
        if (datamax < x[i])
    {
        cacah += 1;  
    }

    }
    printf("cacah datamax adalah: %d", cacah);

}

void cacah10(int n, int x[n]){
    int cacah=0;
    for (int i = 0; i < n; i++)
    {
        if (10 == x[i])
        {
            cacah++;
        }
        
    }
    printf("\nnilai cacah yang bernilai 10 adalah: %d", cacah);
}

int main()
{
    int n;
    printf("masukkan banyak N: ");
    scanf("%d", &n);
    int x[n];
    baca(n, x);
    datamax(n, x);
    cacah10(n, x);

    return 0;
}