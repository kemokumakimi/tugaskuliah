    #include <stdio.h>
    #include <stdlib.h>
        

    int main()
    {
        int angka[] = {3,4,5,2,7,6,1,6,2,4,1,2,3,54,6,78,9,6,5,32,2,2,4,6,7,8,4,3,2,2,234,4,6,2,5,54,3,2,4,56,23,4};
        int banyak = sizeof(angka) / sizeof(angka[0]);

        for (int step = 0; step < banyak - 1; step++)
        {
            for (int i = 0; i < banyak - step - 1; i++)
            {
                if (angka[i] > angka [i+1])
                {
                    int temp = angka[i];
                    angka[i] = angka[i+1];
                    angka[i+1]= temp;
                }   
            }   
        }
        
        printf("\nHasil Pengurutan descending adalah:\n" );
        for (int i = 0; i < banyak; i++)
        {
            printf("%d ", angka[i]);
        }
        printf("\n");

        return 0;
    }  
