#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define hash_size 5

typedef unsigned long hash;

typedef struct stru_node {
    struct stru_node *next;
    char *s;
} node;

node *pop(node *head);
node *push(node *head, char *);
node *destroy(node *head);
void print(node *head);
