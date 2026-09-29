#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

  int fahrenheit;
  int celcius;

  printf("Program pengubah suhu ke fahrenheit\n");
  printf("Masukkan suhu: ");
  scanf("%d", &celcius);
  fahrenheit = celcius * 1.8 + 32;

  printf("Suhu dalam Fahrenheit adalah %d", fahrenheit);


  return 0;
}