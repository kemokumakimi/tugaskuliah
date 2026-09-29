#include <stdio.h>

int main()
{
    int i,N,Cacah80=0,Cacah40=0,data;
    printf("masukkan jumlah perulangan:");
    scanf("%d",&N);
    for (i=0;i<N;i++){
        printf("masukkan nilai sembarang:");
        scanf("%d",&data);
        if (data>80){
            Cacah80=Cacah80+1;
            printf("banyaknya nilai >80 = %d\n\n",Cacah80);}
        else if (data<40){
            Cacah40=Cacah40+1;
            printf("banyaknya nilai <40 = %d\n\n",Cacah40);}
        else
            printf("nilai bukan 80 atau 40 \n");
}
}