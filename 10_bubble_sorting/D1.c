#include <stdio.h>
#include <stdlib.h>

typedef struct N {
    int data;
    struct N *next;
} Node;

void reverse(Node* next) {
    if(next != NULL) {
        reverse(next->next);
        printf("%d ", next->data);
    }    
}

void insert(Node** headPt, int place, int data) {
    int len = length(headPt);
    if(place>len+1)
        return;

    Node* tmp = *headPt;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    int count = 1;
    if(tmp == *headPt && count == place) {
        newNode->next = tmp;
        *headPt = newNode;
        return ;
    } 

    while(tmp != NULL) {
        if(count == place-1) {
            newNode->next = tmp->next;
            tmp->next = newNode;
            return ;
        }

        count++;
        tmp = tmp->next;
    }
}

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
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
}

void bubble_sort(Node **headPt) {
    if(*headPt != NULL) {
        int i, j, tmp, size = length(headPt);
        Node *t, *tnx;

        for(i=size-1; i>0; i--) {
            t = *headPt;
            tnx = t->next;

            for(j = 0; j < i; j++) {
                if(t->data > tnx->data) {
                    tmp = t->data;
                    t->data = tnx->data;
                    tnx->data = tmp;
                }

                t = tnx;
                tnx = tnx->next;
            }
        }
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

    bubble_sort(&head);

    // iteration
    iterate(&head);

    // printf("\nEnter position and data: ");
    // scanf("%d%d", &i, &data);

    // // printf("\nThe Search Result: %d", search(&head, data));    
    // insert(&head, i, data);
    // iterate(&head);

    // reverse(head);

    return 0;
}