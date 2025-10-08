#include <stdio.h>

void swap(int *x, int i, int j) {
    int tmp = x[i];
    x[i] = x[j];
    x[j] = tmp;
}

int partition(int *x, int start, int end) {
    int i = start, j = end;
    int pivot = x[start], tmp;

    while(i < j) {
        while(x[++i] <= pivot);

        while(x[--j] > pivot);

        if(i < j) 
            swap(x, i, j);
    }
    
    swap(x, start, j);

    return j;
}

void quick_sort(int *x, int start, int end) {
    int n;

    if(start < end) {
        n = partition(x, start, end);
        quick_sort(x, start, n);
        quick_sort(x, n+1, end);
    }
}

int main() {
    int x[] = {34, 102, 19, 99, 62, 27, 51, 9999};
    int i;
    int size = sizeof(x) / sizeof(int);

    quick_sort(x, 0, size-1);

    for(i = 0; i< size-1; i++)
        printf("%d ", x[i]); 

    return 0;
}