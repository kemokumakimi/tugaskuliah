#include <stdio.h>
#include <string.h>

int main(){
    char tujuan[40];
    char pilihan;
    printf("masukan tujuan anda R/L? : \n");
    scanf("%c",&pilihan);
    switch(pilihan){
        case 'L':
                strcpy(tujuan,"arena olahraga");
                break;
        case 'R':
                strcpy(tujuan,"taman bermain");
                break;
    }
    printf("tujuan anda adalah: %s \n", tujuan);
}