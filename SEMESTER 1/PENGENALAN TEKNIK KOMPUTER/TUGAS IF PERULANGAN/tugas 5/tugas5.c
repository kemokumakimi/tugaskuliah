#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,nilai;
    for (i=1; i<=3; i=i+1) {
    printf("Masukkan nilai sembarang:\n");
    scanf("%d",&nilai);
    if (nilai%3==0)
    printf("nilai kelipatan 3 yaitu =%d \n",nilai);
}
}