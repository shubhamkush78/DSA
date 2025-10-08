#include <stdio.h>

int main() {
    int x[] = {73, 98, 34, 23, 87, 9};

    int i, j, mi, size, tmp, k;

    size = sizeof(x) / sizeof(int);

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
        printf("\n------------------------\n");
        for(k=0;k<size;k++) {
            printf("%d ", x[k]);
        }
    }

    return 0;
}