#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int value;
    void *next;
}node;

node *head = NULL;

void printList(){
    node *current = head;
    while(current != NULL){
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("\n");
    return;
}

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

int removeNode(int data){
    node *current = head;
    node *prev = head;
    while(current != NULL){
        if(current->value==data){
            if(current == head){
                head = current->next;
            }
            else{
                prev->next = current->next;
                free(current);
                current == NULL;
            }

            return 1;
        }
        prev = current;
        current = current->next;
    }

    return 0;
}

node *insertNode(int data, int position){
    node *current = head;
    while(current != NULL && position != 0){

        position--;
    }

    if(position != 0){
        printf("List is too short to contain requested position\n");
        return NULL;
    }

    node *new = malloc(sizeof(node));
    if(new == NULL){
        return NULL;
    }
    new->value = data;
    new->next = current->next;
    current->next = new;
    return new;
}

int main(){
    int option = -1;
    int option2; 
    node *new;
    while(option != 5){
        printMenu();
        int num_recieved = scanf("%d", &option);
        if(num_recieved == 1 && option > 0 && option <= 5){
            switch(option){
                case 1:
                    printf("Value to store?\n");
                    scanf("%d", &option);
                    new = addNode(option);
                    break;
                case 2:
                    printf("Value to remove?\n");
                    scanf("%d", &option);
                    int retVal = removeNode(option);
                    if(retVal){
                        printf("Node has been removed\n");
                    }
                    else{
                        printf("Node could not be found\n");
                    }
                    break;
                case 3:
                    printf("Value to store?\n");
                    scanf("%d", &option);
                    printf("Index of node to store it at?\n");
                    scanf("%d", &option2);
                    new = insertNode(option, option2);
                    if(new == NULL){
                        printf("Failed to insert into list\n");
                    }
                    break;
                case 4:    
                    printList();
                    break;
            }
        }
    }

}
