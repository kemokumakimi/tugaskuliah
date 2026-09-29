#include <stdio.h>

int main() {
	float jumlah;
	int pilihan, c, n=0;
  	printf("1. USD\n2. Yen\n3. Yuan\nPilih jenis mata uang: ");scanf("%d", &pilihan);
  	printf("Masukkan nominal uang: ");scanf("%f", &jumlah);
  	switch(pilihan){
  		case 1:
  			jumlah = jumlah / 15000;
			if(jumlah >= 100){
  				c = jumlah / 100;
  				jumlah = jumlah - c*100;
  				printf("%d lembar uang 100\n", c);
				  }
			if(jumlah >= 50){
  				c = jumlah / 50;
  				jumlah = jumlah - c*50;
  				printf("%d lembar uang 50\n", c);
				  }
			if(jumlah >= 10){
  				c = jumlah / 10;
  				jumlah = jumlah - c*10;
  				printf("%d lembar uang 10\n", c);
				  }
			printf("Kembalian anda adalah %.0f", jumlah*15000);
			break;
		case 2:
  			jumlah = jumlah / 115;
			if(jumlah >= 1000){
  				c = jumlah / 1000;
  				jumlah = jumlah - c*1000;
  				printf("%d lembar uang 1000\n", c);
			}
			printf("Kembalian anda adalah %.0f", jumlah*115);
			break;
		case 3:
  			jumlah = jumlah / 2200;
			if(jumlah >= 100){
  				c = jumlah / 100;
  				jumlah = jumlah - c*100;
  				printf("%d lembar uang 100\n", c);
				}
			if(jumlah >= 10){
  				c = jumlah / 10;
  				jumlah = jumlah - c*10;
  				printf("%d lembar uang 10\n", c);
				}
			printf("Kembalian anda adalah %.0f", jumlah*2200);
			break;
	  }
return 0;
}