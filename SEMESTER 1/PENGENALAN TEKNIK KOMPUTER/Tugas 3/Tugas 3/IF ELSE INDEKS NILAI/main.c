#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int nilai;
    char matkul[100], indeks[10];
    printf("Masukkan Mata Kuliah: "); fgets(matkul, 100, stdin); fflush(stdin);
    printf("Masukkan Nilai: "); scanf("%d", &nilai); fflush(stdin);
    if(strcmp(matkul, "kalkulus\n")==0){
        if(nilai > 75) {
            strcpy(indeks, "A");
        }
        else if(nilai > 70) {
            strcpy(indeks, "AB");
        }
        else if(nilai > 65) {
            strcpy(indeks, "B");
        }
        else if(nilai > 60) {
            strcpy(indeks, "BC");
        }
        else if(nilai > 55) {
            strcpy(indeks, "C");
        }
        else if(nilai > 40) {
            strcpy(indeks, "D");
        }
        else{
            strcpy(indeks, "E");
        }

    }
    else{
        if(nilai > 80) {
            strcpy(indeks, "A");
        }
        else if(nilai >= 60) {
            strcpy(indeks, "B");
        }
        else if(nilai >= 50) {
            strcpy(indeks, "C");
        }
        else if(nilai >= 40) {
            strcpy(indeks, "D");
        }
        else{
            strcpy(indeks, "E");
        }
    }
    printf("Indeks kamu untuk mata kuliah %sadalah : %s", matkul, indeks);
}