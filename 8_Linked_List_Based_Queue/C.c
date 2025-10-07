#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node *head;
    struct Node *tail;
};

struct Queue* create_queue() {
    struct Queue* newQueue = (struct Queue*)malloc(sizeof(struct Queue));
    newQueue->head = newQueue->tail = NULL;

    return newQueue;
}

int isempty(struct Queue* queue) {
    return queue->head == NULL;
}

int peek(struct Queue* queue) {
    if(queue->head == NULL)
       return -1;

    return queue->head->data; 
}

void enqueue(struct Queue* queue, int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if(queue->head == NULL) {
        queue->head = queue->tail = newNode;
        return ;
    }
    
    queue->tail->next = newNode;
    queue->tail = newNode;
}

int dequeue(struct Queue* queue) {
    int data = -1;
    struct Node* tmp;

    if(queue->head != NULL) {
        data = queue->head->data;
        tmp = queue->head;
        queue->head = queue->head->next;
        if(queue->head == NULL)
            queue->tail = NULL;
        free(tmp);
        return data;
    }

    return data;
}

void showall(struct Queue* queue) {
    struct Node *tmp = queue->head;

    while(tmp != NULL) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
}

int main() {   

    int data, n;
    struct Queue *queue = NULL;

    while(1) {
        printf("\nPress\n0 for create_queue()\n1 for enqueue()\n2 for dequeue()\n3 for peek()\n4 for isempty()\n5 for showall()\n6 for exit(): ");
        scanf("%d", &n);

        printf("\n");
        switch(n) {
            case 0:
                queue = create_queue();
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
                data = peek(queue);
                if(data == -1)
                    printf("Queue is empty");
                else
                    printf("Head: %d", data);
                break;
            case 4:
                printf("Is Empty? %s", isempty(queue)?"yes":"no");
                break;
            case 5:
                showall(queue);
                break;
            default: 
                exit(0);
        }
    }

    return 0;
}