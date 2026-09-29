#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mahasiswa
{
    char nama[30];
    int nim;
    int nilai;
    char indeks;
};

void bubblesort(struct mahasiswa temp, struct mahasiswa mhs[], int n, int size)
{
    int k, pass, tukar;
    pass = 1; 
    tukar = 1;
    while (pass <= n-1 && tukar == 1)
    {
        tukar = 0;
        for (k = 1; k <= n-pass; k++)
        {
            if (mhs[k-1].nim > mhs[k].nim)
            {
                temp = mhs[k];
                mhs[k] = mhs[k-1];
                mhs[k-1] = temp;
                tukar = 1;
            }
            pass += 1;
            
        }
        
    }
    
    printf("NIM yang sudah diurutkan menggunakan bubble sort:\n");
    for (int i = 0; i < n; i++)
    {
        printf("NIM ke %d: %d\n",i+1, mhs[i].nim);
    }
    

}

void selectionsort(struct mahasiswa temp, struct mahasiswa mhs[], int size){

    for (int step = 0; step < size - 1; step++)
    {
        int minIdx = step;
        for (int i = step + 1; i < size; i++)
        {
            if (strcmp(mhs[i].nama, mhs[minIdx].nama) < 0)
            {
                minIdx = i;
            }
            temp = mhs[minIdx];
            mhs[minIdx] = mhs[step];
            mhs[step] = temp;
        }
        
    }
    
    printf("hasil pengurutan nama:\n");
    for (int i = 0; i < size; i++)
    {
        printf("nama ke %d: ", i+1);
        printf("%s\n", mhs[i].nama);
    }
    


}


int main() {
    
    int n;

    printf("Masukkan Banyak data: ");
    scanf("%d", &n); fflush(stdin);
    struct mahasiswa mhs[n];
    
    int size = sizeof(mhs)/sizeof(mhs[0]);
    struct mahasiswa temp;

    for (int i = 0; i < n; i++)
    {
        printf("Masukkan Mahasiswa ke-%d\n", i+1);
        printf("Nama: ");
        fgets(mhs[i].nama, 30, stdin); strtok(mhs[i].nama,"\n");
        printf("Nim: "); 
        scanf("%d", &mhs[i].nim);fflush(stdin);
        printf("Nilai: ");
        scanf("%d", &mhs[i].nilai);fflush(stdin);
        printf("Indeks: ");
        scanf("%c", &mhs[i].indeks);fflush(stdin); 
    }

    bubblesort(temp, mhs, n, size);
    selectionsort(temp, mhs, size);
    
    return 0;
}
