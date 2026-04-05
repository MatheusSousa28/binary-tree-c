#ifndef TREE_H
#define TREE_H

typedef struct cmpnt {
    int id;
    struct cmpnt* dad;
    struct cmpnt* left;
    struct cmpnt* right;
} cmpnt;

//core
int generateTree(cmpnt** root, int first, int last, cmpnt* dad);
void printTree(cmpnt* root);

//search ops
cmpnt* minimum(cmpnt* root);
cmpnt* maximum(cmpnt* root);
cmpnt* search(cmpnt* root, int id);

//navigation
cmpnt* sucessor(cmpnt* root);
cmpnt* predecessor(cmpnt* root);

//modification
void insert(cmpnt** root, cmpnt* n);
void deleteNode(cmpnt** root, cmpnt* n);

//util
cmpnt* getdata(void);

#endif