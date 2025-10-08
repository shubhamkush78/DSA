#include <stdio.h>

int x[] = {92,34,45,8,22,15};
int size = sizeof(x)/sizeof(int);

void insertion_sort() {
    int i, j, t;

    for(i = 1; i < size; i++) {
        t = x[i];

        for(j = i-1; j >= 0; j--) {
            if(x[j] > t) 
                x[j+1] = x[j];
            else
                break;
        }

        x[++j] = t;
    }
}

int main() {   

    int i;

    insertion_sort();    

    for(i=0;i<size;i++) 
        printf("%d ", x[i]);

    return 0;
}