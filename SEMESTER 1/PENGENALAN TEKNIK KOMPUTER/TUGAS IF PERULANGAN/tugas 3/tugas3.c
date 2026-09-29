#include <stdio.h>
 int main() {

int j,N, Cacah=0, Total=0, nilai;

printf("masukkan jumlah perulangan: ");
scanf("%d", &N);
for (j=1;j<=N; j++) {
printf("masukkan sembarang nilai:");
scanf("%d", &nilai); 
if (nilai >70) {
Cacah=Cacah+1;
Total =Total+nilai;
 printf("Cacah = %d\n", Cacah);
printf("Total = %d\n", Total);
}
}


}