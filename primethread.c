#include <stdio.h>
#include <pthread.h>

// Function to check if a number is prime
int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Thread function to print prime numbers
void *print_primes(void *arg) {
    int limit = *((int *)arg);
    for (int i = 2; i <= limit; ++i) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <limit>\n", argv[0]);
        return 1;
    }

    int limit = atoi(argv[1]);

    pthread_t prime_thread;

    // Create a thread that calls the print_primes function
    if (pthread_create(&prime_thread, NULL, print_primes, &limit)) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

    // Wait for the thread to finish
    if (pthread_join(prime_thread, NULL)) {
        fprintf(stderr, "Error joining thread\n");
        return 1;
    }

    return 0;
}
