#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

void* thread_function1()
{
    printf("Hello from Thread1.\n");

    for(int i=0; i<100; i++)
    {
        printf("Thread1: %d\n", i);

        if(i%5==0)
        {
            sleep(1);
        }
    }
}

void* thread_function2()
{
    printf("Hello from Thread2.\n");

    for(int i=0; i<100; i++)
    {
        printf("Thread2: %d\n", i);

        if(i%5==0)
        {
            sleep(1);
        }
    }
}

int main()
{
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, &thread_function1, NULL);

    pthread_create(&thread2, NULL, &thread_function2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
