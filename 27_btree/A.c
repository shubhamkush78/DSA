#include <stdio.h>
#include <stdlib.h>

#define M 4

struct BTNode {
    int keys[M];
    struct BTNode* children[M];
    int count;
    struct BTNode* pN;
};

struct BTNode *root;

void findAndPlace(struct BTNode*, int, int);

struct BTNode* createNode(int key) {
    int i;
    
    struct BTNode* nN = (struct BTNode*)calloc(1, sizeof(struct BTNode));
    
    nN->keys[0] = key;
    nN->count = 1;
    nN->pN = NULL;

    return nN;
}

void split(struct BTNode* cN) {
    int mid,k,j;
    struct BTNode* nN = NULL;

    mid = M/2;
    cN->count = mid;
    nN = createNode(cN->keys[mid+1]);
    k=1;
    for(j=mid+2;j<M;j++) {
        nN->keys[k++] = cN->keys[j];
    }
    nN->count = M-mid-1;

    if(cN == root) {
        root = createNode(cN->keys[mid]);
        root->children[0] = cN;
        root->children[1] = nN;
        cN->pN = root;
        nN->pN = root;
    } else {
        findAndPlace(cN->pN, cN->keys[mid], 0);
    }
}

void findAndPlace(struct BTNode* cN, int key, int isnew) {
    int i, j, flag = 0;
    struct BTNode* tmp = NULL;

    for(i=0;i<cN->count;i++) {
        if(key < cN->keys[i]) {
            if(cN->children[0] == NULL || !isnew) {
                for(j=cN->count-1;j>=i;j--) {
                    cN->keys[j+1] = cN->keys[j];
                }
                cN->keys[i] = key;
                cN->count++;
                if(cN->count == M) {
                    split(cN);
                }                
            } else {
                tmp = cN->children[i];
                findAndPlace(tmp, key, 1);                    
            }

            flag = 1;
            break;
        }            
    }

    if(flag == 0) {
        if(cN->children[0] == NULL || !isnew) {
            cN->keys[i] = key;
            cN->count++;
            if(cN->count==M) {
                split(cN);
            }
        } else {
            findAndPlace(cN->children[i], key, 1);
        }
    }
}


void insert(struct BTNode *cN, int key) {   
    int i,j,mid,k,flag=0;
    struct BTNode* nN = NULL;

    if(cN == NULL) {
        root = createNode(key);
    } else {        
        findAndPlace(cN, key, 1);
    }
}

int main() {
    int key, x;

    while(1) {
        printf("1 for Insert\n2 for iterate\n3 for search\n4 for delete\n5 for exit: ");
        scanf("%d", &x);

        switch(x) {
            case 1:
                printf("Enter a value: ");
                scanf("%d", &key);

                insert(root, key);
        }
    }

    return 0;
}
