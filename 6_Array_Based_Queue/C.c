#include <stdio.h>

struct Node {
    int x;
};

int main() {

    struct Node *node = NULL;

    printf("~%d~ ", node->x);
    printf("\n~~~~~~~~~~~~~~~~~~~~");

    return 0;
}