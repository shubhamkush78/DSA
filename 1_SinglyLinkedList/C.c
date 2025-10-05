#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {

    struct Node *head = NULL;
    struct Node *newNode;
    struct Node *tmp;

    // struct Node a;
    // a.data = 10;
    // a.next = NULL;

    // head = &a;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = 100;
    newNode->next = NULL;

    head = newNode;

    // struct Node b;
    // b.data = 20;
    // b.next = NULL;

    // a.next = &b;

    newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->data = 200;
    newNode->next = NULL;

    if(head != NULL) {
        tmp = head;
        while(tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    } else {
        head = newNode;
    }
    
    


    // struct Node c;
    // c.data = 30;
    // c.next = NULL;

    // b.next = &c;

    newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->data = 300;
    newNode->next = NULL;

    if(head != NULL) {
        tmp = head;
        while(tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    } else {
        head = newNode;
    }

    // struct Node d;
    // d.data = 40;
    // d.next = NULL;

    // c.next = &d;
    newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->data = 400;
    newNode->next = NULL;

    if(head != NULL) {
        tmp = head;
        while(tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    } else {
        head = newNode;
    }       

    tmp = head;

    while(tmp != NULL) {       
        printf("~%d\n", tmp->data);
        tmp = tmp->next;
    }

    return 0;
}