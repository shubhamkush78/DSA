#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int array[MAX_SIZE];
int head=-1, tail=-1;

int isempty() {
    return head == -1;
}

int isfull() {
    return head == 0 && tail == MAX_SIZE-1;
}

void enqueue(int data) {
    if(head == -1) {
        head++;
    }

    if(isfull()) {
        printf("No room left in the queue...!!");
        return ;
    } else 
        array[++tail] = data;
}

int dequeue() {
    if(head == -1) {
        printf("The Queue is empty...!");
        return -1;
    }

    if(head == tail) {
        int a = array[head];
        tail = head = -1;
        return a;
    }

    return array[head++];
}

void showall() {
    int i = 0;
    for(i=0;i<MAX_SIZE;i++) {
        printf("%d ", array[i]);
    }
    printf("\nHead: %d and tail: %d", head, tail);
}

int peek() {
    if(isempty())
        return -1;

    return array[head]; 
}

int main() {

    int data, n;

    while(1) {
        printf("\nPress\n1 for enqueue()\n2 for dequeue()\n3 for peek()\n4 for isempty()\n5 for isfull()\n6 for showall()\n7 for exit(): ");
        scanf("%d", &n);

        printf("\n");
        switch(n) {
            case 1:
                printf("Enter a number: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                printf("Data Removed: %d", dequeue());
                break;
            case 3:
                data = peek();
                if(data==-1)
                    printf("The Queue is Empty...");
                else 
                    printf("The Peek Of the Queue is: %d", data);
                break;
            case 4:
                printf("Is Empty: %s", isempty()?"yes":"no");
                break;
            case 5:
                printf("Is Full: %s", isfull()?"yes":"no");
                break;
            case 6:
                showall();
                break;
            default:
                exit(0);
        }
    }

    return 0;
}