#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c;
    float x,y,z;
    printf("masukkan a: "); scanf("%d",&a);
    printf("masukkan b: "); scanf("%d", &b);
    c=a+b;
    y=c;
    printf("jadi c=%d dan y=%f\n", c,y);
    z=(float)a/b;
    c=z;
    printf("jadi hasil c=%d dan z=%f", c,z);

    return 0;
}
