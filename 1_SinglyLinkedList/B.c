#include <stdio.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {

    struct Node *head = NULL;

    struct Node a;
    a.data = 10;
    a.next = NULL;

    head = &a;

    struct Node b;
    b.data = 20;
    b.next = NULL;

    a.next = &b;

    struct Node c;
    c.data = 30;
    c.next = NULL;

    b.next = &c;

    struct Node d;
    d.data = 40;
    d.next = NULL;

    c.next = &d;       

    struct Node *tmp = head;

    if(tmp != NULL) {
        do {
            printf("~%d\n", tmp->data);
            tmp = tmp->next;  
        } while(tmp != NULL);
    }
    // tmp = tmp->next;    
    // printf("%d\n", tmp->data);
    
    // tmp = tmp->next;    
    // printf("%d\n", tmp->data);
    
    // tmp = tmp->next;    
    // printf("%d\n", tmp->data);
    
    // tmp = tmp->next;    
    // printf("%d\n", tmp->data);

    return 0;
}