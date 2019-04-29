#include "ex03aux.h"

node *push(node *head, char *s){
    node (*p) = malloc(sizeof(node));
    char *k = malloc(sizeof(char)*(strlen(s)+1));
    strcpy(k,s);
    p->s = k;
    p->next = head;                         /*endereço anterior*/
    return p;
}

void print(node *head){
    printf("%s",head->s);
    if (head->next != NULL)
        print(head->next);
    pop(head);
}

node *pop(node *head){
    node *p;
    p = head->next;
    free(head);
    return p;
}

node *destroy(node *head){
    node *aux;
    aux = head->next;
    free(head);
    if(aux != NULL)
        destroy(aux);
    return aux;
}
