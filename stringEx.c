#include <stdio.h>
#include <string.h>


int main(){
    char str[] = "hello world";
    printf("%s\n", str);
    printf("%ld\n", strlen(str)); //prints length of string
    return 0;
}

// char * * vec  <-- need this for the project
//vec = malloc(2*sizeof(char*))
//vec[0] = malloc((strlen(whatever)+1) * sizeof(char))
// read the docs for string.h