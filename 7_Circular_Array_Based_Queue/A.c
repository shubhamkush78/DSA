#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int array[MAX_SIZE];
int head = -1;
int tail = -1;

int isempty() {
    return head == -1;
}

int isfull() {
    return (head==0 && tail==MAX_SIZE-1) || (tail==head-1);
}

void enqueue(int data) {
    if(head == -1) {
        head = tail = 0;
        array[tail] = data; 
        return ;
    }

    if(tail == MAX_SIZE-1 && head != 0) {
        tail = 0;
        array[tail] = data;
        return ;
    }

    if(tail >= head && tail < MAX_SIZE-1) {
        array[++tail] = data;
        return ;
    }
    
    if(tail < head - 1) {
        array[++tail] = data;
        return ;
    }
}

int dequeue() {
    int data = -1;

    if(head == tail) {
        data = array[head];
        head = tail = -1;
        return data;
    }    

    if(head < MAX_SIZE-1) {
        data = array[head++];
        return data;
    }   

    if(head == MAX_SIZE-1 && tail < head) {
        data = array[head];
        head = 0;
        return data;
    }
}

void showall() {
    int i;

    for(i=0;i<MAX_SIZE;i++) {
        printf("%d ", array[i]);
    }
    printf("\nhead: %d and tail: %d", head, tail);
}

int main() {

    int n, data;

    while(1) {
        printf("\nPress\n1 for enqueue()\n2 for dequeue()\n3 for showall()\n4 for isempty()\n5 for isfull()\n6 for exit(): ");
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
                showall();
                break;
            case 4:
                printf("Is Empty: %s", isempty()?"yes":"no");
                break;
            case 5:
                printf("Is Full: %s", isfull()?"yes":"no");
                break;
            default:
                exit(0);
        }
    }

    return 0;
}
