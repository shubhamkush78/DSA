#include <stdio.h>

int x[] = {64, 23, 71, 42, 19, 33, 9};

void merge(int start, int mid, int end) {
    int i, j, k;

    int l1 = mid - start + 1;
    int l2 = end - mid;

    int larr[l1];
    int rarr[l2];

    for(i=0;i<l1;i++)
        larr[i] = x[start+i];

    for(j=0;j<l2;j++)
        rarr[j] = x[mid+1+j];

    i = j = 0;
    k = start;

    while(i < l1 && j < l2) {
        if(larr[i] <= rarr[j])
            x[k++] = larr[i++];
        else
            x[k++] = rarr[j++];
    }

    while(i < l1)
        x[k++] = larr[i++];
    
    while(j < l2)
        x[k++] = rarr[j++];
}

void msort(int start, int end) {
    int mid;

    if(start < end) {
        mid = (start + end) / 2;

        msort(start, mid);
        msort(mid+1, end);

        merge(start, mid, end);
    }
}

int main() {

    int i, size = sizeof(x)/sizeof(int);

    msort(0, size-1);

    for(i=0;i<size;i++)
        printf("%d ", x[i]);

    return 0;
}