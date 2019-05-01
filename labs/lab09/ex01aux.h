#include <stdio.h>
#include <stdlib.h>

int debug;

typedef struct stru_node {
    struct stru_node *next;
    int v;
} node;

node *pop(node *head);
node *push(node *head, int e);
node *destroy(node *head);
void print(node *head);
