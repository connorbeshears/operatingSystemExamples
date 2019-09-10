#include <stdio.h> //imports
#include "functions.h"

// in functions.h
// //func prototypes
// int isPrime(int n);

int main(int argc, char* argv[]){
    for(int i=0; i<10; ++i){
        //printf("hello world\n");
        printf("%d is prime? %d\n", i, isPrime(i));
    }
    return(0);
}

//func definitons
//moved to functions.c
// int isPrime(int n){
//     for(int i = 2; i * i <= n; ++i){
//         if(n % i == 0) return 0;
//     }
//     return 1; 
// }