#include <stdio.h>
#include <stdlib.h>

#define MAX_TABLE_SIZE 10

int hash_table[MAX_TABLE_SIZE];

int hash(int val) {
    int sum, tmp;

    while(val >= MAX_TABLE_SIZE) {
        tmp = val;
        sum = 0;
        while(tmp) {
            sum += tmp % 10;
            tmp = tmp / 10;
        }  
        val = sum;  
    }

    return val;
}

int insert(int val) {
    int index = hash(val);
    if(hash_table[index] == 0) {
        hash_table[index] = val;
        printf("\n%d - %d", index, val);
        return 1;
    }

    return 0;
}

int main() {
    int n, val, i;

    while(1) {
        printf("\n\nEnter 1 for insert\n2 for deletion\n3 for search\n4 for show\n5 for exit: ");
        scanf("%d", &n);

        switch(n) {
            case 1:
                printf("Enter a number: ");
                scanf("%d", &val);

                printf("\n\ninserted?: %s", insert(val)?"true":"false");
                break;
            case 4:
                printf("\n\n");
                for(i=0;i<MAX_TABLE_SIZE;i++) 
                    printf("%d-%d\n", i, hash_table[i]);
                break;

            case 5:
                exit(0);
        }
    }


    return 0;
}