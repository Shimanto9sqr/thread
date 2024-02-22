// 10 ta thread parallely 10 ta value access korbe

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

int num[10] = {13, 32, 12, 5, 6, 9, 50, 20, 19, 24};

void* thread_function(void* args)
{
    int* index = (int*) args;

    printf("%d\n", num[*index]);

    free(index);
}


int main()
{
    pthread_t threads[10];

    for(int i=0; i<10; i++)
    {
        int* idx = (int*) malloc(sizeof(int));
        *idx=i;

        pthread_create(&threads[i], NULL, &thread_function, idx);
    }


    for(int i=0; i<10; i++)
    {
        pthread_join(threads[i], NULL);
    }


    return 0;
}
