#include <stdio.h>
    #include <stdlib.h>

    int main()
    {
        char pilihan, motor[50];
        int harga;
        printf("Pilihan motor : B(Beat) V(Vario) P(PCX) :\n");
        scanf("%c",&pilihan);
        switch(pilihan){
            case 'B': case 'b' : strcpy(motor,"Beat"); harga=15; break;
            case 'V': case 'v' : strcpy(motor,"Vario"); harga=20; break;
            default : strcpy(motor,"PCX"); harga=30;
        }
        printf("Motor: %s Harga: %d \n",motor,harga);
    }
