#include <stdio.h>
#include <stdlib.h>

int main()
{
    int X,Y,Z;

    scanf("%d %d", &X,&Y);
    Z=X+Y;
    printf("%d\n", Z);
    Z=X-Y;
    printf("%d\n", Z);
    Z=X*Y;
    printf("%d\n", Z);
    Z=(float)X/Y;
    printf("%d\n", Z);
    Z=X%Y;
    printf("%d", Z);


    return 0;
}
