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

void inorder(struct Node *root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node* root) {
    if(root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {
    if(root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}


int main() {
    int n, data;
    struct Node *root = NULL;

    while(1) {
        printf("\nPress\n1 for insert()\n2 for inorder()\n3 for preorder()\n4 for postorder()\n9 for exit(): ");
        scanf("%d", &n);

        printf("\n");
        switch(n) {
            case 1:
                printf("Enter a number: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                inorder(root);
                break;
            case 3:
                preorder(root);
                break;
            case 4:
                postorder(root);
                break;
            default:
                exit(0);
        }
    }

    return 0;
}