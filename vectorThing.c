#include <stdio.h>
#include <stdlib.h>

typedef struct intVec {
    int * vec;
    int size;
    int capacity;
} intVec;
void iv_init(intVec * self);


int main(){
    return 0; 
}



void iv_init(intVec * self){
    (*self).size = 0; //Go to the actual object, and set self.size, parenthesis are important

}