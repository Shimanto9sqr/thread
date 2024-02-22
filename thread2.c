#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

int counter=0;
pthread_mutex_t mutex;


void* thread_function()
{

    for(int i=0; i<100; i++)
    {
        pthread_mutex_lock(&mutex);
        counter++;
        pthread_mutex_unlock(&mutex);
    }


}


int main()
{
    //pthread_t thread1, thread2;
    pthread_t threads[4];
    pthread_mutex_init(&mutex, NULL);

    for(int i=0; i<4; i++)
    {
        printf("Executing Thread %d\n", i);
        pthread_create(&threads[i], NULL, &thread_function, NULL);
    }

    for(int i=0; i<4; i++)
    {
        pthread_join(threads[i], NULL);
        printf("Execution Complete Thread %d\n", i);
    }


    //pthread_create(&thread1, NULL, &thread_function, NULL);

    //pthread_create(&thread2, NULL, &thread_function, NULL);


    //pthread_join(thread1, NULL);
    //pthread_join(thread2, NULL);
    printf("Counter: %d\n", counter);

    pthread_mutex_destroy(&mutex);

    return 0;
}
