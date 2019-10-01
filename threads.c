#include <stdio.h>
#include <pthread.h>

void * my_thread(void* args);

int main(){
    pthread_t tid; //thread object
    int label = 1;
    void * result; //space for thread return
    pthread_create(&tid, NULL, my_thread, (void *) &label); // create thread with pointer to thread, args, function, function args
    pthread_join(tid, &result); // tells main to wait until thread is done
    return 0;
}

void * my_thread(void* args){
    int * intarg = (int *)args;
    for(int i = 0; i < 10; i++){
        printf("Hello World%d\n", *intarg);
    }
    pthread_exit(NULL); //return nothing from the thread
}