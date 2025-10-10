#include <stdio.h>

int linear_search(int *x, int size, int key) {
    int i;

    for(i=0; i<size; i++) {
        if(x[i] == key) 
            return i;
    }
            
    return -1;
}

int main() {
    int x[] = {34, 67, 12, 89, 41, 19, 5};

    int key, size = sizeof(x)/sizeof(int), search_index;

    printf("Enter a number: ");
    scanf("%d", &key);

    search_index = linear_search(x, size, key);

    if(search_index == -1)
        printf("The key: %d not found...", key);
    else
        printf("The key: %d found at index %d...", key, search_index);

    return 0;
}