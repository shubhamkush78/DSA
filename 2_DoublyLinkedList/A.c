#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
};

void addNode(struct Node **headPt, int data) {
    struct Node* tmp = *headPt;
    
    struct Node* newNode = (struct Node *)malloc(sizeof(struct Node));
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
    int data, n;
    struct Node *head = NULL;

    printf("Enter How many records you want to enter: ");
    scanf("%d", &n);

    while(n-- > 0) {    
        printf("Enter a number to be inserted in the DLL: ");
        scanf("%d", &data);

        addNode(&head, data);
    }

    printf("\n%d %d %d", head->data, head->next->data, head->next->next->data);

    return 0;
}