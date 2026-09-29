#include <stdio.h>
#include <stdlib.h>
struct mahasiswa
{
    char nama[20], kelas[10];
    int nim;
} mhs[5] = {"Adi S", "TK01", 115, "Budi K", "TK02", 112, "Cica C", "TK03", 113, "Dudi D", "TK02", 111, "Edi E", "TK04", 114}; // Tiap data terdiri dari komponen nama, kelas dan nim.
// Jika kosong, isikan sesuai dengan data : int/float dg 0, string dg “ “,
// karakter dengan ‘ ‘. Masing2 komponen data dipisah dg koma

int X[10] = {5, 1, 7, 4, 9, 2, 7, 10, 3, 0};

// Berikut adalah prosedur untuk membaca data mhs sebanyak n data. Lengkapi dg TULISAN TANGAN
void baca(n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        fflush(stdin);
        printf("Masukkan Nama : ");
        …… printf("Masukkan NIM : ");
        …… fflush(stdin);
        printf("Masukkan Kelas : ");
        ……
    }

    // Prosedur Pencarian Nilai Maksimal. Perhatikan bentuk variabel pembawa nilai hasil !
    void carimax(int N, int *Imax)
    {
        int i;
        *Imax = 0; // Index TabInt pertama
        for (i = 1; i < N; i++)
            if
                ……
         ……
    }

    // Prosedur Counting sort untuk array X ( integer)
    void countint(int N)
    {
        int i, k, j, Max, Imax;
        ……………..            // memanggil prosedur carimax()
            Max = X[Imax]; // Nilia maksimal
        .......            // Deklarasi variabel Hit
            printf("Nilai maksimal adalah %d, indeks Hit[] dari 0 sampai %d", Max, Max);
        // Inisialisasi array Hit ke 0
        for (i = 0; i <= ……………………..)
            ………………………..
                // Mencacah nilai array Data
                for (i = 0;…………………………………………)
            {
                Hit[………………..] = ………………………..+ 1;
                printf("Isi array Hit pada pass ke %d:", i);
                for (j = 0; j <=…………………..)
                    printf("%d ",…………………);
                printf("\n");
            }
        // Membentuk kembali array Data
        k = 0;
        for (i = 0; i <= Max; i++)
            if (……………… != 0)
                for (j = 1;………………………………)
                {
                    …………………….. // Mengisi array X dengan i
          ………………..
                }
    }

    // Prosedur bubbleint(), untuk mengurutkan array integer X dengan bubblesort ( bukan modified BS)
    // Variabel “tukar” hanya untuk menghitung cacah pertukaran tiap pass.
    // Array X dideklarasikan di luar prosdur ( di bawah include )
    void bubbleint(int N)
    {
        int temp, i, k, pass, jmltukar = 0, tukar;
        for (pass = 1; pass <= N - 1; pass++)
        {
            tukar = 0;
    for (…………………………………………………
       if (………………………..) {
                temp = X[k];
                X[k] = X[k - 1];
                X[k - 1] = temp;
                tukar++;
       }
    printf("Pada pass ke-%d, terjadi %d kali penukaran, sehingga urutan data : ",pass, tukar);
    for (i=0;i<N;i++) printf("%d ",X[i]);
    printf("\n");
        }
    }

    // Digunanakn untuk mengurutkan array mhs1[] berdasatkan nim dengan bubblesort
    // bukan  modified BS, struct dan array mhs[] dideklarasikan di luar prosdur ( di bawah include )
    void bubblenim(int N)
    {
        int k, pass;
        struct mahasiswa temp;        // perhatikan : tipe temp adalah mahasiswa
        for (……………………………………………………………) // HARUS menggunkan variabel pass
    for (k = 1; k <= N - pass; k++)
        if ()
        {
            temp = mhs1[k];
            mhs1[k] = mhs1[k - 1];
            mhs1[k - 1] = temp;
        }
    }

    // Prosedur untuk mencari nim (integer)  secara sekuensial.
    //  Bisa ditambahkan jika yg dicari adalah komponen array struktur bertipe string
    void sequential3(int n, int x, int *ix)
    {
        int i;
        mhs[n].nim = x;
        i = 0;
        while ()
        {
    i = i + 1;
        }
        if (i < n)
        {
    *ix = i;
        }
        else
        {
    *ix = -1;
        } // Perhatikan bahwa nilai ix adalah -1 jika tidak ditemukan !
    }

    // Prosedur untuk mencari nilai integer dengan binary search.
    void Binaryint(int N, int Cari, int *IX)
    {
        int i, Awal, Tengah, Akhir, Pass = 1; //, temp;
        // Jika array belum diurutkan, maka perlu diurutkan. Bisa dengan prosedur bubbleint
        /*printf("Sebelum diurutkan ");
        for (i=0;i<N;i++) printf("%d\n",X[i]);
        bubbleint(N);
        printf("Setelah diurutkan ");
        for (i=0;i<N;i++) printf("%d\n",X[i]);
       */
        Awal = 0;
        Akhir = N - 1;
        Tengah = (Awal + Akhir) / 2;
        printf("Pass %d: Awal=%d, Akhir=%d dan Tengah=%d dengan nilai X[Awal]=%d, X[Akhir]=%d dan X[Tengah]=%d\n", Pass, Awal, Akhir, Tengah, X[Awal], X[Akhir], X[Tengah]);
        while (() && ())
        {
    if (Cari < X[Tengah])
        Akhir = ;
    else if (Cari > X[Tengah])
        ;
    Tengah = / 2;
    Pass++;
    printf("Pass %d: Awal=%d, Akhir=%d dan Tengah=%d dengan nilai X[Awal]=%d, X[Akhir]=%d dan X[Tengah]=%d\n", Pass, Awal, Akhir, Tengah, X[Awal], X[Akhir], X[Tengah]);
        }
        if (Cari == X[Tengah])
    *IX = Tengah;
        else
    *IX = -1;
    }

    // Prosedur unt mencari nim (integer) dengan binary search pada array mhs1[]. Bisa direvisi dengan // mencari nilai string
    void Binarynim(int N, int Cari, int *IX)
    {
        int i, Awal, Tengah, Akhir; //, temp;
        // Catatan : data sudah urut berdasrkan nim. Jika belum, urutkan dengan bubblenim
        Awal = 0;
        Akhir = N - 1;
        Tengah = (Awal + Akhir) / 2;
    while ((Awal < Akhir) && (                                                                               ) {
            printf("X[Tengah]=%d\n", mhs1[Tengah].nim);
            if (Cari <)
                Akhir = Tengah - 1;
            else if (Cari >)
                Awal = Tengah + 1;
            Tengah = (Awal + Akhir) / 2;
    }
    if (Cari ==                                             ) *IX=Tengah;
    else *IX=-1;
    }

    // Menulis array mhs[] ke file
    void tulisfile(int N)
    { // N adalah cacah/jumlah data
    FILE *fp;
    int i;
    fp = fopen("C:/test1.txt", "w");
    // Gunakan prosedur bacadata() jika data belum diisikan ke array mhs[]
    // bacadata(N);
    for (i = 0; i < N; i++)
    fwrite();
    fclose(fp);
    }

    // Membaca array file dan menuliskan isinya ke mhs1[]
    //  Digunakan mhs1 agar bisa dipastikan hasil pembacaan berhasil disimpan ke array mhs1
    void bacafile(int N)
    { // N adalah cacah/jumlah data
    FILE *fp;
    int i;
    fp = fopen("C:/test1.txt", "r");
    for (i = 0; i < N; i++)
    fread();
    fclose(fp);
    }

    // Menampilkan isi array , mode 0 untuk mhs[], mode lainnya untuk mhs1[]:
    void tampilmhs(int N, int mode)
    {
    int i;
    for (i = 0; i < N; i++)
    if (mode == 0)
        printf("%s %s %d--", mhs[i].nama, mhs[i].kelas, mhs[i].nim);
    else
        printf("%s %s %d--", mhs1[i].nama, mhs1[i].kelas, mhs1[i].nim);
    printf("\n");
    }

    // Program Utama, memanggil prosedur2
    int main()
    {
    int i, n, cari, ix;

    printf("Masukkan jumlah data : ");
    scanf("%d", &n);
    // bacadata(n);   // Jika program membaca data dari pemakai
    tampilmhs(n, 0);
    tulisfile(n);
    bacafile(n);
    // panggil prosedur tampilmhs() untuk menampilkan mhs1
    printf("Setelah diurutkan berdasarkan nim:\n");
    // panggil bubblenim();
    tampilmhs(n, 1);
    printf("\nMasukkan NIM yang ingin dicari : ");
    scanf("%d", ……………………);
    // sequential3(n,cari,&ix);
    //  panggil prosedur Binarynim()
    if (ix != -1)
    printf("Data yang dicari : \nNama %s\n NIM %d\n Kelas %s\n", mhs[ix].nama, mhs[ix].nim, mhs[ix].kelas);
    else
    printf("data yang dicari dengan nim %d tidak ditemukan ");

    // Di bawah ini untuk data dalam bentuk array X
    /*
    n=10;   // Jumlah data X dalam bentuk integer
    for (i=0;i<n;i++) printf("%d--",X[i]);
    printf("\n");
    bubbleint(n);
    //countint(n);
    printf("\n");
    for (i=0;i<n;i++) printf("%d--",X[i]);

    // Di bawah ini jika dipakai untuk pencarian
    printf("\nMasukkan nilai yang ingin dicari : "); scanf("%d", &cari);
    //sequential3(n,cari,&ix);
                                                                                       // Panggil Binaryint(). Tulis parameter yg sesuai
    if (ix != -1)
        printf("Data yang dicari ditemukan pada nilai indeks : %d\n",ix);
    else printf("Data yang dicari dengan nilai %d tidak ditemukan ",cari);
    */
    return 0;
    }
