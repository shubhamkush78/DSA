#include <stdio.h>
#include <stdlib.h>

typedef struct N {
    int data;
    struct N *next;
} Node;

int length(Node** headPt) {
    int length = 0;

    Node* tmp = *headPt;

    while(tmp!=NULL) {
        length++;
        tmp = tmp->next;
    }

    return length;
}

void deleteNode(Node** headPt, int data) {
    Node *tmp = *headPt;
    Node *delNode = NULL;
    Node *prev = NULL;

    while(tmp != NULL) {
        if(tmp == *headPt && tmp->data == data) {
            *headPt = tmp->next;
            free(tmp);
            return ;
        } else if(tmp->data == data) {
            prev->next = tmp->next;
            free(tmp);
            return ;
        }

        prev = tmp;
        tmp = tmp->next;
    }    
}

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
    // iterate(&head);

    // printf("\nEnter data to be deleted: ");
    // scanf("%d", &data);
    // deleteNode(&head, data);
    // printf("\n");
    // iterate(&head);

    int len = length(&head);

    printf("Length: %d", len);

    return 0;
}