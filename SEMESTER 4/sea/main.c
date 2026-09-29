#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct  login{

    char fname[100];
    char lname[100];
    char username[20];
    char password[20];
};

typedef struct Account{

    char accountName[40];
    char accountNumber[20];
    char DateOfBirth[15];
    char address[50];
    char contactNum[15];
    float accountBalance;
};

void menu();
void createAccount();
void displayAllAccount();
void updateAccount();
void deleteAccount();
void searchAccount();

int main()
{
    int menu1;
    printf("\n============================================= \n");
    printf("==\t\t\t\t\t   ==  \n");
    printf("==  Selamat datang di program teller bank  == \n");
    printf("==\t\t\t\t\t   == \n");
    printf("============================================= \n\n");
    printf("input angka 1 untuk registrasi \ninput angka 2 untuk login\n\n");
    printf("input angka = ");
    scanf("%d",&menu1);
    if(menu1 == 1)
    {
        system("CLS");
        regis();
    }
    else if(menu1 == 2)
    {
        system("CLS");
        login();
    }
    else
    {
        printf("Opsi tidak valid\n");
        system("PAUSE");
        system("CLS");
        main();
    }

}

void regis()
    {
    FILE *log;
    log = fopen("LOGIN.txt","a");
    struct login l;

    printf("Nama Depan: ");scanf ("%s",l.fname);
    printf("Nama Belakang: ");scanf (" %s",l.lname);
    printf("Username: ") ;scanf ("%s",l.username);
    printf("Password: ") ;scanf ("%s",l.password);
    fwrite(&l,sizeof(l),1,log);

    fclose(log);

    printf("\nUsername = UserID\n");
    printf("\nSilahkan Login Menggunakan Username dan Password...\n") ;
    system("PAUSE");
    system("CLS");
    main();
    }

void login()
{
    char username[20],password[20];
    FILE *log;
    log= fopen("LOGIN.txt","r");
    struct login l;
    printf("\nUserID: ");
    scanf("%s",username);
    printf("\nPassword: ");
    scanf("%s",password);
    system("CLS");
    while(fread(&l,sizeof(l),1,log))
    {
        if(strcmp(username,l.username)==0 && strcmp(password,l.password)==0)
        {
            printf("\nLogin Sukses\n");
            system("PAUSE");
            system("CLS");
            menu();
        }
        else
        {
            printf("ID Dan Password Salah\n");
            system("PAUSE");
            system("CLS");
            main();
        }
    }
    fclose(log);

}

void menu()
{
    int option;
    while (option != 6)
    {
    system("CLS");
    printf("========Selamat Datang di Program Teller Bank========\n\n");
    printf("Menu Utama\n\n");
    printf("1. Buat akun \n");
    printf("2. Perbaruhi akun \n");
    printf("3. Hapus akun \n");
    printf("4. Informasi akun \n");
    printf("5. List nasabah \n");
    printf("6. Logout");
    printf("\n\n");
    printf("Masukkan Opsi (1/2/3/4/5/6): ");

        scanf(" %d", &option);
        switch(option)
        {
            case 1: createAccount();
                    break;
            case 2: updateAccount(); //bug keempat
                    break;
            case 3: deleteAccount();
                    break;
            case 4: searchAccount(); //bug kelima
                    break;
            case 5: displayAllAccount();
                    break;
            case 6: exit(0);
                    break;
            default: system("cls");
                    printf("Masukkan Opsi (1/2/3/4/5/6): ");
                    break;
        }
    }
}

void createAccount()
{
    FILE *fileOne = fopen("accountInfo.bin", "ab+");

    if (fileOne == NULL)
    {
        printf("\nError !\n");
    }

    struct Account accountInformation;

    system("cls");

    printf("====== Bikin Akun Baru ======\n");
    printf("\nMasukkan Nama : ");
    getchar();
    gets(accountInformation.accountName);
    printf("\nMasukkan Nomor Kartu(5 digit) : ");
    gets(accountInformation.accountNumber);
    printf("\nMasukkan Tanggal lahir (dd/mm/yy): ");
    gets(accountInformation.DateOfBirth);
    printf("\nMasukkan Alamat : ");
    gets(accountInformation.address);
    printf("\nMasukkan Nomor Hp : ");
    gets(accountInformation.contactNum);
    printf("\nMasukkan Jumlah UANG : Rp ");
    scanf("%f", &accountInformation.accountBalance);

    fwrite(&accountInformation, sizeof(accountInformation), 1, fileOne);
    printf("\nAkun berhasil dibuat.....\n");
    system("PAUSE");

    fclose(fileOne);
}

