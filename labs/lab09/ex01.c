#include <stdio.h>
#include <stdlib.h>

typedef struct stru_node {
    struct stru_node *next;
    int v;
} node;


node *pop(node *head);
node *push(node *head, int e);
node *destroy(node *head);
void print(node *head);

int main(){
    int c;
    node (*head) = NULL, (*p);
    p = head;
    while ((c = getchar())!='0'){
        p = push(p, c);
    }
    return 0;
}

node *push(node *head, int e){
    node (*p) = malloc(sizeof(node));
    (*head).next = p;
    (*p).v = e;
    (*p).next = NULL;
    return p;
}

void print(node *head){
    printf("%d\n", (*head).v);
    if ((*((*head).next)).next != NULL)
        print((*head).next);
}

node *pop(node *head){
    node (*p);
    
    free(p);
    return NULL
}