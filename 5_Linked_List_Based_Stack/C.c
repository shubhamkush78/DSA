#include <stdio.h>
#include <stdlib.h>

typedef struct N {
    int data;
    struct N *next;
} Node;

int isempty(Node *top) {
    return top == NULL;
}

void push(Node **topPt, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = *topPt;
    *topPt = newNode;
}

int pop(Node **topPt) {
    Node *tmp = *topPt;

    if(isempty(tmp)) {
        printf("\nThe Stack Is Empty...!!");
        return -1;
    } else {
        int a = tmp->data;
        *topPt = tmp->next;
        free(tmp);
        return a;
    }
}

int peek(Node *top) {
    if(isempty(top)) {
        printf("\nThe Stack Is Empty...!!");
        return -1;
    } else
        return top->data;
}

void iterate(Node *top) {

    if(top == NULL) {
        printf("\nThe Stack Is Empty...!!");
        return ;
    }

    while(top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
}

int main() {
    int n, data;
    Node *top = NULL;

    while(1) {
        printf("\nPress\n1 for push()\n2 for pop()\n3 for peek\n4 for isempty()\n5 for iterate()\n6 for exit(): ");
        scanf("%d", &n);

        printf("\n");
        switch(n) {
            case 1:
                printf("Enter a number: ");
                scanf("%d", &data);
                push(&top, data);
                break;
            case 2:
                data = pop(&top);
                if(data != -1)
                    printf("Data removed: %d", data);
                break;
            case 3:
                data = peek(top);
                if(data != -1)
                    printf("Data read: %d", data);
                break;
            case 4:
                printf("Is stack empty?: %s", isempty(top)?"yes":"no");
                break;
            case 5:
                iterate(top);
                break;
            default:
                exit(0);
        }
    }

    return 0;
}