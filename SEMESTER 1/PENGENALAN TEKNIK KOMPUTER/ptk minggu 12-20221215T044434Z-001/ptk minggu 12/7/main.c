#include <stdio.h>
#include <string.h>

int main(){
    int tingkat, fakultas;
    char ruang[20];
    printf("masukan tingkat (1/2/3): \n");
    scanf("%d",&tingkat);
    switch(tingkat){
        case 1:
            printf("masukan fakultas (1.FTE 2.FIF 3.FTI 4.lainnya): \n");
            scanf("%d",&fakultas);
            switch(fakultas){
                case 1 : strcpy(ruang,"GKU Lt 1"); break;
                case 2 : strcpy(ruang,"GKU Lt 2"); break;
                case 3 : strcpy(ruang,"GKU Lt 3"); break;
                default: strcpy(ruang,"GKU Lt 4"); break;
            }
            break;

            case 2: strcpy(ruang,"GAB");break;
            case 3: strcpy(ruang,"Lab");break;
    }
    printf("mahasiswa tingkat %d, ruangan di %s \n",tingkat,ruang);
}