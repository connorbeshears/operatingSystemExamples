#include <stdio.h>
#include <stdlib.h>

typedef struct intVec {
    int * vec; //the actual array for our data
    int size; // these next two are pretty much meta data about our array
    int capacity;
} intVec;

//these would go in a .h file with header guards
void iv_init(intVec * self);
void iv_cleanup(intVec * self);
void iv_push(intVec * self, int val);
int iv_get(intVec self, int idx, int * val);
int iv_set(intVec self, int idx, int val);

//keep this in this class
int main(){
    intVec v;
    iv_init(&v); // creates the space in memory

    iv_push(&v, 5); //push 5 into the vector
    int result; // make a space for the result
    if(iv_get(v, 0, &result)){ // gets the result, if we don't have an OOB error
        printf("Value at index 0: %d\n", result);
    }
    iv_cleanup(&v); // clean up the vector
    return 0; 
}


//everything below here would go in a .c
void iv_init(intVec * self){
    (*self).size = 0; //Go to the actual object, and set self.size, parenthesis are important

    self -> capacity = 2; //This is the same as above
    self -> vec = (int*) calloc(self->capacity, sizeof(int)); //this is basically an array
}

void iv_cleanup(intVec * self){
    free(self -> vec);
    self->vec = NULL; // set to null to prevent double frees
    self->size = 0;
    self->capacity = 0;
}

void iv_push(intVec * self, int val){
    //this checks to make sure we don't need more space
    if(self->size == self->capacity){
        self->capacity *= 2; //double the total number of things we can have
        self->vec = (int*) realloc(self->vec, self->capacity * sizeof(int)); // double the indexes 
    }

    self->vec[self->size] = val; //throw the value at the correct index
    self->size += 1; // increment size
}

int iv_get(intVec self, int idx, int * val){
    if(idx < 0 || idx >= self.size){
        return 0; //returns a zero for false, because OOB exception
    }
    *val = self.vec[idx]; //set passed in area to needed value
    return 1;
}

// we only need the actual vector, because we don't edit the size or capacity
int iv_set(intVec self, int idx, int val){
    if(idx <= 0 || idx >= self.size){
        return 0;
    }
    self.vec[idx] = val;
    return 1;
}