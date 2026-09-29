#include <stdio.h>

#include <string.h>

int main() {
  int pilmerek, jenis;
  char merek[35];
  printf("Masukkan pilihan merek (1. Toyota 2.Daihatsu 3.Isuzu): ");
  scanf("%d", & pilmerek);
  switch (pilmerek) {
  case 1:
    printf("Masukkan jenis (1.Kijang 2.Avanza 3. Agya) :");
    scanf("%d", & jenis);
    switch (jenis) {
    case 1:
      strcpy(merek, "Toyota Kijang");
      break;
    case 2:
      strcpy(merek, "Toyota Avanza");
      break;
    case 3:
      strcpy(merek, "Toyota Agya");
      break;
    }

    break;

  case 2:
    strcpy(merek, "Daihatsu");
    break;

  case 3:
    strcpy(merek, "Isuzu");
    break;
  }
  printf("merek mobil yang dipilih adalah %s\n", merek);
}
