#include <stdio.h>
#include <stdlib.h>

int main()
{
    char menu[15];
    int harga;

    printf("Pilih menu (baso/soto/mi ayam/bubur ayam): \n");
    fgets(menu,15,stdin);
    strtok(menu,"\n");
    if (strcmp(menu,"baso")==0) {harga=10000;}
    else if (strcmp(menu,"soto")==0) {harga=7500;}
    else if (strcmp(menu,"mi ayam")==0) {harga=6000;}
    else if (strcmp(menu,"bubur ayam")==0) {harga=5000;}
    else {harga=0;}
    printf("Menu : %s dengan harga %d \n",menu,harga);

}
