#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int sin, cos, tan, alpha;
    int i;
    char pilihan;

    do
    {
        printf("\n1.sin\n2.cos\n3.tan\npilih trigono: ");
        scanf("%d", &i); fflush(stdin);
        switch (i)
        {
        case 1:
            printf("masukin alpha: 0, 30, 45, 60, 90\n");
            scanf("%d", &alpha); fflush(stdin);
            if (alpha == 0)
            {
                printf("sin 0 = 0");
            }
            else if (alpha == 30)
            {
                printf("sin 30 = 1/2");
            }
            else if (alpha == 45)
            {
                printf("sin 45 = 1/2akar2");
            }
            else if (alpha == 60)
            {
                printf("sin 60 = 1/2akar3");
            }
            else if (alpha == 90)
            {
                printf("sin 90 = 1");
            }

            break;

        case 2:
            printf("masukin alpha: 0, 30, 45, 60, 90\n");
            scanf("%d", &alpha); fflush(stdin);
            if (alpha == 0)
            {
                printf("cos 0 = 1");
            }
            else if (alpha == 30)
            {
                printf("cos 30 = 1/2akar3");
            }
            else if (alpha == 45)
            {
                printf("cos 45 = 1/2akar2");
            }
            else if (alpha == 60)
            {
                printf("cos 60 = 1/2");
            }
            else if (alpha == 90)
            {
                printf("cos 90 = 0");
            }

        case 3:
            printf("masukin alpha: 0, 30, 45, 60, 90\n");
            scanf("%d", &alpha);fflush(stdin);
            if (alpha == 0)
            {
                printf("tan 0 = 0");
            }
            else if (alpha == 30)
            {
                printf("tan 30 = 1/3akar3");
            }
            else if (alpha == 45)
            {
                printf("tan 45 = 1");
            }
            else if (alpha == 60)
            {
                printf("tan 60 = akar3");
            }
            else if (alpha == 90)
            {
                printf("tan 90 = tidak terdefinisi");
            }
        default:
            break;
        }
        printf("\ningin ulang (y/t): ");
        scanf("%c", &pilihan); fflush(stdin);
    } while (pilihan == 'y');

    return 0;
}