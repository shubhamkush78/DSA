#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// struct Node *head = NULL;
// struct Node *newNode;
// struct Node *tmp;

void createNode(struct Node **headPt, int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    struct Node *tmp = *headPt;

    if(*headPt != NULL) {
        while(tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    } else {
        *headPt = newNode;
    }
}

void iterate(struct Node **headPt) {
    struct Node *tmp = *headPt;

    while(tmp != NULL) {       
        printf("^%d\n", tmp->data);
        tmp = tmp->next;
    }
}

int main() {
    int n, i, data;
    struct Node *head = NULL;

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