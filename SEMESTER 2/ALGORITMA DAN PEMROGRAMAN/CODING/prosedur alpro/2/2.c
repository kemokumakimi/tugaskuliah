#include <stdio.h>
#include <stdlib.h>

void baca(int n, int array[n])
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("masukkan data ke %d: ", i + 1);
        scanf("%d", &array[i]);
    }
}

void output(int n, int array[n])
{

    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
}

float jumlah(int n, int array[n])
{
    float total = 0;
    for (int i = 0; i < n; i++)
    {
        total += array[i];
    }
    total = total / n;

    return total;
}

int mencari(int n, int array[n])
{
    int cari;
    printf("\napa yang mau anda cari: ");
    scanf("%d", &cari);
    for (int i = 0; i < n; i++)
    {
        if (array[i] == cari)
        {
            return 1;
        }
        
    }
    return 0;
}

int main()
{
    int n;
    printf("masukkan banyak N: ");
    scanf("%d", &n);
    int array[n];
    baca(n, array);
    output(n, array);
    printf("\nrata rata nya adalah: %.2f", jumlah(n, array));
    printf("hasil cari adalah: %d",mencari(n, array)); 
    
    


    return 0;
}