#include <stdio.h>
#include <stdlib.h>


int main()
{
    int TabInt[13]={0,3,10,12,11,5,9,4,21,14,19,90,12};
    int k=TabInt[0];
    for (int i = 0; i < 13; i++)
    {
        if(i % 3 == 0){
            if(TabInt[i] > k){
                k = TabInt[i];
            }
        }
    }
    printf("nilai: %d\n", k);
    for (int i = 0; i < 13; i++)
    {
        if (TabInt[i] % 3 == 0){
        
            if (TabInt[i] > k)
            {
                k = TabInt[i];
            }
        }
    }
    printf("nilai: %d\n", k);
    
    
    return 0;
}
