#include <stdio.h>

int main() {
   int matriksA[2][2], matriksB[2][2], matriksC[2][2];
   int i, j;

   
   printf("====Matriks X====\n");
   for (i = 0; i < 2; i++) {
      for (j = 0; j < 2; j++) {
         printf("Masukkan nilai untuk baris %d kolom %d: ", i+1, j+1);
         scanf("%d", &matriksA[i][j]);
      }
   }

   for (i = 0; i < 2; i++) {
    printf("|");
      for (j = 0; j < 2; j++) {
         printf(" %d ", matriksA[i][j]);
         
      }
      printf("|");
      printf("\n");
   }

   printf("====Matriks Y====\n");
   for (i = 0; i < 2; i++) {
      for (j = 0; j < 2; j++) {
         printf("Masukkan nilai untuk baris %d kolom %d: ", i+1, j+1);
         scanf("%d", &matriksB[i][j]);
      }
   }

   for (i = 0; i < 2; i++) {
    printf("|");
      for (j = 0; j < 2; j++) {
         printf(" %d ", matriksB[i][j]);
         
      }
      printf("|");
      printf("\n");
   }

   for (j = 0; j < 2; j++) {
      for (i = 0; i < 2; i++) {
         matriksC[i][j] = matriksA[i][j] + matriksB[i][j];
      }
   }

   printf("Hasil penjumlahan matriks A dan B berdasarkan kolom:\n");
   for (i = 0; i < 2; i++) {
    printf("|");
      for (j = 0; j < 2; j++) {
         printf(" %d ", matriksC[i][j]);
      }
      printf("|");
      printf("\n");
   }

   return 0;
}
