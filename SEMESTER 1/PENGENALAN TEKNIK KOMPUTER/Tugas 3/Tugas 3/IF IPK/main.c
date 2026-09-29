#include <stdio.h>
#include <stdlib.h>

int main()
{
    char TA;
    float IPK;
    int BPP;
    char Status_Sarjana[20];

    printf("masukkan hasil sidang Tugas Akhir anda (L/T):\n");
    scanf("%c", &TA);
    //fflush(stdin);
    printf("Masukkan IPK anda: \n");
    scanf("%f", &IPK);
    fflush(stdin);
    printf("apakah anda sudah membayar BPP? (1=sudah, 0=belum)\n");
    scanf("%d", &BPP);
    //fflush(stdin);
    
    if ((TA=='L') && (IPK>=2) && (BPP==1)) {
        strcpy(Status_Sarjana,"LULUS");
    }
    else {
        strcpy(Status_Sarjana,"TIDAK LULUS");
    }
    printf("Selamat kamu %s", Status_Sarjana);
    return 0;
}
