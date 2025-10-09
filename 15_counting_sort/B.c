#include <stdio.h>

int get_max(int *x, int size) {
    int i, max = x[0];

    for(i=1;i<size;i++)
        if(x[i] > max)
            max = x[i];

    return max;
}

int main() {
    int x[] = {5,3,7,9,1,4,2,5,8,7,3,4,1,2,9,8,5};

    int size = sizeof(x)/sizeof(int);
    
    int i, max = get_max(x, size);

    // for(i=1;i<size;i++)
    //     if(x[i] > max)
    //         max = x[i];

    int arr[max+1];

    for(i=0;i<max+1;i++)
        arr[i] = 0;

    for(i=0;i<size;i++)
        ++arr[x[i]];

    
    for(i=1;i<max+1;i++)
        arr[i] = arr[i] + arr[i-1];

    
    int y[size];

    for(i=size-1;i>=0;i--)
        y[--arr[x[i]]] = x[i];

    for(i=0;i<size;i++)
        x[i] = y[i];

    for(i=0;i<size;i++)
        printf("%d ", x[i]);
        
    return 0;
}