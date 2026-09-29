#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Daftar kopi beserta harga
typedef struct {
    char nama[20];
    int harga;
} Kopi;

Kopi daftarKopi[] = {
    {"Aren", 10000},
    {"Caramel", 12000},
    {"Pandan", 15000}
};

// Daftar non kopi beserta harga
typedef struct {
    char nama[20];
    int harga;
} NonKopi;

NonKopi daftarNonKopi[] = {
    {"Teh", 8000},
    {"Milkshake", 15000},
    {"Charcoal", 10000}
};

// Struktur untuk menyimpan pesanan
typedef struct {
    char nama[20];
    int jumlah;
    int harga;
} Pesanan;

int main() {
    int pilihanMinuman;
    int totalHargaKopi = 0;
    int totalHargaNonKopi = 0;

    time_t t;
    struct tm* timestamp;
    char waktuPemesanan[100];

    Pesanan pesananKopi[4] = {{"Aren", 0, 10000}, {"Caramel", 0, 12000}, {"Pandan", 0, 15000}};
    Pesanan pesananNonKopi[4] = {{"Teh", 0, 8000}, {"Milkshake", 0, 15000}, {"Charcoal", 0, 10000}};

    time(&t);
    timestamp = localtime(&t);
    strftime(waktuPemesanan, sizeof(waktuPemesanan), "%d/%m/%Y %H:%M:%S", timestamp);

    printf("Selamat datang di tempat pemesanan kopi!\n");
    printf("Waktu Pemesanan: %s\n", waktuPemesanan);

    while (1) {
        printf("Pilih jenis minuman:\n");
        printf("1. Kopi\n");
        printf("2. Non-Kopi\n");
        printf("0. Selesai pemesanan\n");
        scanf("%d", &pilihanMinuman);

        if (pilihanMinuman == 0) {
            break; // Keluar dari loop jika pengguna memilih 0
        }

        if (pilihanMinuman == 1) {
            printf("Daftar Kopi:\n");
            for (int j = 0; j < sizeof(daftarKopi) / sizeof(daftarKopi[0]); j++) {
                printf("%d. %s - %d\n", j + 1, daftarKopi[j].nama, daftarKopi[j].harga);
            }
        } else if (pilihanMinuman == 2) {
            printf("Daftar Non-Kopi:\n");
            for (int j = 0; j < sizeof(daftarNonKopi) / sizeof(daftarNonKopi[0]); j++) {
                printf("%d. %s - %d\n", j + 1, daftarNonKopi[j].nama, daftarNonKopi[j].harga);
            }
        } else {
            printf("Pilihan tidak valid.\n");
            continue; // Lanjut ke iterasi berikutnya jika pilihan tidak valid
        }

        while (1) {
            int nomorPesanan;
            printf("Masukkan nomor pesanan (0 untuk kembali): ");
            scanf("%d", &nomorPesanan);

            if (nomorPesanan == 0) {
                break; // Keluar dari loop jika pengguna memilih 0
            }

            if (pilihanMinuman == 1 && nomorPesanan >= 1 && nomorPesanan <= sizeof(daftarKopi) / sizeof(daftarKopi[0])) {
                pesananKopi[nomorPesanan - 1].jumlah++;
            } else if (pilihanMinuman == 2 && nomorPesanan >= 1 && nomorPesanan <= sizeof(daftarNonKopi) / sizeof(daftarNonKopi[0])) {
                pesananNonKopi[nomorPesanan - 1].jumlah++;
            } else {
                printf("Nomor pesanan tidak valid.\n");
            }
        }
    }

    printf("\n\n");
    printf("\t     Norma Coffee\n");
    printf("---------------------------------------\n");

    printf("   Order Date    %s\n", waktuPemesanan);
    printf("   Cashier\t\t\tkimi\n");
    printf("---------------------------------------\n");

    // Cetak pesanan dengan format yang diinginkan
    for (int i = 0; i < sizeof(pesananKopi) / sizeof(pesananKopi[0]); i++) {
        if (pesananKopi[i].jumlah > 0) {
            printf("   %d %s\t\t       %d\n", pesananKopi[i].jumlah, pesananKopi[i].nama, pesananKopi[i].harga );
        }
    }
    for (int i = 0; i < sizeof(pesananNonKopi) / sizeof(pesananNonKopi[0]); i++) {
        if (pesananNonKopi[i].jumlah > 0) {
            printf("   %d %s\t\t       %d\n", pesananNonKopi[i].jumlah, pesananNonKopi[i].nama, pesananNonKopi[i].harga);
        }
    }

    // Hitung total harga
    for (int i = 0; i < sizeof(pesananKopi) / sizeof(pesananKopi[0]); i++) {
        totalHargaKopi += pesananKopi[i].jumlah * daftarKopi[i].harga;
    }
    for (int i = 0; i < sizeof(pesananNonKopi) / sizeof(pesananNonKopi[0]); i++) {
        totalHargaNonKopi += pesananNonKopi[i].jumlah * daftarNonKopi[i].harga;
    }
    printf("\n---------------------------------------\n");
    
    printf("   TOTAL\t\t      %d\n", totalHargaKopi + totalHargaNonKopi);

    printf("\n\n\tThanks for Stopping By\n\n\n");

    return 0;
}
