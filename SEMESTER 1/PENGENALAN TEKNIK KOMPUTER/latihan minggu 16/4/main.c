#include <stdio.h>

int main(){
    int j,N,nilai,total1=0,total2=0,total3=0,cacah1=0,cacah2=0,cacah3=0;
    float rata1=0,rata2=0,rata3=0;
    printf("masukan banyaknya perulangan: ");
    scanf("%d",&N);
    fflush(stdin);
    for (j=1;j<=N; j++){
        printf("masukan nilai anda:");
        scanf("%d",&nilai);
        fflush(stdin);
        switch(nilai){
            case 0 ... 40:
                total1=total1+nilai;
                cacah1=cacah1+1;
                break;
            case 41 ... 70 :
                total2=total2+nilai;
                cacah2=cacah2+1;
                break;
            case 71 ... 100 :
                total3=total3=nilai;
                cacah3=cacah2+1;
                break;
        }

    }
    rata1=(float)total1/cacah1;
    rata2=(float)total2/cacah2;
    rata3=(float)total3/cacah3;
    printf("rata1=%f, rata2=%f, rata3=%f \n", rata1,rata2,rata3);
}