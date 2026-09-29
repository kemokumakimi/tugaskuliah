#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    FILE *file;
    printf("===> Menulis Data <===");
    char username[50];
    char password[50];
    printf("\nMasukkan username anda: ");
    fgets(username, 50, stdin);
    printf("Masukkan Password anda: ");
    scanf("%s", &password);
    fflush(stdin);

    file = fopen("test.txt", "a");

    if (file == NULL)
    {
        printf("\nTidak dapat membuka file");
    }
    else
    {
        for (int i = 0; i < 2; i++)
        {
           fgets(username, 50, file);
        }
        
        while (fgets(username, 50, file) != NULL)
        {
            printf("%s", username);
        }
        
        if (strlen(username) > 0)
        {
            fputs("\n\n", file);
            fputs("username : ", file);
            fputs(username, file);
            fputs("password : ", file);
            fputs(password, file);
        }
        fclose(file);

        printf("\nData berhasil di tulis di file test.txt");
    }

    return 0;
}
