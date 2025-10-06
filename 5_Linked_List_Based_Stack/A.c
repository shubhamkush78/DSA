#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *top = NULL, *newNode, *tmp;

// struct Node *top = NULL, *newNode;

int isempty() {
    return top == NULL;
}

void push(int data) {
    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

int pop() {
    if(top == NULL) {
        printf("\nThe Stack Is Empty...!!");
        return -1;
    } else {
        int a = top->data;
        tmp = top;
        top = top->next;
        free(tmp);
        return a;
    }
}

int peek() {
    if(top == NULL) {
        printf("\nThe Stack Is Empty...!!");
        return -1;
    } else
        return top->data;
}

void iterate() {
    tmp = top;

    if(top == NULL) {
        printf("\nThe Stack Is Empty...!!");
        return ;
    }

    while(tmp != NULL) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
}

int main() {
    int n, data;

    while(1) {
        printf("\nPress\n1 for push()\n2 for pop()\n3 for peek\n4 for isempty()\n5 for iterate()\n6 for exit(): ");
        scanf("%d", &n);

        printf("\n");
        switch(n) {
            case 1:
                printf("Enter a number: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                data = pop();
                if(data != -1)
                    printf("Data removed: %d", data);
                break;
            case 3:
                data = peek();
                if(data != -1)
                    printf("Data read: %d", data);
                break;
            case 4:
                printf("Is stack empty?: %s", isempty()?"yes":"no");
                break;
            case 5:
                iterate();
                break;
            default:
                exit(0);
        }
    }

    return 0;
}