#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Mahasiswa //buat struktru untuk mahasiswa
{
    char nama[50];
    char nim[100];
    char kelas[50];
};

void sorting(struct Mahasiswa temp, struct Mahasiswa data[], int size, int n){
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (strcmp(data[j].nim, data[j + 1].nim) > 0)
            {
                temp = data[j + 1];
                data[j + 1] = data[j];
                data[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%s\n", data[i].nim);
    }
    

}

void binary_search(struct Mahasiswa data[], int size){
    char target[50];
    int left = 0;
    int right = size - 1;
    int mid;
    int result = -1;

    printf("Masukkan NIM yang dicari: ");
    fgets(target, 50, stdin); //menginput nim yang dicari
    strtok(target, "\n");
    
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (strcmp(data[mid].nim,target)==0) //jika nim yang dicari = 0 maka result = mid
        {
            result = mid;
            break;
        }
        if (strcmp(data[mid].nim, target)<0) //jika nim yang dicari < 0 maka left = mid + 1
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
        printf("NIM tidak ditemukan\n"); 
    }
    else //jika nim ditemukan maka keluar sesuai nim yang dicari
    {
        printf("NIM ditemukan pada indeks %d\n", result);
        printf("NIM: %s\n", data[result].nim);
        printf("Nama: %s\n", data[result].nama);
        printf("Kelas: %s\n", data[result].kelas);
    }
}


int main()
{
    int n;
    struct Mahasiswa temp;

    printf("masukkan banyak data mahasiswa: ");
    scanf("%d", &n); fflush(stdin); //menginput banyak data mahasiswa

    struct Mahasiswa data[n]; //mengubah struktur mahasiswa menjadi data untuk array
    int size = sizeof(data) / sizeof(data[0]); //menghitung banyak index array

    for (int i = 0; i < n; i++) //menginput banyak data sesuai banyak n
    {
        printf("Data Mahasiswa ke %d\n", i + 1);
        printf("Masukkan NIM: "); //input nim
        fgets(data[i].nim, 50, stdin); strtok(data[i].nim, "\n"); //strtok untuk menghilangkan \n
        printf("Masukkan Nama: ");  // input nama
        fgets(data[i].nama, 50, stdin); strtok(data[i].nama, "\n");
        printf("Masukkan Kelas: "); //input kelas
        fgets(data[i].kelas, 50, stdin); strtok(data[i].kelas, "\n");
        printf("\n"); //\n 
    }
    
    sorting(temp, data, size, n);
    //melakukan binary search sesuai di youtube    
    binary_search(data, size);

    return 0;
}