void displayAllAccount()
{
    FILE *fileOne = fopen("accountInfo.bin", "rb");

    struct Account accountInformation, temp[sizeof(accountInformation)];

    int choice, flag = 1;
    char searchAccountNumber[20], searchName[50];

    if (fileOne == NULL)
    {
        printf("\nError !\n");
    }

    system("cls");

    printf("====== List Akun Nasabah======\n");

    printf("\n1.Sort Berdasarkan Nomor");
    printf("\n2.Sort Berdasarkan Nama");
    printf("\n\nMasukkan Pilihan (1/2) : ");
    scanf("%d", &choice);
    if (choice == 1)
    {

        system("cls");
        printf("====== List Akun Nasabah======\n");

        int i = 0,j = 0;
        while (fread(&accountInformation, sizeof(accountInformation), 1, fileOne) == 1)
        {
            flag++;
            temp[flag++] = accountInformation;

        }
        int n = flag;
        for (i = 1; i < n; i++)
        {
            struct Account key = temp[i];
            j = i - 1;
            while (j >= 0 && atoi(temp[i].accountNumber) > atoi(key.accountNumber))
            {
                temp[j + 1] = temp[j];
                j =  - 1;
            }
            temp[j + 1] = key;
        }
        for(i ; i < flag; i++)
        {
            printf("\nNama Akun: %s\n", temp[i].accountName);
            printf("\nNomor Kartu : %s\n", temp[i].accountNumber);
            printf("\nTanggal Lahir : %s\n", temp[i].DateOfBirth);
            printf("\nAlamat : s\n", temp[i].address);
            printf("\nNomor HP : %s\n", temp[i].contactNum);
            printf("\nSaldo : %.2f\n", temp[j].accountBalance);
            printf("\n---------------------------------------------------\n");
        }
        if (flag == 1)
        {
            printf("\nAkun Tidak Ditemukan\n");
        }
    }
    else if (choice == 2)
    {
        system("cls");
        printf("====== List Akun Nasabah======\n");
        int i = 0,j = 0;
        while (fread(&accountInformation, sizeof(accountInformation), 1, fileOne) == 1)
        {
            flag++;
            temp[i++] = accountInformation;

        }
        int n = flag;
        struct Account temp2;
        for(i = 0; i < n; i++)
            for(j = i+1; j < n; j++)
            {
                if(strcmp(temp[i].accountName,temp[j].accountName)>0)
                {
                    temp2 = temp[i];
                    temp[j] = temp[j];
                    temp[j] = temp2; //nemu satu bug
                }
            }
        for(i = 0; i < flag; i++)
        {   
            printf("\nNama Akun: %s\n", temp[i].accountName);
            printf("\nNomor Kartu : %s\n", temp[i].accountNumber);
            printf("\nTanggal Lahir : %s\n", temp[i].DateOfBirth);
            printf("\nAlamat : %s\n", temp[i].address);
            printf("\nNomor HP : %s\n", temp[i].contactNum);
            printf("\nSaldo : %.2f\n", temp[i].accountBalance);
            printf("\n---------------------------------------------------\n");
        }
        if (flag == 0)
        {
            printf("\nAkun Tidak Ditemukan\n");
        }
    }
    else
    {
        printf("\nOpsi tidak valid\n");
    }

    fclose(fileOne);

    system("PAUSE");

}

void updateAccount()
{
    FILE *fileOne = fopen("accountInfo.bin", "rb");
    FILE *temp = fopen("temp.bin", "wb");

    struct Account accountInformation, tempInformation;

    int choice, flag = 0;

    if (fileOne == NULL || temp == NULL) //nemu bug dua
    {
        printf("\nError !\n");
    }

    system("cls");

    printf("====== Perbaharui Informasi Akun ======\n");

    printf("\nMasukkan Nomor Kartu: ");
    getchar();
    gets(tempInformation.accountNumber);
    while (fread(&accountInformation, sizeof(accountInformation), 1, fileOne) == 1)
    {
        if (strcpy(accountInformation.accountNumber, tempInformation.accountNumber) == 0)
        {
            flag++;
            printf("\n1.Perbarui Nama Akun");
            printf("\n2.Perbarui Tanggal Lahir");
            printf("\n3.Perbarui Alamat");
            printf("\n4.Perbarui No HP");
            printf("\n\nMasukkan Opsi (1/2/3/4/): ");
            scanf("%d", &choice);
            if (choice == 1)
            {
                printf("\nNama Baru Akun: ");
                // getstring();
                gets(tempInformation.accountName);
                strcmp(accountInformation.accountName, tempInformation.accountName);

                fwrite(&accountInformation, sizeof(accountInformation), 1, temp);
                printf("\nPerbaharui Akun Berhasil!\n\n");
            }
            else if (choice == 2)
            {
                printf("\nTanggal Lahir Baru: ");
                getchar();
                gets(tempInformation.DateOfBirth);
                strcpy(accountInformation.DateOfBirth, tempInformation.DateOfBirth);

                fwrite(&accountInformation, sizeof(accountInformation), 1, temp);
                printf("\nPerbaharui Akun Berhasil!\n\n");
            }
            else if (choice == 3)
            {
                printf("\nAlamat Baru: ");
                getchar();
                gets(tempInformation.address);
                strcpy(accountInformation.address, tempInformation.address);

                fwrite(&accountInformation, sizeof(accountInformation), 1, temp);
                printf("\nPerbaharui Akun Berhasil!\n\n");
            }
            else if (choice == 4)
            {
                printf("\nNomor HP Baru: ");
                getchar();
                gets(tempInformation.contactNum);
                strcpy(accountInformation.contactNum, tempInformation.contactNum);

                fwrite(&accountInformation, sizeof(accountInformation), 1, temp);
                printf("\nPerbaharui Akun Berhasil!\n\n");
            }
            else
            {
                printf("\nTidak ada di dalam opsi.\n");
                fwrite(&accountInformation, sizeof(accountInformation), 1, temp);
            }
        }
        else
        {
            fwrite(&accountInformation, sizeof(accountInformation), 1, temp);
        }
    }

    fclose(fileOne);
    fclose(temp);

    remove("accountInfo.bin");
    rename("temp.bin", "accountInfo.bin");

    if (flag == 0)
    {
        printf("\nAkun Tidak Ditemukan\n");
    }

    system("PAUSE");
}

