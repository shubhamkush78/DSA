#include <stdio.h>
#include <stdlib.h>

typedef struct N {
    int data;
    struct N *next;
} Node;

void createNode(Node **headPt, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    Node *tmp = *headPt;

    if(*headPt != NULL) {
        while(tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    } else {
        *headPt = newNode;
    }
}

void iterate(Node **headPt) {
    Node *tmp = *headPt;

    while(tmp != NULL) {       
        printf("^%d\n", tmp->data);
        tmp = tmp->next;
    }
}

int main() {
    int n, i, data;
    Node *head = NULL;

    printf("Enter a number: ");
    scanf("%d", &n);

    for(i=0;i<n;i++) {
        printf("Enter Record to be inserted in the node: ");
        scanf("%d", &data); 
        createNode(&head, data); 
    }

    // iteration
    iterate(&head);

    return 0;
}