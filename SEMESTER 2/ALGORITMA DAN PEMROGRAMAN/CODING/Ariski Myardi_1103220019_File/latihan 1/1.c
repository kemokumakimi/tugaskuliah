#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menghitungA(char *tes, char b)
{
    int cacah = 0;
    for (int i = 0; i < strlen(tes); i++)
    {
        if (tes[i] == b)
        {
            cacah++;
        }
    }
    return cacah;
}
int main()
{
    char hurufa[100];
    FILE *lat;
    lat = fopen("lat.txt", "r");
    if (lat == NULL)
    {
        printf("File tidak ada");
        return 1;
    }
    else
    {
        char kata[100];
        char kataterpanjang[100] = "";
        char aterbanyak[100] = "";
        int cacahaterbanyak = 0;
        while (fscanf(lat, "%s", kata) != EOF)
        {
            int cacaha = menghitungA(kata, 'a');
            if (cacaha > 0)
            {
                if (strlen(kata) > strlen(kataterpanjang))
                {
                    strcpy(kataterpanjang, kata);
                }
                if (cacaha > cacahaterbanyak)
                {
                    cacahaterbanyak = cacaha;
                    strcpy(aterbanyak, kata);
                }
            }
        }
        printf("Kata terpanjang: %s\n", kataterpanjang);
        printf("Kata yang paling banyak huruf A: %s\n", aterbanyak);
        rewind(lat);
        
        
        printf("Kata yang memiliki huruf A: %s\n", );
        while (fscanf(lat, "%s", kata) != EOF)
        {
            int cacaha = menghitungA(kata, 'A');
            if (cacaha > 0)
            {
                printf("%s\n", kata);
            }
        }
        fclose(lat);
        return 0;
    }
}


printf("\t  Norma Coffee\n");
    printf("-----------------------------------\n");

    printf("Order Date  %s\n", waktuPemesanan);
    printf("-----------------------------------\n");