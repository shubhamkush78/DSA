#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int *array;
    int head;
    int tail;
    int size;
};

struct Queue* create_queue(int size) {
    struct Queue *newQueue = (struct Queue*)malloc(sizeof(struct Queue));
    newQueue->array = (int*)malloc(sizeof(int)*size);    
    newQueue->head = newQueue->tail = -1;
    newQueue->size = size;

    return newQueue;
}

int isempty(struct Queue* queue) {
    if(queue == NULL)
        return;

    return queue->head == -1;
}

int isfull(struct Queue *queue) {
    if(queue == NULL)
        return;
    return queue->head == 0 && queue->tail == queue->size-1;
}

void enqueue(struct Queue *queue, int data) {
    if(queue == NULL)
        return;

    if(queue->head == -1) {
        queue->head++;
    }

    if(isfull(queue)) {
        printf("No room left in the queue...!!");
        return ;
    } else 
        queue->array[++queue->tail] = data;
}

int dequeue(struct Queue* queue) {
    if(queue == NULL)
        return;

    if(queue->head == -1) {
        printf("The Queue is empty...!");
        return -1;
    }

    if(queue->head == queue->tail) {
        int a = queue->array[queue->head];
        queue->tail = queue->head = -1;
        return a;
    }

    return queue->array[queue->head++];
}

void showall(struct Queue* queue) {
    if(queue == NULL)
        return;

    int i = 0;
    if(queue->head != -1) {
        for(i = 0; i < queue->size; i++) {
            printf("%d ", queue->array[i]);
        }
        printf("\nHead: %d and Tail: %d", queue->head, queue->tail);
    } else {
        printf("Sorry! the queue is empty...!!!");
        printf("\nHead: %d and Tail: %d", queue->head, queue->tail);
    }
}

int main() {
    int data, n, size;
    struct Queue *queue = NULL;

    while(1) {
        printf("\nPress\n0 for create_queue()\n1 for enqueue()\n2 for dequeue()\n3 for peek()\n4 for isempty()\n5 for isfull()\n6 for showall()\n7 for exit(): ");
        scanf("%d", &n);

        printf("\n");
        switch(n) {
            case 0:
                printf("Length of Queue?: ");
                scanf("%d", &size);
                queue = create_queue(size);
                break;
            case 1:
                printf("Enter a number: ");
                scanf("%d", &data);
                enqueue(queue, data);
                break;
            case 2:
                printf("Data Removed: %d", dequeue(queue));
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                showall(queue);
                break;
            default:
                exit(0);
        }
    }

    return 0;
}