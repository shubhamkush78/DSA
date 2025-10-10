#include <stdio.h>

int main() {
    int x[] = {34, 67, 12, 89, 41, 19, 5};

    int key, i, size = sizeof(x)/sizeof(int);
    int flag = 0;

    printf("Enter a number: ");
    scanf("%d", &key);

    for(i=0; i<size; i++) {
        if(x[i] == key) {
            flag = 1;
            break ;
        }
    }

    if(flag)        
        printf("-The key: %d found...", key);
    else    
        printf("-The key: %d not found...", key);

    return 0;
}