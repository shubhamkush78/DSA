#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, n, val; 
    
    char u, v;

    printf("How many vertices you want to handle: ");
    scanf("%d", &n);

    char ar[n];
    int arr[n][n];

    for(i=0;i<n;i++) {
        fflush(stdin);
        scanf("%c", &ar[i]);
    }

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            arr[i][j] = 0;

    while(1) {
        printf("\nEnter 1 for add edge:\n 2 for show all:\n3 for delete an edge\n4 for exit: ");
        scanf("%d", &val);

        switch(val) {
            case 1:
                printf("Enter source and destination vertices: ");
                fflush(stdin);
                scanf("%c", &u);
                fflush(stdin);
                scanf("%c", &v);

                for(i=0;i<n;i++) 
                    if(ar[i] == u)
                        break; 
                for(j=0;j<n;j++) 
                    if(ar[j] == v)
                        break; 

                arr[i][j] = arr[j][i] = 1;
                break;
            case 2:
                for(i=0;i<n;i++)
                    for(j=0;j<n;j++)
                        if(arr[i][j]==1)                            
                            printf("(%c-%c), ", ar[i], ar[j]);
                break;
            case 3:
                printf("Enter source and destination vertices: ");
                fflush(stdin);
                scanf("%c", &u);
                fflush(stdin);
                scanf("%c", &v);

                for(i=0;i<n;i++) 
                    if(ar[i] == u)
                        break; 
                for(j=0;j<n;j++) 
                    if(ar[j] == v)
                        break; 

                arr[i][j] = arr[j][i] = 0;
                break;
            case 4:
                exit(0); 
        }
    }

    // for(i=0;i<n;i++) 
    //     printf("%d ", ar[i]);    
    return 0;
}
