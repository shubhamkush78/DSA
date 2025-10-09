#include <stdio.h>

void swap(int *x, int i, int j) {
    int t;
    
    t = x[i];
    x[i] = x[j];
    x[j] = t;
}

void shell_sort(int *x, int size) {
    int i, j, gap, t;

    for(gap = size/2; gap > 0; gap /= 2) {
        i = 0; j = gap;

        while(j < size) {
            if(x[i] > x[j]) {
                // t = x[i];
                // x[i] = x[j];
                // x[j] = t;
                swap(x, i, j);

                if(i-gap >= 0 && x[i-gap] > x[i]) {
                    // t = x[i-gap];
                    // x[i-gap] = x[i];
                    // x[i] = t;
                    swap(x, i-gap, i);
                }
            }

            i++; j++;
        }
    }
}

int main() {

    int x[] = {15, 34, 23, 2, 61, 7, 19};

    int i, size = sizeof(x) / sizeof(int);

    shell_sort(x, size);  

    for(i=0;i<size;i++) 
        printf("%d ", x[i]);

    return 0;
}