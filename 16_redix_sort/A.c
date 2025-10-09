#include <stdio.h>

void counting_sort(int *x, int size, int place) {
    int arr[10] = {};
    int i;

    int tmp[size];

    for(i=0;i<size;i++) 
        ++arr[(x[i]/place) % 10];
    
    for(i=1;i<10;i++)
        arr[i] = arr[i] + arr[i-1];

    for(i=size-1; i>=0; i--)
        tmp[--arr[(x[i]/place)%10]] = x[i];

    for(i=0;i<size;i++)
        x[i] = tmp[i];    
}

int main() {
    int x[] = {57, 98, 122, 5, 9, 27};

    int size = sizeof(x) / sizeof(int);

    int max = x[0], i;

    for(i=1;i<size;i++)
        if(x[i] > max)
            max = x[i];

    for(i = 1; max/i > 0; i*=10) {
        counting_sort(x, size, i);
    }

    for(i=0;i<size;i++)
        printf("%d ", x[i]);

    return 0;
}