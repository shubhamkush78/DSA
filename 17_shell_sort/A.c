#include <stdio.h>

int main() {

    // int x[] = {59, 34, 23, 61, 7, 42, 19};
    int x[] = {15, 34, 23, 2, 61, 7, 19};

    int size = sizeof(x) / sizeof(int);

    int i, j, gap, t;

    for(gap = size/2; gap > 0; gap /= 2) {
        i = 0; j = gap;

        while(j < size) {
            if(x[i] > x[j]) {
                t = x[i];
                x[i] = x[j];
                x[j] = t;

                if(i-gap >= 0 && x[i-gap] > x[i]) {
                    t = x[i-gap];
                    x[i-gap] = x[i];
                    x[i] = t;
                }
            }

            i++; j++;
        }
    }  

    for(i=0;i<size;i++) 
        printf("%d ", x[i]);

    return 0;
}