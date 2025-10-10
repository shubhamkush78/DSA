#include <stdio.h>

int main() {
    int x[] = {34, 67, 12, 89, 41, 19, 5};

    int key, i, size = sizeof(x)/sizeof(int);

    printf("Enter a number: ");
    scanf("%d", &key);

    for(i=0; i<size; i++) {
        if(x[i] == key) {
            printf("The key: %d found...", key);
            return ;
        }
    }

    printf("The key: %d not found...", key);

    return 0;
}