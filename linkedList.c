#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int value;
    void *next;
}node;

node *head = NULL;

void printMenu(void){
    printf("You have the following options:\n");
    printf("\t1. Add a node to the list.\n");
    printf("\t2. Remove a node from the list.\n");
    printf("\t3. Insert a node to the list\n");
    printf("\t4. Print your list.\n");
    printf("\t5. Exit\n");
}

node *addNode(int value){
    node *new;
    if(head ==NULL){
        new = malloc(sizeof(node));
        if(new == NULL){
            return NULL;
        }
        new->value = value;
        head = new;
        new->next = NULL;
    }
    else {
        new = malloc(sizeof(node));
        if(new == NULL){
            return NULL;
        }
        new->value = value;
        new->next = head;
        head = new;
    }
    return new;
}

int main(){
    int option = -1;
    while(option != 5){
        printMenu();
        int num_recieved = scanf("%d", &option);
        if(num_recieved == 1 && option > 0 && option <= 5){
            switch(option){
                case 1:

                case 2:

                case 3:

                case 4:    
            }
        }
    }

}
