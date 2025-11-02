#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* tmp = (struct Node*)malloc(sizeof(struct Node));
    tmp->data = data;
    tmp->next = NULL;

    return tmp;
}

int searchIndex(char data, struct Node* arr[], int n) {
    int i;

    for(i=0;i<n;i++) 
        if(arr[i]->data == data)
            break;
    
    return i;
}

void showAll() {

}

int main() {
    int i, j, n, val;
    char data, u, v;
    struct Node* tmp = NULL;

    printf("How many vertices in your graph: ");
    scanf("%d", &n);

    struct Node* arr[n];
    
    for(i=0;i<n;i++) {
        fflush(stdin);
        scanf("%c", &data);
        arr[i] = createNode(data);
    }

    while(1) {
        printf("Press 1 for New Edge\n2 for Show All Vertices\n3 for exit: ");
        scanf("%d", &val);

        switch(val) {
            case 1:
                printf("\nEnter both source and destination nodes: ");
                fflush(stdin);
                scanf("%c", &u);
                fflush(stdin);
                scanf("%c", &v);
                
                i = searchIndex(u, arr, n);
                j = searchIndex(v, arr, n);

                tmp = arr[i];
                while(1) {
                    if(tmp->next == NULL) {
                        tmp->next = createNode(v);    
                        break;
                    } 

                    tmp = tmp->next;
                }                   
                
                tmp = arr[j];  
                while(1) {
                    if(tmp->next == NULL) {
                        tmp->next = createNode(u);    
                        break;
                    } 

                    tmp = tmp->next;
                }                   

                break;
            case 2:                
                for(i=0;i<n;i++) {
                    tmp = arr[i];
                    while(1) {
                        if(tmp->next == NULL)
                            break;
                        
                        tmp = tmp->next;

                        printf("(%c-%c), ", arr[i]->data, tmp->data);
                    }
                }

                break;
            case 3:
                exit(0);
        }
    }

    return 0;
}
