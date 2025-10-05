#include <stdio.h>
#include <stdlib.h>

typedef struct N {
    int data;
    struct N *next;
} Node;

int search(Node** headPt, int data) {
    int flag = 0;
    Node* tmp = *headPt;

    while(tmp != NULL) {
        if(tmp->data==data) {
            flag = 1;
            break;
        }
        tmp = tmp->next;
    }

    return flag;
}

int isempty(Node** headPt) {
    return *headPt==NULL?1:0;
}

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

    printf("\nEnter a number: ");
    scanf("%d", &data);

    printf("\nThe Search Result: %d", search(&head, data));    

    return 0;
}