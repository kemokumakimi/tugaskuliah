#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct mahasiswa
    {
        char nama[20];
        int uts, uas;
        float nilai_akhir;
    };
    struct mahasiswa mhs[10];
    // Mengisi data mhs
    for (int i = 0; i < 3; i++)
    {
        fgets(mhs[i].nama, 20, stdin);
        scanf("%d", &mhs[i].uts);
        scanf("% d", &mhs[i].uas);
        fflush(stdin);
        mhs[i].nilai_akhir = (float)(mhs[i].uts + mhs[i].uas) / 2;
    }
    // Mencetak data mhs
    for (int i = 0; i < 3; i++)
        printf("%s %d %d %f\n", mhs[i].nama,
               mhs[i].uts, mhs[i].uas, mhs[i].nilai_akhir);

    return 0;
}
