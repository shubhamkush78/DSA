#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int isempty(struct Node *top) {
    return top == NULL;
}

void push(struct Node **topPt, int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = *topPt;
    *topPt = newNode;
}

int pop(struct Node **topPt) {
    struct Node *tmp = *topPt;

    if(tmp == NULL) {
        printf("\nThe Stack Is Empty...!!");
        return -1;
    } else {
        int a = tmp->data;
        *topPt = tmp->next;
        free(tmp);
        return a;
    }
}

int peek(struct Node *top) {
    if(top == NULL) {
        printf("\nThe Stack Is Empty...!!");
        return -1;
    } else
        return top->data;
}

void iterate(struct Node *top) {

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
    struct Node *top = NULL;

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