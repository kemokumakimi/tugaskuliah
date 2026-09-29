#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int nilai;
	char status[100];
	
	printf("Masukkan nilai anda: "); scanf("%d", &nilai); fflush(stdin);
	
	if (nilai > 75){
		strcpy(status, "LULUS");
	}
	else {
		strcpy(status, "TIDAK LULUS");
	}
	
	printf("------------------------------\n Nilai anda %d\n Anda dinyatakan %s", nilai, status);
}
