#include <stdio.h>

int x[] = {34, 1, 19, 82, 62, 27, 51, 9999};

void swap(int i, int j) {
    int tmp = x[i];
    x[i] = x[j];
    x[j] = tmp;
}

int partition(int start, int end) {
    int i = start, j = end;
    int pivot = x[start], tmp;

    while(i < j) {
        while(x[++i] <= pivot);

        while(x[--j] > pivot);

        if(i < j) 
            swap(i, j);
    }
    
    swap(start, j);

    return j;
}

void quick_sort(int start, int end) {
    int n;

    if(start < end) {
        n = partition(start, end);
        quick_sort(start, n);
        quick_sort(n+1, end);
    }
}

int main() {
    int i;
    int size = sizeof(x) / sizeof(int);

    quick_sort(0, size-1);

    for(i = 0; i< size-1; i++)
        printf("%d ", x[i]); 

    return 0;
}