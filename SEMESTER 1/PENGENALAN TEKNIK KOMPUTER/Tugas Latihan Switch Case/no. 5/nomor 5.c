#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int main(){
	int kelompok;
	float potongan;
	printf("Masukkan kelompok barang 1/2? : "); scanf("%d", &kelompok);
	switch (kelompok){
		case 1: potongan = 0.10; break;
		case 2: potongan = 0.10; break;
		default: potongan = 0.25; break;
	}
	printf("Kelompok= %d potongan= %.0f persen \n", kelompok, potongan*100);
	return 0;	
}
