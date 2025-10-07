#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node* left;
    int data;
    struct Node* right;
};

struct Node* insert(struct Node* root, int data) {
    if(root == NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->left = newNode->right = NULL;

        return newNode;
    }

    if(data < root->data) {
        root->left = insert(root->left, data);
    }

    if(data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

int main() {
    int n, data;
    struct Node *root = NULL;

    while(1) {
        printf("\nPress\n1 for insert()\n2 for traverse()\n9 for exit(): ");
        scanf("%d", &n);

        printf("\n");
        switch(n) {
            case 1:
                printf("Enter a number: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                traverse(root);
                break;
            default:
                exit(0);
        }
    }

    return 0;
}