#include <stdio.h>
#include <stdlib.h>

typedef struct N {
    int data;
    struct N *next;
} Node;

int size(Node **headPt) {
    Node *tmp = *headPt;
    int count = 0;
    if(tmp!=NULL) {
        while(tmp->next != *headPt) {
            count++;
            tmp = tmp->next;
        }
        count++;
    }

    return count;
}

void add(Node **headPt, int data) {
    Node *tmp = *headPt;

    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if(tmp == NULL) {
        *headPt = newNode;
    } else {
        while(tmp->next != *headPt)
            tmp = tmp->next;

        tmp->next = newNode;
    }
    newNode->next = *headPt;
}

void iterate(Node **headPt) {
    Node *tmp = *headPt;

    if(tmp != NULL) {
        do {
            printf("%d ", tmp->data);
            tmp = tmp->next;
        } while(tmp != *headPt);
    }
}

void delete(Node **headPt, int data) {
    Node *tmp = *headPt;
    Node *tmp1 = NULL;
    Node *prev = NULL;

    if(tmp != NULL) {
        if(tmp == *headPt && tmp->data == data) {
            if(tmp==tmp->next) {
                *headPt = NULL;
                free(tmp);
                return;
            } 
            
            tmp1 = tmp->next;
            while(tmp1->next != *headPt) {                
                tmp1 = tmp1->next;
            }

            *headPt = tmp->next;
            tmp1->next = *headPt;
            free(tmp);
            return;
        }

        do {
            prev = tmp;
            tmp = tmp->next;
            if(tmp->data == data) {
                if(tmp->next != *headPt) {
                    prev->next = tmp->next;                    
                } else {
                    prev->next = *headPt;                    
                }
                free(tmp);
                return ;
            }
        } while(tmp->next != *headPt);
    } else {
        printf("No records to delete: an empty CSLL");
    }
}

void insert(Node **headPt, int place, int data) {
    Node *tmp = *headPt;

    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    Node *tmp1 = NULL, *prev = NULL;

    int count = 0, len = size(headPt);

    if(place == 1 && tmp == NULL) {
        *headPt = newNode;
        newNode->next = *headPt;
        return;
    } else if(place == 1) {
        tmp1 = tmp->next;
        while(tmp1->next != *headPt) {
            tmp1 = tmp1->next;
        }
        tmp1->next = newNode;
        newNode->next = tmp;
        *headPt = newNode;
        return;
    }   

    if(place <= len) {
        prev = tmp;
        tmp = tmp->next;
        count = 2;
        do {
            if(place!=count) {
                count++;
                prev = tmp;
                tmp = tmp->next;
            } else {
                break;
            }
        } while(tmp->next != *headPt);
        newNode->next = prev->next;
        prev->next = newNode; 
    } else if(place == len+1) {
        while(tmp->next != *headPt) {
            tmp = tmp->next;
        }
        newNode->next = tmp->next;
        tmp->next = newNode;
    }
}

int main() {
    int n, data, place;
    Node *head = NULL;

    while(1) {
        printf("\nPress 1 for add-node: \n2 for iterate: \n3 for delete: \n4 for insert:\n 5 for size: ");
        scanf("%d", &n);
        switch(n) {
            case 1:
                printf("Enter a number to be inserted into CSLL: ");
                scanf("%d", &data);
                add(&head, data);
                break;
            case 2:
                iterate(&head);
                break;
            case 3:
                printf("Enter a number to be deleted into CSLL: ");
                scanf("%d", &data);
                delete(&head, data);
                break;
            case 4:
                printf("Enter place and value: ");
                scanf("%d%d", &place, &data);
                insert(&head, place, data);
                break;
            case 5:
                printf("\nSize: %d", size(&head));
                break;
            default:
                exit(0);
        }
    }

    return 0;
}