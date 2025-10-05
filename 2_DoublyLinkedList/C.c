#include <stdio.h>
#include <stdlib.h>

typedef struct N {
    struct N *prev;
    int data;
    struct N *next;
} Node;

int isempty(Node** headPt) {
    return *headPt == NULL;
} 

int length(Node **headPt) {
    Node *tmp = *headPt;
    int len = 0;

    while(tmp != NULL) {
        len++;
        tmp = tmp->next;
    }

    return len;
}

void iterate(Node **headPt) {
    Node* tmp = *headPt;

    while(tmp != NULL) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
}

void reverse(Node** headPt) {
    Node* tmp = *headPt;

    while(tmp != NULL && tmp->next != NULL) {
        tmp = tmp->next;
    }

    while(tmp != NULL) {
        printf("%d ", tmp->data);
        tmp = tmp->prev;
    }
}

void delete() {

}

void insert(Node** headPt, int place, int data) {
    int len = length(headPt);
    if(place > len + 1) 
        return;

    Node* tmp = *headPt;
    int count = 1;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;

    if(tmp == NULL && place == 1) { 
        *headPt = newNode;
        return ;
    }

    while(tmp != NULL) {
        if(count == place) {
            if(tmp->prev == NULL) {
                newNode->next = tmp;
                tmp->prev = newNode;
                *headPt = newNode;
                return ;
            } else {
                newNode->prev = tmp->prev;
                newNode->next = tmp;
                tmp->prev = newNode;
                newNode->prev->next = newNode;
                return ;
            }            
        } 
        count++;

        if(tmp->next == NULL && count == place) {
            tmp->next = newNode;
            newNode->prev = tmp;

            return ;
        }

        tmp = tmp->next;
    }   
}

int search() {

}

void addNode(Node **headPt, int data) {
    Node* tmp = *headPt;
    
    Node* newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;

    if(tmp == NULL) {
        *headPt = newNode;
        return;
    }

    do {
        if(tmp->next == NULL){
            tmp->next = newNode;
            newNode->prev = tmp;
            return ;
        }

        tmp = tmp->next;
    } while(tmp != NULL);
}

int main() {
    int data, n, place = 0;
    Node *head = NULL;

    while(1) {

        printf("\n####################################################\n");

        printf("Press 1 for iterate:\nPress 2 for add:\nPress 3 for insert:\nPress 4 for delete:\nPress 5 for search:\nPress 6 for length:\nPress 7 for isempty:\nPress 8 for reverse: ");
        scanf("%d", &n);

        printf("\n####################################################\n");

        printf("\n");
        switch(n) {
            case 1:
                iterate(&head);
                break;
            case 2:
                printf("Enter a number to be inserted in the DLL: ");
                scanf("%d", &data);

                addNode(&head, data);
                break;
            case 3:                
                printf("Enter place and value to be inserted: ");
                scanf("%d%d", &place, &data);
                insert(&head, place, data);
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                printf("Length of DLL is: %d", length(&head));
                break;
            case 7:
                printf("Is DLL Empty: %s", isempty(&head)?"true":"false");
                break;
            case 8:
                reverse(&head);
                break;
            default:
                exit(0);
        }
    }

    return 0;
}