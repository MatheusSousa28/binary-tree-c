#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

//vetor base para árvore balanceada inicial
static int vtr[] = {101, 152, 230, 285, 340, 451, 512};
static char buffer[30];

int generateTree(cmpnt** root, int first, int last, cmpnt* dad){
    if(first > last) return 0;

    *root = malloc(sizeof(**root));
    if(*root == NULL){
        printf("erro ao alocar memória\n");
        return -1;
    }

    int mid = (first + last) / 2;

    (*root)->id = vtr[mid];
    (*root)->dad = dad;
    (*root)->left = NULL;
    (*root)->right = NULL;

    if(generateTree(&(*root)->left, first, mid - 1, *root) == -1 ||
       generateTree(&(*root)->right, mid + 1, last, *root) == -1){
        free(*root);
        return -1;
    }

    return 0;
}

void printTree(cmpnt* root){
    if(!root) return;
    printTree(root->left);
    printf("%d ", root->id);
    printTree(root->right);
}

cmpnt* minimum(cmpnt* root){
    while(root && root->left)
        root = root->left;
    return root;
}

cmpnt* maximum(cmpnt* root){
    while(root && root->right)
        root = root->right;
    return root;
}

cmpnt* search(cmpnt* root, int id){
    if(!root || root->id == id)
        return root;

    if(id < root->id)
        return search(root->left, id);

    return search(root->right, id);
}

cmpnt* sucessor(cmpnt* root){
    if(root->right)
        return minimum(root->right);

    cmpnt* y = root->dad;

    while(y && root == y->right){
        root = y;
        y = y->dad;
    }

    return y;
}

cmpnt* predecessor(cmpnt* root){
    if(root->left)
        return maximum(root->left);

    cmpnt* y = root->dad;

    while(y && root == y->left){
        root = y;
        y = y->dad;
    }

    return y;
}

void insert(cmpnt** root, cmpnt* n){
    if(*root == NULL){
        *root = n;
        return;
    }

    cmpnt* y = NULL;
    cmpnt* x = *root;

    while(x){
        y = x;
        if(n->id < x->id)
            x = x->left;
        else
            x = x->right;
    }

    n->dad = y;

    if(n->id < y->id)
        y->left = n;
    else
        y->right = n;
}

cmpnt* getdata(void){
    cmpnt* new = malloc(sizeof(cmpnt));
    if(!new){
        printf("erro ao alocar memória\n");
        return NULL;
    }

    printf("digite o id: ");
    fgets(buffer, 30, stdin);

    new->id = atoi(buffer);
    new->dad = NULL;
    new->left = NULL;
    new->right = NULL;

    return new;
}

static void transplant(cmpnt** root, cmpnt* u, cmpnt* z){
    if(u->dad == NULL)
        *root = z;
    else if(u == u->dad->left)
        u->dad->left = z;
    else
        u->dad->right = z;

    if(z)
        z->dad = u->dad;
}

void deleteNode(cmpnt** root, cmpnt* n){
    if(n->left == NULL){
        transplant(root, n, n->right);
    }
    else if(n->right == NULL){
        transplant(root, n, n->left);
    }
    else{
        cmpnt* suce = minimum(n->right);

        if(suce != n->right){
            transplant(root, suce, suce->right);
            suce->right = n->right;
            suce->right->dad = suce;
        }

        transplant(root, n, suce);
        suce->left = n->left;
        suce->left->dad = suce;
    }

    free(n);
}