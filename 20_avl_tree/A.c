#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node* left;
    int data;
    struct Node* right;
    int height;
};

struct Node* create_node(int data) {
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->left = NULL;
    node->right = NULL;
    node->data = data;
    node->height = 0;

    return node;
}

int larger(int a, int b) {
    return a > b ? a : b;
}

int get_height(struct Node *root) {
    if(root == NULL)
        return 0;

    return root->height+1;
}

// int calc_balance_factor(struct Node *root) {
//     return get_height(root->left) - get_height(root->right);
// }

struct Node* left_rotate(struct Node *root) {
    struct Node *a = root->right;
    struct Node *t = a->left;

    a->left = root;
    root->right = t;

    root->height = larger(get_height(root->left), get_height(root->right));
    a->height = larger(get_height(a->left), get_height(a->right));

    return a;
}

struct Node* right_rotate(struct Node* root) {
    struct Node *a = root->left;
    struct Node *t = a->right;

    a->right = root;
    root->left = t;

    root->height = larger(get_height(root->left), get_height(root->right));
    a->height = larger(get_height(a->left), get_height(a->right));

    return a;
}

struct Node* insert_node(struct Node *root, int data) {
    
    if(root == NULL)        
        return create_node(data);
    
    if(data < root->data) {
        root->left = insert_node(root->left, data);
    } else if(data > root->data) {
        root->right = insert_node(root->right, data);
    } 

    root->height = larger(get_height(root->left), get_height(root->right));

    int balance_factor =  get_height(root->left) - get_height(root->right);

    if(balance_factor == -2) {
        if(data > root->right->data) {
            //RR
            return left_rotate(root);
        } else {
            //RL
            root->right = right_rotate(root->right);
            return left_rotate(root);
        }
    }

    if(balance_factor == 2) {
        if(data < root->left->data) {
            //LL
            return right_rotate(root);
        } else {
            //LR
            root->left = left_rotate(root->left);
            return right_rotate(root);
        }
    }

    return root;
}

void inorder(struct Node *root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d-%d ", root->data, root->height);
        inorder(root->right);
    }
}

int main() {
    struct Node *root = NULL;
    int flag = 1, input, data;

    while(flag) {
        printf("\n\nEnter 1 for insertion\n2 for showall\n3 for exit: ");
        scanf("%d", &input);

        printf("\n");
        if(input == 1) {
            printf("Enter a number: ");
            scanf("%d", &data);
            root = insert_node(root, data);
        } else if(input == 2) {
            inorder(root);
        } else if(input >= 3) {
            flag = 0;
        }
    }

    return 0;
}