#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nilai
{
    int nilai;
};

void selection_sort(struct nilai nilai[], int n, int size, struct nilai temp)
{

    for (int step = 0; step < size - 1; step++)
    {
        int min_idx = step;
        for (int i = step + 1; i < size; i++)
        {
            if (nilai[i].nilai > nilai[min_idx].nilai)
            {
                min_idx = i;
            }
        }
        temp = nilai[min_idx];
        nilai[min_idx] = nilai[step];
        nilai[step] = temp;
    }

    printf("Data setelah diurutkan:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", nilai[i]);
    }
}

int main()
{

    int n;
    int i;
    struct nilai temp;
    printf("Masukkan Jumlah data: ");
    scanf("%d", &n);
    fflush(stdin);
    struct nilai nilai[n];
    int size = sizeof(nilai) / sizeof(nilai[0]);
    for (i = 0; i < n; i++)
    {
        printf("Nilai %d : ", i + 1);
        scanf("%d", &nilai[i].nilai);
    }
    selection_sort(nilai, n, size, temp);

    return 0;
}