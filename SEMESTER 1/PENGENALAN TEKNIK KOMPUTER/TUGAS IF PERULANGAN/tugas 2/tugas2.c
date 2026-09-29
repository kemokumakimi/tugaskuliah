#include <stdio.h>
int main() {
int x, y, data, jumlah=0;

 x=1; y = 10;
 while (x < y) {
printf("masukkan nilai sembarang: ");
scanf("%d", &data);
x = x + 2 ;
printf("nilai x = %d\n",x); 
if (data>50){
jumlah = jumlah+data; 
printf("total semua nilai >50 = %d\n\n", jumlah);
}
}
}