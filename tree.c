#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

Node *create_tree(int v)
{
    Node *Tree = (Node *)malloc(sizeof(Node));
    Tree->index = v;
    Tree->son = NULL;
    Tree->brother = NULL;
    return Tree;
}


Node *node_find(Node *tree, int index)
{
    Node *tr = NULL;
    if (tree->index == index) {
        return tree;
    }
    if (tree->son) {
        tr = node_find(tree->son, index);
        if(tr != NULL) {
            return tr;
        }
    }
    if (tree->brother) {
        tr = node_find(tree->brother, index);
        if(tr != NULL) {
            return tr;
        }
    }
    return NULL;
}

void node_add(Node *tree, int parent, int index)
{
    if (tree) {
        Node *parent_node = node_find(tree, parent);
        if (parent_node) {
            if (parent_node->son == NULL) {
                parent_node->son = create_tree(index);
            } else {
                Node *brother = parent_node->son;
                while (brother->brother) {
                    brother = brother->brother;
                }
                brother->brother = create_tree(index);
            }
        } else {
            printf("Error: you can't add node\n");
        }
    }
}


void tree_destroy(Node *tree)
{
    if (tree->son) {
        tree_destroy(tree->son);
    }
    if (tree->brother) {
        tree_destroy(tree->brother);
    }
    free(tree);
    tree = NULL;
}

void node_remove(Node *tree, int index)
{
    if (tree->son) {
        if (tree->son->index == index) {
            Node *tr = tree->son;
            tree->son = tree->son->brother;
            if (tr->son) {
                tree_destroy(tr->son);
            }
            free(tr);
            tr = NULL;
            return;
        } else {
            node_remove(tree->son, index);
        }
    }
    if (tree->brother) {
        if (tree->brother->index == index) {
            Node *tr = tree->brother;
            tree->brother = tree->brother->brother;
            if (tr->son) {
                tree_destroy(tr->son);
            }
            free(tr);
            tr = NULL;
            return;
        } else {
            node_remove(tree->brother, index);
        }
    }
}

void tree_draw(Node *tree, int num)
{
    if (tree) {
        for (int i = 0; i < num; i++) {
            printf("\t");
        }
        printf("%d\n", tree->index);
        if (tree->son) {
            tree_draw(tree->son, num + 1);
        }
        if (tree->brother) {
            tree_draw(tree->brother, num);
        }
    }
}

void tree_rec(Node *tree, int num, int *matr)
{
    matr[num] += 1;
    if (tree->son) {
        tree_rec(tree->son, num + 1, matr);
    }
    if (tree->brother) {
        tree_rec(tree->brother, num, matr);
    }
}