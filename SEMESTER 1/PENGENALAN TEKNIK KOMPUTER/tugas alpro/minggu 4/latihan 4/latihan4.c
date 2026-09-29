#include <stdio.h>
#include <string.h>

int main() {
    struct datanilai
    {
        int nim,nilai;
        char mk[200],status[20];
    };
    struct datanilai dn[10];
    int i, N;
    float rata;
    int nimpil;
    int cacah=0;
    int jumlah=0;
        
        printf("Masukkan Banyak Data: ");
        scanf("%d",&N);

        for (i = 0; i < N; i++) {
        printf("Masukkan NIM: ");
        scanf("%d",&dn->nim); fflush(stdin);
        printf("Masukkan MK: ");
        fgets(dn->mk,200, stdin ); strtok(dn->mk, "\n");
        printf("Masukkan Nilai: ");
        scanf("%d", &dn->nilai); fflush(stdin);
             switch (dn->nilai)
            {
            case 81 ... 100:
                strcpy(dn->status,"Hebat");
                break;
            case 61 ... 80:
                strcpy(dn->status,"Bagus");break;
            case 41 ... 60:
                strcpy(dn->status,"Cukup");break;
            default:
                strcpy(dn->status,"Tak Lulus");break;
            }
        printf("Mahasiswa %d, %s, %s\n", dn->nim, dn->mk, dn->status);
        }
        printf("NIM mhs dihitung nilai rata-ratanya : ");
        scanf("%d",&nimpil);
        for (i = 0; i < N; i++)
        {
            if (dn->nim=nimpil)
        {
            cacah=cacah+1;
            jumlah=jumlah+dn->nilai;
            rata=(float)jumlah/cacah;
        }
           
        }
            printf("Jumlah data dengan nim %d adalah %d", nimpil, cacah);
            printf("Nilai rata-rata mahasiswa tersebut adalah %.2f",rata);
        
   
    
   return 0;
}
