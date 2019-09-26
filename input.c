#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char * inputline = NULL;
    size_t size = 0;
    printf("Enter a sentence: ");
    int nread;
    nread = getline(&inputline, &size, stdin);
    printf("%d characters read\n", nread);
    printf("%ld is the size\n", size);
    printf("Input String: %s\n", inputline);

    char * tok;
    tok = strtok(inputline, " \n");
    while(tok){
        printf("%s\n", tok);
        tok = strtok(NULL, " \n");
    }

    free(inputline);
    return 0;
}