#include <stdio.h>

int main() {
    int x[] = {78, 45, 92, 21, 19, 7, 39, 61};

    int i, j, tmp, size;

    size = sizeof(x) / sizeof(int); 

    for(j = 0; j < size-1; j++) {
        for(i = 0; i < size-j-1; i++) {
            if(x[i] > x[i+1]) {
                tmp = x[i];
                x[i] = x[i+1];
                x[i+1] = tmp;
            }
        }
    }

    for(i=0;i<size;i++)
        printf("%d ", x[i]);
    

    return 0;
}