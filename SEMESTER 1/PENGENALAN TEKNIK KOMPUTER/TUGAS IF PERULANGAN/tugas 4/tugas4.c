#include <stdio.h>
int main() {
int i, N, suku;

i=1;

printf("masukkan jumlah perulangan:");  scanf("%d", &N); 
suku=1;  
while (i<=N) {  
printf("%d", suku);
suku=suku+1;
if (i % 4 ==0) 
suku=1;
 i++;
}
printf("\n");
}