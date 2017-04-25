#ifndef _TREE_H_
#define _TREE_H_
#include <stdio.h>
#include <stdlib.h>

#define MAX_DEEP 200

typedef struct Tnode {
    int index;
    // int value;
    struct Tnode *son;
    struct Tnode *brother;
}Node;

Node *create_tree(int v);
Node *node_find(Node *tree, int index);
void node_add(Node *tree, int parent, int index);
void tree_draw(Node *tree, int num);
void tree_destroy(Node *tree);
void node_remove(Node *tree, int index);
void tree_rec(Node *tree, int num, int *matr);

#endif