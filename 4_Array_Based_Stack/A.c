#include <stdio.h>
#include <stdlib.h>

int arr[5];
int top = -1;

int isempty() {
    return top == -1;
}

int isfull() {
    return top == 5-1;
}

void push(int data) {
    if(isfull()) {
        printf("\nThe Stack is full....");
    } else {
        arr[++top] = data;
    }        
}

int pop() {
    if(isempty()) {
        printf("\nThe Stack is empty");
        return 0;
    } else {
        return arr[top--];
    }
}

int peek() {
    return arr[top];
}

int main() {
    int n, data;

    while(1) {
        printf("\n\nPress\n1 for isempty()\n2 for isfull()\n3 for push()\n4 for pop()\n5 for peek()\n6 for exit(): ");
        scanf("%d", &n);

        printf("\n");
        switch(n) {        
            case 1:
                printf("Is the stack empty: %d", isempty());
                break;
            case 2:
                printf("Is the stack full: %d", isfull());
                break;
            case 3:
                printf("Enter a number: ");
                scanf("%d", &data);
                push(data);
                break;
            case 4:
                printf("Record removed: %d", pop());
                break;
            case 5:
                printf("Record read: %d", peek());
                break;
            default:
                exit(0);
        }
    }

    return 0;
}