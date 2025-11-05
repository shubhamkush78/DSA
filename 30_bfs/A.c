#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* tmp = (struct Node*)malloc(sizeof(struct Node));
    tmp->data = data;
    tmp->next = NULL;

    return tmp;
}

int searchIndex(int data, struct Node* arr[], int n) {
    int i;

    for(i=0;i<n;i++) 
        if(arr[i]->data == data)
            break;
    
    return i;
}

void showAll() {

}

int main() {
    int i, j, n, val, data;
    int u, v, flag;
    struct Node* tmp = NULL;

    printf("How many vertices in your graph: ");
    scanf("%d", &n);

    struct Node* arr[n];
    
    int queue[n];
    int head = -1, tail = -1;
    
    for(i=0;i<n;i++) {
        // fflush(stdin);
        scanf("%d", &data);
        arr[i] = createNode(data);
    }

    while(1) {
        printf("Press 1 for New Edge\n2 for Show All Vertices\n3 for BFS\n4 for exit: ");
        scanf("%d", &val);

        switch(val) {
            case 1:
                printf("\nEnter both source and destination nodes: ");
                // fflush(stdin);
                scanf("%d", &u);
                // fflush(stdin);
                scanf("%d", &v);
                
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

                        printf("(%d-%d), ", arr[i]->data, tmp->data);
                    }
                }

                break;
            case 3:
                printf("Enter start vertex: ");
                scanf("%d", &data);

                while(1 && tail != n-1) {
                    if(head == -1) {
                        head = tail = 0;
                        queue[tail] = data;
                        printf("%d-", data);
                    } else {
                        data = queue[head++];

                        for(i=0;i<n;i++) {
                            if(arr[i]->data == data) {
                                tmp = arr[i];
                                while(tmp->next != NULL) {
                                    flag = 0;
                                    for(j=0;j<=tail;j++) {
                                        if(queue[j] == tmp->next->data) {
                                            flag = 1;
                                            break;
                                        }
                                    }
                                    if(flag == 0) {
                                        queue[++tail] = tmp->next->data; 
                                        printf("%d-", queue[tail]);
                                    }
                                    tmp = tmp->next;
                                }

                                break;
                            }
                        }
                    }  
                }
                
                break;
            case 4:
                exit(0);
        }
    }

    return 0;
}
