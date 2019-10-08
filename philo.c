#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#define PHILS 5
pthread_mutex_t chopsticks[PHILS]; // this is an array of "keys" if a thread has already locked one, 
                                    // the other thread will wait to grab it 
sem_t sharedChops;

void * phil(void * args);
void * semphil(void * args);

int main(){
    pthread_t tids[PHILS];
    int ids[PHILS];
    void * result;
    // for(int i=0; i<PHILS; i++){
    //     pthread_mutex_init(&chopsticks[i], NULL);
    // }
    sem_init(&sharedChops, 0, PHILS / 2);
    for(int i=0; i<PHILS; i++){
        ids[i] = i;
        pthread_create(&tids[i], NULL, semphil, &ids[i]);
    }

    for(int i=0; i<PHILS; i++){
        pthread_join(tids[i], &result);
    }
    // for(int i=0; i<PHILS; i++){
    //     pthread_mutex_destroy(&chopsticks[i]);
    // }
    sem_destroy(&sharedChops);

    return 0;
}

void * phil(void * args){
    int label = *((int*) args);
    printf("Phil %d is awake\n", label);
    //add dijkstra 
    int c1 = label;
    int c2 = (label + 1) % PHILS;
    if(c2 < c1){
        c1 = c2;
        c2 = label;
    }

    for(int i = 0; i < 5; i++){
        pthread_mutex_lock(&chopsticks[c1]); // locks the mutex, this means "grab the chopstick with the same index"
        usleep(500);
        pthread_mutex_lock(&chopsticks[c2]); //Grab the other chopstick, mod by PHILS to prevent IOB errors
        printf("Phil %d is eating!! \n", label); // this is where you would do the things with whatever data
        usleep(500); // make the eating take half a second
        pthread_mutex_unlock(&chopsticks[c1]); //this unlocks the mutex, "put chopsticks back down"
        usleep(500);
        pthread_mutex_unlock(&chopsticks[c2]);  //drop the other chopstick, mod by PHILS to prevent IOB errors
        printf("Phil %d is now thinking...\n", label);
    }
    pthread_exit(NULL);
}

//Same solution, using semaphores
void * semphil(void * args){
    int label = *((int*) args);
    printf("Phil %d is awake\n", label);
    for(int i = 0; i < 5; i++){
        sem_wait(&sharedChops);
        printf("Phil %d is eating!! \n", label); // this is where you would do the things with whatever data
        usleep(1000000);
        sem_post(&sharedChops);
        printf("Phil %d is now thinking...\n", label);
    }
    pthread_exit(NULL);
}