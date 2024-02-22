#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>


void* thread_function(void* args)
{
    int* val = (int*) args;

    printf("Hello from Thread.\n");
    printf("Passed argument val: %p\n", val);
    printf("Passed argument *val: %d\n", *val);
}


int main()
{
    pthread_t thread1, thread2;

    int val = 100;

    printf("Address to pass: %p\n", &val);

    pthread_create(&thread1, NULL, &thread_function, (void*) &val);

    pthread_join(thread1, NULL);


    return 0;
}