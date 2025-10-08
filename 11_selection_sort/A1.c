#include <stdio.h>

void selection_sort(int x[], int size) {
    int i, j, mi, tmp, k;    

    for(i = 0; i < size-1; i++) {
        mi = i;

        for(j = i+1; j < size; j++) {
            if(x[j] < x[mi]) {
                mi = j;
            }
        }

        tmp = x[i];
        x[i] = x[mi];
        x[mi] = tmp;
    }
}

int main() {
    int x[] = {73, 98, 34, 23, 87, 9};

    int k, size;

    size = sizeof(x) / sizeof(int);

    selection_sort(x, size);

    for(k=0;k<size;k++) {
        printf("%d ", x[k]);
    }

    return 0;
}