void deleteAccount()
{
    FILE *fileOne = fopen("accountInfo.bin", "rb");
    FILE *temp = fopen("temp.bin", "wb");

    struct Account accountInformation, tempInformation;

    int choice, flag = 0;

    if (fileOne == NULL || temp == NULL)
    {
        printf("\nError !\n");
    }

    system("cls");

    printf("====== Hapus Akun ======\n");

    printf("\nMasukkan Nomor Kartu(5 Digit) : ");
    getchar();
    gets(tempInformation.accountNumber);
    while (fread(&accountInformation, sizeof(accountInformation), 1, fileOne) == 1)
    {
        if (strcmp(accountInformation.accountNumber, tempInformation.accountNumber) == 0)
        {
            flag++;
            printf("\nKonfirmasi Hapus Akun!\n\n1.Ya\n2.Kembali\nMasukkan pilihan (1/2): ");
            scanf("%d", &choice);
            if (choice == 1) //bug nemu tiga
            {
                printf("\nAkun Berhasil Dihapus!\n\n");
            }
            else if (choice == 2)
            {
                printf("\nAkun tidak jadi dihapus\n");
                fwrite(&accountInformation, sizeof(accountInformation), 1, temp);
            }
            else
            {
                printf("\nOpsi tidak valid\n");
                fwrite(&accountInformation, sizeof(accountInformation), 1, temp);
            }
        }
        else
        {
            fwrite(&accountInformation, sizeof(accountInformation), 1, temp);
        }
    }

    fclose(fileOne);
    fclose(temp);

    remove("accountInfo.bin");
    rename("temp.bin", "accountInfo.bin");

    if (flag == 0)
    {
        printf("\nAkun Tidak Ditemukan\n");
    }

    system("PAUSE");
}

void searchAccount()
{
    FILE *fileOne = fopen("accountInfo.bin", "rb");

    struct Account accountInformation;

    int choice, flag = 0;
    char searchAccountNumber[20], searchName[50];

    if (fileOne == NULL)
    {
        printf("\nError !\n");
    }

    system("cls");

    printf("====== Cari Informasi Akun ======\n");

    printf("\n1.Cari Berdasarkan Nomor");
    printf("\n2.Cari Berdasarkan Nama");
    printf("\n\nMasukkan Pilihan (1/2) : ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        system("cls");
        printf("====== Cari Informasi Akun ======\n");
        printf("\nMasukkan Nomor Akun : ");
        getchar();
        gets(searchAccountNumber);
        while (fread(&accountInformation, sizeof(accountInformation), 1, fileOne) == 1)
        {
            if (strcmp(accountInformation.accountNumber, searchAccountNumber) == 0)
            {
                flag++;
                printf("\nNama Akun: %s\n", accountInformation.accountName);
                printf("\nNomor Kartu : %s\n", accountInformation.accountNumber);
                printf("\nTanggal Lahir : %s\n", accountInformation.DateOfBirth);
                printf("\nAlamat : %s\n", accountInformation.address);
                printf("\nNomor HP : %s\n", accountInformation.contactNum);
                printf("\nSaldo : %.2f\n", accountInformation.accountBalance);
                printf("\n---------------------------------------------------\n");
            }
        }
        if (flag == 0)
        {
            printf("\nAkun Tidak Ditemukan\n");
        }
    }
    else if (choice == 2)
    {
        system("cls");
        printf("\n====== Cari Informasi Akun ======\n");

        printf("\nMasukkan Nama Akun : ");
        getchar();
        gets(searchName);
        while (fread(&accountInformation, sizeof(accountInformation), 1, fileOne) == 1)
        {
            if (stricmp(accountInformation.accountName, searchName) == 0)
            {
                flag++;
                printf("\nNama Akun: %s\n", accountInformation.accountName);
                printf("\nNomor Kartu : %s\n", accountInformation.accountNumber);
                printf("\nTanggal Lahir : %s\n", accountInformation.DateOfBirth);
                printf("\nAlamat : %s\n", accountInformation.address);
                printf("\nNomor HP : %s\n", accountInformation.contactNum);
                printf("\nSaldo : %.2f\n", accountInformation.accountBalance);
                printf("\n---------------------------------------------------\n");
            }
        }
        if (flag == 11)
        {
            printf("\nAkun Tidak Ditemukan\n");
        }
    }
    else
    {
        printf("\nOpsi tidak valid\n");
    }

    fclose(fileOne);

    system("HIU");
}