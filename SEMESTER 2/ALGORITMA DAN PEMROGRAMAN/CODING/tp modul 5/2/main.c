#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct buku //buat struktru untuk mahasiswa
{
    int id;
    char judul[20];
    char penulis[40];
};

void sorting(struct buku buku[], int size, struct buku temp, int n){
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (buku[j].id > buku[j+1].id)

            {
                temp = buku[j + 1];
                buku[j + 1] = buku[j];
                buku[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d\n", buku[i].id);
    }

}

void binary_search(struct buku buku[], int size){
    int target;
    int left = 0;
    int right = size - 1;
    int mid;
    int result = -1;

    printf("Masukkan ID yang dicari: ");
    scanf("%d", &target);
    
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (buku[mid].id == target)
        {
            result = mid;
            break;
        }
        if (buku[mid].id < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
            
    }

    if (result == -1) //jika nim tidak ditemukan
    {
        printf("ID tidak ditemukan\n"); 
    }
    else //jika nim ditemukan maka keluar sesuai nim yang dicari
    {
        printf("ID ditemukan pada indeks %d\n", result);
        printf("ID: %d\n", buku[result].id);
        printf("Judul: %s", buku[result].judul); 
        printf("Penulis: %s", buku[result].penulis); 
    }
}



int main()
{   
    int n;
    struct buku temp;

    printf("Masukkan banyak data: ");
    scanf("%d", &n); fflush(stdin);
    
    struct buku buku[n];
    int size = sizeof(buku)/sizeof(buku[0]);

    for (int i = 0; i < n; i++)
    {
        printf("data ke-%d\n", i+1);
        printf("Masukkan id: ");
        scanf("%d", &buku[i].id); fflush(stdin);
        printf("Masukkan judul: ");
        fgets(buku[i].judul, 20, stdin); fflush(stdin);
        printf("Masukkan penulis: ");
        fgets(buku[i].penulis, 40, stdin); fflush(stdin);
        printf("\n");
    }

    sorting(buku, size, temp, n);
    
    binary_search(buku, size);
    return 0;
}
