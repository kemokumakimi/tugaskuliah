#include <stdio.h>
int main (){
  int i, N, nilai, Cacah = 0;
  printf ("masukkan nilai perulangan : \n");
  scanf ("%d", &N);
  for (i = 1; i <= N; i = i + 1){
      printf ("masukkan nilai sembarang: \n");
      scanf ("%d", &nilai);
      if (nilai > 70){
	  		printf ("Nilai (>70) yaitu = %d \n", nilai);
	  		Cacah = Cacah + 1;
		}
    }
  printf ("Jumlah (nilai > 70) yang dinamakan = %d \n", Cacah);
}

