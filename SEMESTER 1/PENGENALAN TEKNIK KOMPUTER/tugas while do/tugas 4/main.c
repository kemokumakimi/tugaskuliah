#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, nilai , total=0, n;
    printf("masukkan banyaknya perulangan: \n");
    scanf("%d", &n);
    for (i=1; i<=n; i=i+1){
        printf("masukkan nilai untuk di jumlahkan: \n");
        scanf("%d",&nilai);
        total=total+nilai;
    }
    printf("total semua nilai = %d \n", total);

return 0;
}