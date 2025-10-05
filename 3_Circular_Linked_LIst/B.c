#include <stdio.h>
#include <stdlib.h>

typedef struct N {
    int data;
    struct N *next;
} Node;

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


int main() {
    int n, data;
    Node *head = NULL;

    while(1) {
        printf("\nPress 1 for add-node: \n2 for iterate: \n3 for delete: ");
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
            default:
                exit(0);
        }
    }

    return 0;
}