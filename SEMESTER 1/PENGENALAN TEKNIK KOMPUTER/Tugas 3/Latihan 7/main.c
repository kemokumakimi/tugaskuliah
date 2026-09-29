#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Nomor;
    char Nama[20],Panggilan[20],grade, ans[20];
    float Berat;
    printf("nomor!");
    scanf("%d",&Nomor);
    fflush(stdin);
    printf("masukkan nama");
    fgets(Nama,20,stdin);
    printf("masukkan nilai");
    fflush(stdin);
    scanf("%s",&grade);
    printf("masukkan panggilan");
    fflush(stdin);
    scanf("%s",&Panggilan);
    printf("masukkan berat");
    fflush(stdin);
    scanf("%f",&Berat);
    strcpy(ans,Nama);
    strcpy(Nama,Panggilan);
    strcpy(Panggilan,ans);
    printf("Nomor=%d\nNama=%s\nPanggilan=%s\nGrade=%c\nBerat=%f\n Biaya Perawatan=%f",Nomor,Nama,Panggilan,grade,Berat,Berat*10000);

    return 0;
}


