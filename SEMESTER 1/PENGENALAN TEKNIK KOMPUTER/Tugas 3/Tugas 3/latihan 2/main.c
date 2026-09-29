#include <stdio.h>
#include <stdlib.h>

main(){
    int UAS,UTS;
    float nakhir;
    printf("masukkan nilai uts dan uas\n");
    scanf("%d %d",&UTS ,&UAS);
    nakhir=(float)(UTS+UAS)/2;
    printf("jadi nilai akhir adalah %f", nakhir);
    return 0;
}
