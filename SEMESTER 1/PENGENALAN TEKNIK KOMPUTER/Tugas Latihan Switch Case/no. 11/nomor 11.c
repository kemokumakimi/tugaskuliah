#include <stdio.h>

#include <string.h>

int main() {

  int kelas;

  char jenis_kelamin;

  char Ruang[40];

  printf("masukkan jenis kelamin (L/P): \n");

  scanf("%c", & jenis_kelamin);

  printf("masukkan kelas (1/2/3): \n");
  scanf("%d", & kelas);

  if (jenis_kelamin == 'L')

    if (kelas == 1) strcpy(Ruang, "Asrama Putra Gd A");
    else strcpy(Ruang, "Asrama Putra Gd B");

  else

    switch (kelas) {

    case 1:
      strcpy(Ruang, "Asrama Putri Gd C");
      break;

    case 2:
      strcpy(Ruang, "Asrama Putri Gd D");
      break;

    case 3:
      strcpy(Ruang, "Asrama Putri Gd E");
      break;

    }

  printf("Ruang asrama adalah %s\n", Ruang);

}
