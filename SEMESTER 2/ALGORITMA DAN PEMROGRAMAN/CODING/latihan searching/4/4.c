#include <stdio.h>
#include <stdlib.h>


void countingSort(int arr[], int n, int max) {
    int count[max + 1]; 
    int output[n]; 
    int i;

    
    for (i = 0; i <= max; i++) {
        count[i] = 0;
    }

    
    for (i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    
    for (i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    
    for (i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    
    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}


void binarySearch(int arr[], int n, int target, int *awal, int *akhir) {
    int low = 0;
    int high = n - 1;
    int mid;

    
    *awal = -1;
    *akhir = -1;

    
    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == target) {
            
            *awal = mid;
            *akhir = mid;

            
            while (*awal > 0 && arr[*awal - 1] == target) {
                (*awal)--;
            }

            
            while (*akhir < n - 1 && arr[*akhir + 1] == target) {
                (*akhir)++;
            }

            return;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
}


void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int Y[10] = {90, 3, 7, 30, 40, 70, 40, 60, 2, 10};
    int n = sizeof(Y) / sizeof(Y[0]);
    int max = 90; // Nilai maksimum dalam array

    printf("Array sebelum sorting: ");
    printArray(Y, n);

    countingSort(Y, n, max);

    printf("Array setelah sorting: ");
    printArray(Y, n);

    int target = 0;
    printf("\nNilai yang mau di cari: ");
    scanf("%d", &target);
    int awal, akhir;

    binarySearch(Y, n, target, &awal, &akhir);

    printf("\n");
    printf("Pencarian nilai %d:\n", target);
    if (awal == -1 && akhir == -1) {
        printf("Nilai tidak ditemukan dalam array.\n");
    } else {
        printf("Indeks awal: %d\n", awal);
        printf("Indeks akhir: %d\n", akhir);
    }

    target = 0;
    printf("\nNilai yang mau di cari: ");
    scanf("%d", &target);

    binarySearch(Y, n, target, &awal, &akhir);

    printf("\n");
    printf("Pencarian nilai %d:\n", target);
    if (awal == -1 && akhir == -1) {
        printf("Nilai tidak ditemukan dalam array.\n");
    } else {
        printf("Indeks awal: %d\n", awal);
        printf("Indeks akhir: %d\n", akhir);
    }

    return 0;
}
