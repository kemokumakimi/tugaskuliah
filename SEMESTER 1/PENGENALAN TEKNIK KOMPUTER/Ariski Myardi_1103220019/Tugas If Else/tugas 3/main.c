#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int umur;
	char tempat[100], pasangan;
	
	printf("Masukan umur anda: "); scanf("%d", &umur); fflush(stdin);
	
	if (umur >= 20){
		printf("Apakah anda membawa pasangan? (Y/N): "); scanf("%c", &pasangan); fflush(stdin);
		if (pasangan == 'Y'){
			strcpy(tempat, "Apartemen B");
		}
		else {
			strcpy(tempat, "Apartemen C");
		}
	}
	else {
		strcpy(tempat, "Suite A");
	}
	
	printf("Anda akan tinggal di %s", tempat);
}
