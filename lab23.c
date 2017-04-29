



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include <signal.h>
#include <stdbool.h>

bool free_memory = false;

void fct(int sign)
{
    printf("123\n");;
}

void free_memory_f(int sgn)
{
    free_memory = true;
}

int main(void)
{
    Node *tree = NULL;
    signal(SIGINT, free_memory_f);
    while (1) {
        if (free_memory) {
            if (tree) {
                tree_destroy(tree);
            }
            return 0;
        }
        char what_do[24];
        scanf("%s", what_do);
        if (!strcmp(what_do, "add")) {
            int a, b;
            scanf("%d%d", &a, &b);
            node_add(tree, a, b);
        } else if (!strcmp(what_do, "root")) {
            if (tree == NULL) {
                int a;
                scanf("%d", &a);
                tree = create_tree(a);
            }
        } else if (!strcmp(what_do, "draw") || !strcmp(what_do, "print")) {
            tree_draw(tree, 0);
        } else if (!strcmp(what_do, "remove")) {
            int a;
            scanf("%d", &a);
            if (tree) {
                node_remove(tree, a);
            }
        } else if (!strcmp(what_do, "exit") || !strcmp(what_do, "close") || !strcmp(what_do, "quit")) {
            break;
        } else if (!strcmp(what_do, "result")) {
            int matr[MAX_DEEP] = {0};
            int max = 0;
            int max_ind = 0;
            tree_rec(tree, 0, matr);
            for (int i = 0; i < MAX_DEEP; ++i) {
                if (matr[i] == 0) {
                    break;
                } else if (matr[i] > max) {
                    max = matr[i];
                    max_ind = i;
                }
            }
            printf("%d\n", max_ind + 1);
        } else {
            printf("Error: Invalid query\n");
        }
    }
    tree_destroy(tree);
    return 0;
}
