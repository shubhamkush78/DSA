#include <stdio.h>

void linear_search(int *x, int size, int key) {
    int i, flag = 0;

    for(i=0; i<size; i++) {
        if(x[i] == key) {
            flag = 1;
            break ;
        }
    }
            
    printf("#The key: %d %sfound...", key, flag?"":"not ");
}

int main() {
    int x[] = {34, 67, 12, 89, 41, 19, 5};

    int key, size = sizeof(x)/sizeof(int);

    printf("Enter a number: ");
    scanf("%d", &key);

    linear_search(x, size, key);

    return 0;
}