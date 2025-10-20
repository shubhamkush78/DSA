// color: 1(Red) and 0(Black)

#include <stdio.h>
#include <stdlib.h>

typedef struct N {
    struct N* ln;
    struct N* pn;
    int data;
    int color;     
    struct N* rn;     
} Node;

void balance2(Node*);
void inorder(Node*);

Node* root = NULL;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node)); 
    newNode->ln = NULL;
    newNode->rn = NULL;
    newNode->pn = NULL;
    newNode->data = data;
    newNode->color = 1; // color: 1(Red) and 0(Black)

    return newNode;
}

void balance(Node* nN) {
    Node* cN = nN->pn;
    Node* pn = cN->pn;
    if(pn != NULL && cN->color == 1) {
        if(cN == pn->ln) {
            if(pn->rn == NULL || pn->rn->color==0) {
                printf("\nb1\n");
                cN->pn = pn->pn;
                pn->ln = cN->rn; 
                cN->rn = pn;
                printf("\n-----\n");
                inorder(root);
                if(pn->pn != NULL) {
                    if(pn->pn->ln==pn)
                        pn->pn->ln = cN;
                    else 
                        pn->pn->rn = cN;
                }
                pn->pn = cN;
                if(pn->ln != NULL)
                    pn->ln->pn = pn;
                pn->color = pn->color==0?1:0;
                cN->color = cN->color==0?1:0;
                printf("\n-----\n");
                inorder(root);
            } else {
                printf("\nb2\n");
                cN->color = 0;
                pn->rn->color = 0;

                if(pn != root) {
                    pn->color = 1;
                    if(pn==pn->pn->ln)
                        balance(pn);
                    else
                        balance2(pn);
                }
            }
        } else {
            if(pn->ln==NULL || pn->ln->color == 0) {
                printf("\nb3\n");
                cN->ln->pn = pn;
                pn->rn = cN->ln;
                Node* tmp = cN->ln->rn;
                cN->ln->rn = cN;
                cN->pn = cN->ln;
                cN->ln = tmp;
                printf("\n-----\n");
                inorder(root);
                if(pn->pn != NULL) {
                    if(pn == pn->pn->rn)
                        pn->pn->rn = cN->pn;                        
                    else 
                        pn->pn->ln = cN->pn;
                }                
                cN->pn->pn = pn->pn;
                if(cN->pn->pn == NULL)
                    root = cN->pn;
                tmp = cN->pn->ln;
                cN->pn->ln = pn;
                pn->pn = cN->pn;
                pn->rn = tmp;
                pn->color = pn->color==0?1:0;
                cN->pn->color = cN->pn->color==0?1:0;
                printf("\n-----\n");
                inorder(root);
            } else {
                printf("\nb4\n");
                cN->color = 0;
                pn->ln->color = 0;

                if(pn != root) {
                    pn->color = 1;
                    if(pn==pn->pn->ln)
                        balance(pn);
                    else
                        balance2(pn);
                }
            }
        }          
    }
}

void balance2(Node* nN) {
    Node* cN = nN->pn;
    Node* pn = cN->pn;
    if(pn != NULL && cN->color == 1) {
        if(cN == pn->ln) {
            if(pn->rn == NULL || pn->rn->color==0) {
                printf("\nb5\n");
                cN->rn->pn = pn;
                pn->ln = cN->rn;
                Node* tmp = cN->rn->ln;
                cN->rn->ln = cN;
                cN->pn = cN->rn;
                cN->rn = tmp;
                printf("\n-----\n");
                inorder(root);
                if(pn->pn != NULL) {
                    if(pn == pn->pn->rn)
                        pn->pn->rn = cN->pn;                        
                    else 
                        pn->pn->ln = cN->pn;
                }
                
                cN->pn->pn = pn->pn;
                if(cN->pn->pn == NULL)
                    root = cN->pn;
                tmp = cN->pn->rn;
                cN->pn->rn = pn;
                pn->pn = cN->pn;
                pn->ln = tmp;
                // pn->ln->pn = pn;
                pn->color = pn->color==0?1:0;
                cN->pn->color = cN->pn->color==0?1:0;
                printf("\n-----\n");
                inorder(root);
            } else {
                printf("\nb6\n");
                cN->color = 0;
                pn->rn->color = 0;

                if(pn != root) {
                    pn->color = 1;
                    if(pn==pn->pn->ln)
                        balance(pn);
                    else
                        balance2(pn);
                }
            }
        } else {
            if(pn->ln==NULL || pn->ln->color == 0) {                
                printf("\nb7\n");
                cN->pn = pn->pn; 
                pn->rn = cN->ln; 
                cN->ln = pn;
                printf("\n-----\n");
                inorder(root);
                if(pn->pn != NULL) {
                    if(pn->pn->ln==pn)
                        pn->pn->ln = cN;
                    else 
                        pn->pn->rn = cN;
                }
                pn->pn = cN;
                if(pn->rn != NULL)
                    pn->rn->pn = pn;
                pn->color = pn->color==0?1:0;
                cN->color = cN->color==0?1:0;
                printf("\n-----\n");
                inorder(root);
            } else {
                printf("\nb8\n");
                cN->color = 0;
                pn->ln->color = 0;

                if(pn != root) {
                    pn->color = 1;
                    if(pn==pn->pn->ln)
                        balance(pn);
                    else
                        balance2(pn);
                }
            }
        }          
    }
}


Node* insert(Node* cN, int data) {  

    if(cN == NULL) {
        return createNode(data);
    } else if(data < cN->data) {
        if(cN->ln == NULL) {
            cN->ln = insert(cN->ln, data);
            cN->ln->pn = cN;
    
            balance(cN->ln);
        } else {
            insert(cN->ln, data);
        }
    } else if(data > cN->data) {
        if(cN->rn == NULL) {
            cN->rn = insert(cN->rn, data);
            cN->rn->pn = cN;
            
            balance2(cN->rn);
        } else {
            insert(cN->rn, data);
        }
    }

    return cN;
}

void inorder(Node* root) {
    if(root != NULL) {
        inorder(root->ln);
        printf("~%d-%c-%d~ ", root->data, root->color==0?'B':'R',root->pn!=NULL?root->pn->data:-1);
        inorder(root->rn);
    }
}

int main() {
    int inp, data;

    while(1) {
        printf("\nPress 1 for insert\n2 for search\n3 for deletion\n4 for inorder\n5 for exit: ");
        scanf("%d", &inp);

        switch(inp) {
            case 1:
                printf("Enter a number: ");
                scanf("%d", &data);

                root = insert(root, data);        
                root->color = 0;    

                printf("\n");
                inorder(root);

                break;
            case 2:
                inorder(root);
                break;
            case 5:
                exit(0);
        }
    }


    return 0;
}