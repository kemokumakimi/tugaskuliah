#include <stdio.h>


void umur(){
    int umur;
    printf("Masukkan Umur: ");
    scanf("%d", &umur);
}

void lama(){
    int lama;
    printf("Masukkan Lama Bekerja: ");
    scanf("%d", &lama);
}

void pegawai(){
    int umur, bonus, lama;
    if (lama >= 5 && umur >= 50)
    {
        bonus = 750000+1000000;
    }
    else if (lama>=5 && umur < 50)
    {
        bonus=1000000;
    }
    else if (lama < 5 && umur >= 50)
    {
        bonus=750000;
    }
    else {
        bonus=500000;
    }
    
    printf("bonus pegawai adalah: %d", bonus);
}

int main()
{

    umur();
    lama();
    pegawai();
    

    return 0;
}
