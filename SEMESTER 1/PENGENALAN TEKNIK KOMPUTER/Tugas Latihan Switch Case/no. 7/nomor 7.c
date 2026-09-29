#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int main(){
	int tingkat, fakultas;
	char ruang[100];
	printf("Masukkan tingkat (1/2/3) : "); scanf("%d", &tingkat);
	switch (tingkat){
		case 1: 
			printf("Masukkan fakultas (1.FTE 2.FIF 3.FTI 4.Lainnya) : "); scanf("%d", &fakultas);
			switch(fakultas){
				case 1 : strcpy(ruang, "GKU Lt 1"); break;
				case 2 : strcpy(ruang, "GKU Lt 2"); break;
				case 3 : strcpy(ruang, "GKU Lt 3"); break;
				default : strcpy(ruang, "GKU Lt 4"); break;
			}
			break;
		case 2: strcpy(ruang, "GAB"); break;
		case 3: strcpy(ruang, "Lab"); break;
	}
	printf("mahasiswa tingkat %d, ruanga di %s \n", tingkat, ruang);
	return 0;	
}
