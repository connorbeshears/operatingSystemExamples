#include <stdio.h>
// Structs
typedef struct _table {
    double length, width;
    int legs;
} table;

struct foo { int a, b, c; };

int main(){
    table desk;
    desk.length = 5.5;
    desk.width = 1.5;
    desk.legs = 2;

    printf("size of table:%lu\n", sizeof(table));
    printf("size of table legs:%lu\n", sizeof(desk.legs));
    printf("size of table length:%lu\n", sizeof(desk.length));
    printf("size of table width:%lu\n", sizeof(desk.width));

    //make an array pointer
    double * arr = (double *)(&desk);
    printf("Length of table: %f\n", arr[1]);

    struct foo bar;

    return 0;
}

void printTable(table t){
    
}