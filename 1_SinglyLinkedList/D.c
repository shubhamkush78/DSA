#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *newNode;
struct Node *tmp;

void createNode() {
    newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter Record to be inserted in the node: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;

    if(head != NULL) {
        tmp = head;
        while(tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    } else {
        head = newNode;
    }
}

int main() {
    int n, i;

    printf("Enter a number: ");
    scanf("%d", &n);

    for(i=0;i<n;i++) { 
        createNode();       
        // newNode = (struct Node*)malloc(sizeof(struct Node));
        // printf("Enter Record to be inserted in the node: ");
        // scanf("%d", &newNode->data);
        // newNode->next = NULL;

        // if(head != NULL) {
        //     tmp = head;
        //     while(tmp->next != NULL) {
        //         tmp = tmp->next;
        //     }
        //     tmp->next = newNode;
        // } else {
        //     head = newNode;
        // }
    }

    // iteration
    tmp = head;

    while(tmp != NULL) {       
        printf("#%d\n", tmp->data);
        tmp = tmp->next;
    }

    return 0;
}