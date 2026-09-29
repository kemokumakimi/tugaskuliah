#include <stdio.h>
int main() {
int i, N, Total=0;

printf("Masukkan banyaknya deret:\n"); 
scanf("%d", &N);
for (i=1; i<=N; i=i+1) { 
printf("Nilai i = %d\n",i);
if (i % 2==0){
Total=Total+i; 
printf("Total= %d\n\n", Total);

}
}

}
