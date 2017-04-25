#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

int main(void)
{
    Node *tree = create_tree(1);
    while (1) {
        char what_do[24];
        scanf("%s", what_do);
        if (strcmp(what_do, "add") == 0) {
            int a, b;
            scanf("%d%d", &a, &b);
            node_add(tree, a, b);
        } else if (strcmp(what_do, "draw") == 0) {
            tree_draw(tree, 0);
        } else if (strcmp(what_do, "remove") == 0) {
            int a;
            scanf("%d", &a);
            node_remove(tree, a);
        } else if (strcmp(what_do, "exit") == 0 || strcmp(what_do, "close") == 0) {
            tree_destroy(tree);
            break;
        } else if (strcmp(what_do, "result") == 0) {
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
            exit(1);
        }
    }

    return 0;
}