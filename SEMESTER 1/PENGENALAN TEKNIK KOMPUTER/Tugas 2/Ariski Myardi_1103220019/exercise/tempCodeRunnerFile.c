#include <stdio.h>
#include <stdlib.h>

main(){
	int nomor;
	char jenis_kelamin;
	char nama[20], alamat[30], kota[20];
	printf("Masukkan Nomor:");
	scanf("%d", &nomor);
    fflush(stdin);
	printf("Masukkan Nama:");
	fgets(nama, 30, stdin);
	fflush(stdin);
	printf("Masukkan Jenis Kelamin L/P:");
	scanf("%c", &jenis_kelamin);
	fflush(stdin);
	printf("Masukkan Alamat:");
	fgets(alamat, 30, stdin);
	printf("Masukkan Kota:");
	fgets(kota, 15, stdin);
	printf("nomor         : %d\nnama          : %sjenis kelamin : %c\nalamat        : %skota          : %s",nomor, nama, jenis_kelamin, alamat, kota);
}