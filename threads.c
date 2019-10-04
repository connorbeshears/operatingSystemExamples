#include <stdio.h>
#include <pthread.h>

void * my_thread(void* args);

int main(){
    const int THREADS = 3;
    pthread_t tids[THREADS]; //thread arrays
    int label[THREADS]; 
    void * result; //space for thread return
    for(int i = 0; i<THREADS; i++){
        label[i] = i;
        pthread_create(&tids[i], NULL, my_thread, (void *) &label[i]); // create thread with pointer to thread, args, function, function args
    }
    for(int i = 0; i<THREADS; i++){
        pthread_join(tids[i], &result); // tells main to wait until thread is done
    }
    printf("all done!\n");
    return 0;
}

void * my_thread(void* args){
    int * intarg = (int *)args;
    for(int i = 0; i < 10; i++){
        printf("Hello World%d\n", *intarg);
    }
    pthread_exit(NULL); //return nothing from the thread
}