#include <stdio.h>
#include <pthread.h>
#include <unistd.h>


pthread_mutex_t lock;

void* print_numbers(void* arg) {
    pthread_mutex_lock(&lock);
    for (int i = 1; i <= 10; i++) {
        printf("%d ", i);
        fflush(stdout); 
        usleep(100000); 
    }
    printf("\n");
    pthread_mutex_unlock(&lock);
    return NULL;
}

void* print_letters(void* arg) {
    pthread_mutex_lock(&lock);
    for (char c = 'A'; c <= 'J'; c++) {
        printf("%c ", c);
        fflush(stdout);
        usleep(100000);
    }
    printf("\n");
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    pthread_mutex_init(&lock, NULL);

    pthread_create(&thread1, NULL, print_numbers, NULL);
    pthread_create(&thread2, NULL, print_letters, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&lock);

    printf("Program selesai!\n");
    return 0;
}
