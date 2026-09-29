#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Mahasiswa // buat struktru untuk mahasiswa
{
    char nama[50];
    int nilai;
};

void bubble_sort(struct Mahasiswa temp, struct Mahasiswa data[], int size, int n)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (strcmp(data[j].nama, data[j + 1].nama) > 0)
            {
                temp = data[j + 1];
                data[j + 1] = data[j];
                data[j] = temp;
            }
        }
    }
    printf("Nama\tNilai");
    for (int i = 0; i < n; i++)
    {
        printf("\n%s\t%d", data[i].nama, data[i].nilai);
    }
}

int main()
{
    int n;
    struct Mahasiswa temp;

    printf("Jumlah data: ");
    scanf("%d", &n);
    fflush(stdin);

    struct Mahasiswa data[n];
    int size = sizeof(data) / sizeof(data[0]);

    for (int i = 0; i < n; i++)
    {
        printf("Data ke-%d\n", i + 1);
        printf("Nama: ");
        fgets(data[i].nama, 50, stdin);
        fflush(stdin);
        strtok(data[i].nama, "\n");
        printf("Nilai: ");
        scanf("%d", &data[i].nilai);
        fflush(stdin);
        printf("\n");
    }

    bubble_sort(temp, data, size, n);

    return 0;
}
