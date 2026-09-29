    #include <stdio.h>
    #include <stdlib.h>
        
    void total(int A, int B, int *JUMLAH){
        *JUMLAH = A + B;
    }



    int main()
    {
        int a, b, jumlah;
        printf("masukkan nilai a: ");
        scanf("%d", &a);
        printf("masukkan nilai b: ");
        scanf("%d", &b);
        total(a,b,&jumlah);
        printf("jumlahnya adalah: %d", jumlah);
        return 0;
    }