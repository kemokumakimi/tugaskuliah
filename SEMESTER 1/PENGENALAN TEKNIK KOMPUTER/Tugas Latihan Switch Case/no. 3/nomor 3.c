#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int main(){
	char tujuan[100], pilihan;
	printf("Masukan tujuan anda R/L? : "); scanf("%c", &pilihan);
	switch (pilihan){
		case 'L':
			strcpy(tujuan,"Arena Olahraga");
			break;
		case 'R':
			strcpy(tujuan,"Taman Bermain");
			break;
		default:
			strcpy(tujuan,"Bandara");
	}
	printf("Tujuan anda adalah: %s\n", tujuan);
	return 0;	
}
