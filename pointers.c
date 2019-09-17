#include <stdio.h>

void swap(int *x, int *y);


int main() {
    int x = 5;
    int * ptr = &x;
    printf("%d\n", x);
    printf("%p\n", &x); //the & sign means access the address of the variable
    printf("%p\n", ptr); //don't need &, because ptr is already holding the address
    printf("%d\n", *ptr); // * means go to the address, and grab the value
    *ptr = 10; //changes the value of x
    printf("%d\n", x);

    int a = 10;
    int b = 15;
    printf("%d %d\n", a, b);
    swap(&a, &b); // function needs a pointer, so we pass in the addresses of the variables
    printf("%d %d\n", a, b);



    return 0;
}


//pass in an arrow to our data, which allows for an easy swap. Imagine using a google doc URL
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}