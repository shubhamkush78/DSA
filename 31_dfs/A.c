#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    int flag;
};

struct Node* createNode(int data) {
    struct Node* tmp = (struct Node*)malloc(sizeof(struct Node));
    
    tmp->data = data;
    tmp->next = NULL;
    tmp->flag = 0;

    return tmp;
}

int searchIndex(int data, struct Node* arr[], int n) {
    int i;

    for(i=0;i<n;i++) 
        if(arr[i]->data == data)
            return i;
    
    return -1;
}

void addToAdjList(struct Node* arr[], int target, int data) {
    struct Node* tmp = arr[target];
    
    while(tmp->next != NULL)
        tmp = tmp->next;

    tmp->next = createNode(data);
}

int main() {
    int n, i, j, data, choice, u, v;

    printf("How many vertices in your graph: ");
    scanf("%d", &n);

    struct Node* arr[n];
    int ar[n];
    int st[n];
    int top = -1;

    for(i=0;i<n;i++) {
        scanf("%d", &data);
        arr[i] = createNode(data);
    }

    while(1) {
        printf("\nPress 1 to add two adjacent nodes\n2 for dfs\n3 for exit: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter source(u) and destination(v): ");
                scanf("%d%d", &u, &v);

                i = searchIndex(u, arr, n);
                j = searchIndex(v, arr, n);

                addToAdjList(arr, i, v);
                addToAdjList(arr, j, u);

                break;
            case 2:
                break;
            case 3:
                exit(0);
        }
    }

    return 0;
}
