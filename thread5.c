#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<time.h>



void* thread_function(void* args)
{
    int *dice = (int *) malloc(sizeof(int));
    *dice = rand()%6+1;

    return (void*)dice;
}


int main()
{
    srand(time(NULL));

    pthread_t t1, t2;

    pthread_create(&t1, NULL, &thread_function, NULL);

    int* res;

    pthread_join(t1, (void**) &res);

    printf("Dice Roll Output: %d\n", *res);
    free(res);

    return 0;
}
