#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

char buffer[30];

int main(){
    cmpnt* root = NULL;

    if(generateTree(&root, 0, 6, NULL) == -1){
        printf("erro ao gerar arvore\n");
        return 1;
    }

    int op = -1;

    while(op != 0){
        printf("\n1 imprimir\n2 minimo\n3 maximo\n4 buscar\n5 sucessor/predecessor\n6 inserir\n7 remover\n0 sair\n");

        fgets(buffer, 30, stdin);
        op = atoi(buffer);

        if(op == 1){
            printTree(root);
        }
        else if(op == 2){
            printf("%d\n", minimum(root)->id);
        }
        else if(op == 3){
            printf("%d\n", maximum(root)->id);
        }
        else if(op == 4){
            printf("id: ");
            fgets(buffer, 30, stdin);
            int id = atoi(buffer);

            cmpnt* n = search(root, id);

            if(n) printf("encontrado: %d\n", n->id);
            else printf("nao existe\n");
        }
        else if(op == 5){
            printf("id: ");
            fgets(buffer, 30, stdin);
            int id = atoi(buffer);

            cmpnt* n = search(root, id);

            if(!n){
                printf("nao existe\n");
                continue;
            }

            printf("1 sucessor 2 predecessor\n");
            fgets(buffer, 30, stdin);
            int t = atoi(buffer);

            if(t == 1){
                cmpnt* s = sucessor(n);
                printf("%d\n", s ? s->id : -1);
            } else {
                cmpnt* p = predecessor(n);
                printf("%d\n", p ? p->id : -1);
            }
        }
        else if(op == 6){
            cmpnt* n = getdata();
            insert(&root, n);
        }
        else if(op == 7){
            printf("id: ");
            fgets(buffer, 30, stdin);
            int id = atoi(buffer);

            cmpnt* n = search(root, id);
            if(n) deleteNode(&root, n);
        }
    }

    return 0;
}