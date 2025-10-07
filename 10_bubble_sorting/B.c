#include <stdio.h>

void bubble_sort(int *arr, int size) {
    int i, j, tmp;

    for(j = 0; j < size-1; j++) {
        for(i = 0; i < size-j-1; i++) {
            if(arr[i] > arr[i+1]) {
                tmp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = tmp;
            }
        }
    }
}

int main() {
    int x[] = {78, 45, 21, 19, 7, 39, 61};

    int i, size;

    size = sizeof(x) / sizeof(int); 

    bubble_sort(x, size);

    for(i=0;i<size;i++)
        printf("%d ", x[i]);    

    return 0;
}