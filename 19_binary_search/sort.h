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