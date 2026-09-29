#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nilai,N100=0;
    printf("masukkan sembarang nilai: \n");
    scanf("%d",&nilai);

    if (nilai == 100)
    {
        N100=N100+1;
    }
    else if (nilai == 10)
    {
        N100=0;
    } 
    printf("Nilai N100 saat ini: %d \n",N100);

    return 0;
}
