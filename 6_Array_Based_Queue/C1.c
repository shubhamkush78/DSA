#include <stdio.h>

int main() {

    int x[] = {10, 20};

    printf("~%d~ ~%d~ ", x[-1], x[-2]);
    printf("\n~~~~~~~~~~~~~~~~~~~~");

    return 0;
}