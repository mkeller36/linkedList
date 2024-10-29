#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int value;
    struct node * nextNode;
}node;

typedef struct{
    struct node * head;
    struct node * tail;
}list;

/*TODO; make add node function
        make delete node function
        make search nodes function
        */

int main(){
    node n1;
    node n2;
    n1.value = 1;
    n1.nextNode = &n2;

    return 1;
}
