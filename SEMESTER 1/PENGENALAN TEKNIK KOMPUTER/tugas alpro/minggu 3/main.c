#include <stdio.h>

int main() {
    int i, N, sks, jmlbobot=0, MK, bobot,jumlahsks=0, j, b;
    char nama[100], NIM[100], matkul[100], nilai, ceknilaiE='T';
    float ipk;

    printf("Masukkan Jumlah Mahasiswa: ");
    scanf("%d", &N); fflush(stdin);
    for (i = 0; i < N; i++)
    {
        printf("Masukkan Nama Mahasiswa: ");
        scanf("%s", &nama);
        printf("Masukkan NIM: ");
        scanf("%s", &NIM);
        printf("Masukkan Jumlah Mata Kuliah: ");
        scanf("%d", &b); fflush(stdin);
        for (j = 0; j < b; j++)
        {
            printf("Masukkan Mata Kuliah: ");
            scanf("%s",&matkul);
            printf("Masukkan SKS Mata Kuliah: ");
            scanf("%d",&sks); fflush(stdin);
            printf("Masukkan Nilai Mata Kuliah: ");
            scanf("%c", &nilai);
            switch (nilai)
            {
            case 'A':bobot=4; break;
            case 'B':bobot=3; break;
            case 'C':bobot=2; break;
            case 'D':bobot=1; break;
            case 'E':bobot=0; ceknilaiE='Y'; break;
            }
            jumlahsks=jumlahsks+sks;
            MK=bobot*sks;
            jmlbobot=jmlbobot+MK;
        }
        ipk=(float)jmlbobot/jumlahsks;
        if (ipk>=2 && ceknilaiE=='T')
        {
            printf("Nama : %s, dengan IPK = %.2f dan tidak ada nilai E, maka lulus TPB\n", nama, ipk );
        }
        else{
            printf("Nama : %s, dengan IPK = %.2f dan ada nilai E, maka tidak lulus TPB\n", nama, ipk);
        }        
        jumlahsks=0;
        jmlbobot=0;
        ceknilaiE='T';

    }
    
    
    return 0;
}
