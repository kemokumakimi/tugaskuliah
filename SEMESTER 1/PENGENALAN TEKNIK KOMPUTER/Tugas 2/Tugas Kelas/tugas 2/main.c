#include <stdio.h>
#include <stdlib.h>

main(){
	float emas = 12.5, uang = 10.5;
	int total;
	emas = emas * 500000;
	uang = uang * 1000000;
	total = emas + uang;
	printf("uang  %.0f + emas  %.0f = %d",uang, emas, total);
}