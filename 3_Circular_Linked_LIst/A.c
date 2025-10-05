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

int main() {
    int n, data;
    Node *head = NULL;

    while(1) {
        printf("\nPress 1 for add-node: \n2 for iterate: ");
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
            default:
                exit(0);
        }
    }

    return 0;
}