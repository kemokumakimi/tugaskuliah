#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Login {
    char fname[100];
    char lname[100];
    char username[20];
    char password[20];
};

typedef struct Account {
    char accountName[40];
    char accountNumber[20];
    char DateOfBirth[15];
    char address[50];
    char contactNum[15];
    float accountBalance;
} Account;

void menu();
void createAccount();
void displayAllAccount();
void updateAccount();
void deleteAccount();
void searchAccount();
void regis();
void login();

int main() {
    int choice;
    printf("\n=============================================\n");
    printf("==\t\t\t\t\t   ==\n");
    printf("==  Selamat datang di program teller bank  ==\n");
    printf("==\t\t\t\t\t   ==\n");
    printf("=============================================\n\n");
    printf("input angka 1 untuk registrasi\ninput angka 2 untuk login\n\n");
    printf("input angka = ");
    scanf("%d", &choice);
    if (choice == 1) {
        system("CLS");
        regis();
    } else if (choice == 2) {
        system("CLS");
        login();
    } else {
        printf("Opsi tidak valid\n");
        system("PAUSE");
        system("CLS");
        main();
    }
}

void regis() {
    FILE *log;
    log = fopen("LOGIN.txt", "a");
    struct Login l;

    printf("Nama Depan: ");
    scanf("%s", l.fname);
    printf("Nama Belakang: ");
    scanf("%s", l.lname);
    printf("Username: ");
    scanf("%s", l.username);
    printf("Password: ");
    scanf("%s", l.password);
    fwrite(&l, sizeof(l), 1, log);

    fclose(log);

    printf("\nUsername = UserID\n");
    printf("\nSilahkan Login Menggunakan Username dan Password...\n");
    system("PAUSE");
    system("CLS");
    main();
}

void login() {
    char username[20], password[20];
    FILE *log;
    log = fopen("LOGIN.txt", "r");
    struct Login l;
    printf("\nUserID: ");
    scanf("%s", username);
    printf("\nPassword: ");
    scanf("%s", password);
    system("CLS");
    while (fread(&l, sizeof(l), 1, log)) {
        if (strcmp(username, l.username) == 0 && strcmp(password, l.password) == 0) {
            printf("\nLogin Sukses\n");
            system("PAUSE");
            system("CLS");
            menu();
        } else {
            printf("ID Dan Password Salah\n");
            system("PAUSE");
            system("CLS");
            main();
        }
    }
    fclose(log);
}

void menu() {
    char option;
    while (option != '6') {
        system("CLS");
        printf("========Selamat Datang di Program Teller Bank========\n\n");
        printf("Menu Utama\n\n");
        printf("1. Buat akun\n");
        printf("2. Perbaruhi akun\n");
        printf("3. Hapus akun\n");
        printf("4. Informasi akun\n");
        printf("5. List nasabah\n");
        printf("6. Logout");
        printf("\n\n");
        printf("Masukkan Opsi (1/2/3/4/5/6): ");

        scanf(" %c", &option);
        switch (option) {
            case '1':
                createAccount();
                break;
            case '2':
                updateAccount();
                break;
            case '3':
                deleteAccount();
                break;
            case '4':
                searchAccount();
                break;
            case '5':
                displayAllAccount();
                break;
            case '6':
                exit(0);
                break;
            default:
                system("cls");
                printf("Masukkan Opsi (1/2/3/4/5/6): ");
                break;
        }
    }
}

void createAccount() {
    FILE *fileOne = fopen("accountInfo.bin", "ab+");
    if (fileOne == NULL) {
        printf("\nError !\n");
    }

    Account accountInformation;

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

void displayAllAccount() {
    FILE *fileOne = fopen("accountInfo.bin", "rb");

    Account accountInformation, temp[100];

    int choice, flag = 0;
    char searchAccountNumber[20], searchName[50];

    if (fileOne == NULL) {
        printf("\nError !\n");
    }

    system("cls");

    printf("====== List Akun Nasabah======\n");

    printf("\n1.Sort Berdasarkan Nomor");
    printf("\n2.Sort Berdasarkan Nama");
    printf("\n\nMasukkan Pilihan (1/2) : ");
    scanf("%d", &choice);
    if (choice == 1) {
        system("cls");
        printf("====== List Akun Nasabah======\n");

        int i = 0, j = 0;
        while (fread(&accountInformation, sizeof(accountInformation), 1, fileOne) == 1) {
            temp[flag++] = accountInformation;
        }
        int n = flag;
        for (i = 1; i < n; i++) {
            Account key = temp[i];
            j = i - 1;
            while (j >= 0 && atoi(temp[j].accountNumber) > atoi(key.accountNumber)) {
                temp[j + 1] = temp[j];
                j = j - 1;
            }
            temp[j + 1] = key;
        }
        for (i = 0; i < flag; i++) {
            printf("\nNama Akun: %s\n", temp[i].accountName);
            printf("\nNomor Kartu : %s\n", temp[i].accountNumber);
            printf("\nTanggal Lahir : %s\n", temp[i].DateOfBirth);
            printf("\nAlamat : %s\n", temp[i].address);
            printf("\nNomor HP : %s\n",
