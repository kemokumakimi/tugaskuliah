#include <stdio.h>
#include <stdlib.h>

int main() {
	int total, pilihan;
    char hiburan[100], nginap[100];
    strcpy (nginap, "Penginapan");
    printf("1. Gunung\n2. Pantai\n3. Taman Hiburan\nPilih Jenis Hiburan: ");
    scanf("%d", &pilihan);
    switch (pilihan){
        case 1:
        strcpy(hiburan, "Gunung");
        total=250000;
        break;
        
        case 2:
        strcpy(hiburan, "Pantai");
        total=240000;
        break;

        case 3:
        strcpy(hiburan, "Taman Hiburam");
        total=80000;
        printf("1. Hotel\n2. Penginapan\n Pilih Jenis Penginapan: ");
        scanf("%d", &pilihan);
        switch(pilihan){
            case 1:
            strcpy(nginap, "Hotel");
            total += 500000;
            break;

            case 2:
            strcpy(nginap, "Penginapan");
            total += 250000;
            break;
        }
        break;
    }
    printf("Anda membeli tiket %s dan bertempat menginap di %s dengan harga %d", hiburan, nginap, total);
  	
return 0;
}