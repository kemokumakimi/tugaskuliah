    #include <stdio.h>
    #include <stdlib.h>
        

    int main()
    {
        int angka[] = {3,4,5,2,7,6,1,6};
        int banyak = sizeof(angka) / sizeof(angka[0]);

        for (int step = 0; step < banyak - 1; step++)
        {
            for (int i = 0; i < banyak - step - 1; i++)
            {
                if (angka[i] < angka [i+1])
                {
                    int temp = angka[i];
                    angka[i] = angka[i+1];
                    angka[i+1]= temp;
                }
                
            }
            
        }
        printf("banyak: %d ", banyak);
        printf("Hasil Pengurutan ascending adalah:\n" );
        
        for (int i = 0; i < banyak; i++)
        {
            printf("%d ", angka[i]);
        }
        
        return 0;
    }  
