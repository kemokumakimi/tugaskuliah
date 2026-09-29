#include <stdio.h>

int main()
{

    int a;
    a = 4;
    while (a > 0)
    {
        if (a % 2 == 1)
            a = a - 3;
        else
            a = a + 1;
        printf("%d", 1 / a);
    }

    return 0;
}
