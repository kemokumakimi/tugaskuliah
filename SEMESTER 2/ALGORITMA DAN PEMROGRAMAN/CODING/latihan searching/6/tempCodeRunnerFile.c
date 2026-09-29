#include <stdio.h>
#include <string.h>

int sequential_search(char data[][100], int n, char target[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(data[i], target) == 0) {
            return i;  // Mengembalikan indeks jika ditemukan
        }
    }
    return -1;  // Mengembalikan -1 jika tidak ditemukan
}

int main() {
    char data[][100] = {"Barang 1", "Barang 2", "Barang 3", "Barang 4", "Barang 5"};
    int n = sizeof(data) / sizeof(data[0]);

    char target[100];
    printf("Masukkan nama barang yang ingin dicari: ");
    scanf("%s", target); strtok(target, "\n");

    int index = sequential_search(data, n, target);
    if (index != -1) {
        printf("Barang ditemukan pada indeks %d\n", index);
    } else {
        printf("Barang tidak ditemukan dalam data\n");
    }

    return 0;
}
