#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

int isempty() {
    return head == NULL;
}

int peek() {
    if(head == NULL)
       return -1;

    return head->data; 
}

void enqueue(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if(head == NULL) {
        head = tail = newNode;
        return ;
    }
    
    tail->next = newNode;
    tail = newNode;
}

int dequeue() {
    int data = -1;
    struct Node* tmp;

    if(head != NULL) {
        data = head->data;
        tmp = head;
        head = head->next;
        if(head == NULL)
            tail = NULL;
        free(tmp);
        return data;
    }

    return data;
}

void showall() {
    struct Node *tmp = head;

    while(tmp != NULL) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
}

int main() {   

    int data, n;

    while(1) {
        printf("\nPress\n1 for enqueue()\n2 for dequeue()\n3 for peek()\n4 for isempty()\n5 for showall()\n6 for exit(): ");
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
                if(data == -1)
                    printf("Queue is empty");
                else
                    printf("Head: %d", data);
                break;
            case 4:
                printf("Is Empty? %s", isempty()?"yes":"no");
                break;
            case 5:
                showall();
                break;
            default: 
                exit(0);
        }
    }

    return 0;
}