#include <stdio.h>
#include <stdlib.h>

#define M 10

struct Node {
    int data;
    struct Node* next;
};

struct Node* ht[M]; 

int hash(int val) {
    int sum, tmp;

    while(val >= M) {
        tmp = val;
        sum = 0;
        while(tmp) {
            sum += tmp % 10;
            tmp = tmp / 10;
        }  
        val = sum;  
    }

    return val;
}

struct Node* createNode(int val) {
    struct Node* nN = (struct Node*)malloc(sizeof(struct Node));
    nN->data = val;

    return nN;
}

void insert(int val) {
    int hcode = hash(val);

    struct Node* nN = createNode(val);

    nN->next = ht[hcode];
    ht[hcode] = nN;
}

int main() {
    int n, data;

    while(1) {
        printf("Press 1 for insertion\n2 for search\n3 for delete\n4 for exit: ");
        scanf("%d", &n);

        switch(n) {
            case 1:
                print("\nEnter a number: ");
                scanf("%d", &data);

                insert(data);
                break;
        }
    }


    return 0;
}

