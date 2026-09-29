#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int jarak;
	char tempat[100], arah[100];
	
	printf("Masukan destinasi anda (kota/pasar/bandara): "); fgets(tempat, 100, stdin); fflush(stdin);
	
	if (strcmp(tempat, "kota\n")==0){
		strcpy(arah, "KANAN");
		jarak = 5;
	}
	else if(strcmp(tempat, "pasar\n")==0){
		strcpy(arah, "KIRI");
		jarak = 10;
	}
	else {
		strcpy(arah, "LURUS");
		jarak = 15;
	}
	
	printf("Anda akan ke %s, maka belok %s dengan jarak %d km. Anda akan menempuh perjalanan sejauh %d km sejak anda berangkat.", tempat, arah, jarak, jarak + 15);
}
