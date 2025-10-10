#include <stdio.h>

void bubble_sort(int *arr, int size) {
    int i, j, tmp, flag;

    for(j = 0; j < size-1; j++) {
        flag = 1;
        for(i = 0; i < size-j-1; i++) {
            if(arr[i] > arr[i+1]) {
                tmp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = tmp;
                flag = 0;
            }
        }

        if(flag)
           break; 
    }
}

int binary_search(int *x, int size, int key) {
    int start = 0, end = size-1, mid;

    if(key >= x[0] && key <= x[size-1]) {
        while(start <= end) {
            mid = (start + end) / 2;

            if(key == x[mid])
                return mid;

            if(key < x[mid])
                end = mid - 1;
            else 
                start = mid + 1;        
        }
    }    

    return -1;
} 

int main() {
    int x[] = {89, 34, 56, 21, 45, 19, 67, 2};

    int i, key, search_index, size = sizeof(x) / sizeof(int);

    for(i=0;i<size;i++)
        printf("%d ", x[i]); 

    bubble_sort(x, size);

    printf("\n~~~~~~~~~~~~~~~~~~~\n");
    for(i=0;i<size;i++)
        printf("%d ", x[i]); 

    printf("\n\nEnter a key: ");
    scanf("%d", &key);

    search_index = binary_search(x, size, key);

    if(search_index == -1)
        printf("The given key: %d not found...", key);
    else    
        printf("The given key: %d found... at index: %d", key, search_index);


    return 0;
}