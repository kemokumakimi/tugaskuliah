#include <stdio.h>

int main(){
    int kelompok;
    float potongan;
    printf("masukan kelompok barang 1/2? : ");
    scanf("%d",&kelompok);
    switch(kelompok){
        case 1 : potongan= 0.10; break;
        case 2 : potongan= 0.10; break;
        default : potongan= 0.25; break;
    }
    printf("kelompok= %d potongan= %f persen \n1",kelompok,potongan*100);

}