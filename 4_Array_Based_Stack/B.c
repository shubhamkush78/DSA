// File inclusion directive
#include <stdio.h>
#include <stdlib.h>

// Simple macro substitution directive
#define MAX_SIZE 5

typedef struct {
    int array[MAX_SIZE];
    int top;
} Stack;

int isempty(Stack *stack) {
    return stack->top == -1;
}

int isfull(Stack *stack) {
    return stack->top == MAX_SIZE-1;
}

Stack* create_stack() {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;

    return stack;
}

void push(Stack *stack, int data) {
    if(isfull(stack))
        printf("\nThe Stack Is Full...");
    else 
        stack->array[++stack->top] = data;
}

int pop(Stack *stack) {
    if(isempty(stack)) {
        printf("\nThe Stack is Empty...");
        return 0;
    } else 
        return stack->array[stack->top--];
}

int peek(Stack *stack) {
    return stack->array[stack->top];
}

int main() {
    int n, data;
    Stack *stack = NULL;

    while(1) {
        printf("\n\nPress\n1 for create_stack()\n2 for isempty()\n3 for isfull()\n4 for push()\n5 for pop()\n6 for peek()\n7 for exit(): ");
        scanf("%d", &n);

        printf("\n");
        switch(n) { 
            case 1:
                stack = create_stack();
                break;        
            case 2:
                printf("Is the stack empty: %d", isempty(stack));
                break;
            case 3:
                printf("Is the stack full: %d", isfull(stack));
                break;
            case 4:
                printf("Enter a number: ");
                scanf("%d", &data);
                push(stack, data);
                break;
            case 5:
                printf("Record removed: %d", pop(stack));
                break;
            case 6:
                printf("Record read: %d", peek(stack));
                break;
            default:
                exit(0);
        }
    }

    return 0;
}