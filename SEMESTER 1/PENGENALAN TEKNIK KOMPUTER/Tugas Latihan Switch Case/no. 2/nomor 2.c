#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int main(){
	int menu, harga;
	char nama_menu[100];
	printf("Pilih menu (baso (1)/soto (2)/mi ayam (3)/bubur ayam (4)): \n"); scanf("%d", &menu);
	switch (menu){
		case 1:
			harga = 10000;
			strcpy(nama_menu, "baso");
			break;
		case 2:
			harga = 7500;
			strcpy(nama_menu, "soto");
			break;
		case 3:
			harga = 6000;
			strcpy(nama_menu, "mi ayam");
			break;
		case 4:
			harga = 5000;
			strcpy(nama_menu, "bubur ayam");
			break;
		default:
			harga = 0;
			strcpy(nama_menu, "menu tidak ada dalam daftar");
			break;
	}
	printf("Menu : %s dengan harga %d \n", nama_menu, harga);
	return 0;	
}
