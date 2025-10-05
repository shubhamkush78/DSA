#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *newNode;
struct Node *tmp;

void createNode(int data) {
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
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

void iterate() {
    tmp = head;

    while(tmp != NULL) {       
        printf("^%d\n", tmp->data);
        tmp = tmp->next;
    }
}

int main() {
    int n, i, data;

    printf("Enter a number: ");
    scanf("%d", &n);

    for(i=0;i<n;i++) {
        printf("Enter Record to be inserted in the node: ");
        scanf("%d", &data); 
        createNode(data); 
    }

    // iteration
    iterate();
    // tmp = head;

    // while(tmp != NULL) {       
    //     printf("@%d\n", tmp->data);
    //     tmp = tmp->next;
    // }

    return 0;
}