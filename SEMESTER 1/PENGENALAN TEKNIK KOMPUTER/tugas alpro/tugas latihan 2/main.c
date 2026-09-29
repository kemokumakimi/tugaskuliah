#include<stdio.h> //library ini hanya bisa print dan scan
#include<stdlib.h> 


int main(void) { //pada program ini tidak ada nilai yang dikembalikan jadi menggunakan void.

  float nilai[]={45.2 , 98.8, 89.3, 69}; //array yang di deklariskan dengan 4 elemen
  float jumlah=0; // variable jumlah yang bernilai 0
  float rata2; //variable untuk menghasilkan rata rata
  int x; //variabel untuk perulangan

  printf("Menghitung rata-rata nilai\n"); 
  int length = sizeof(nilai) / sizeof(*nilai); //membuat variable length ber tipe integer yang di isi sizeof(nilai) / sizeof(*nilai)
 
  for (x=0;x<length;x++) 
    { 
      printf("\nNilai ke %d : %.2f ", x+1, nilai[x]); 
      jumlah=jumlah+nilai[x]; 
    } //perulangan x=0 berhenti sampai x<length dan memberi output 
 
  rata2=jumlah/length; //menghitung rata rata dengan rumus jumlah/length
  
  printf("\nJadi Nilai Rata-rata dari Nilai adalah %f", rata2); 
  //memberi output nilai rata rata
  
  return 0; 

}
