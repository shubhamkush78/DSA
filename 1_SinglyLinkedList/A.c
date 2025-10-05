#include <stdio.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {

    struct Node *head;

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

    printf("%d\n", a.data);    
    printf("%d\n", b.data);    
    printf("%d\n", c.data);    
    printf("%d\n", d.data);    

    return 0;
}