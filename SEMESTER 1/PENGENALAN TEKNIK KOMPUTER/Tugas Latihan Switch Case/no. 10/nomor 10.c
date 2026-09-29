#include <stdio.h>

#include <string.h>

int main() {

  int pilmenu, pilbaso, pilsoto, harga;

  char menu[20];

  printf("masukkan pilihan menu anda! (1.Baso 2.Soto 3.Mie ayam 4.Bubur ayam): \n");

  scanf("%d", & pilmenu);

  switch (pilmenu) {

  case 1:
    harga = 10000;
    printf("masukkan pilihan baso anda! (1.Baso telor 2.Baso urat): \n");
    scanf("%d", & pilbaso);
    if (pilbaso == 1) strcpy(menu, "baso telor");
    else strcpy(menu, "baso urat");

    break;

  case 2:
    harga = 7500;

    printf("masukkan pilihan soto anda! (1.soto babat 2.soto kudus 3.soto bandung):\n");
    scanf("%d", & pilsoto);

    switch (pilsoto) {

    case 1:
      strcpy(menu, "soto babat");
      break;
    case 2:
      strcpy(menu, "soto kudus");
      break;

    case 3:
      strcpy(menu, "soto bandung");
      break;

    }

    break;

  case 3:
    harga = 6000;

    strcpy(menu, "mie ayam");
    break;

  case 4:
    harga = 5000;

    strcpy(menu, "bubur ayam");
    break;

  }

  printf("Makanan yang anda pilih %s dengan harga %d\n", menu, harga);

}
