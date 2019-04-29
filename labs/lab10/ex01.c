#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1024

typedef struct stru_node{
    struct stru_node *next;
    char *s;
} node;

node *pop(node *head);
node *push(node *head, const char *);
node *destroy(node *head);
void print(node *head);

int main(){
    node *head = NULL;
    char buffer[MAX] = "";
    scanf("%s", buffer);
    while(strcmp("x",buffer)){
        head = push(head, buffer);
        scanf("%s", buffer);
    }
    return 0;
}


node *push(node *head, const char *s){
    if(head == NULL){                                   /*/recebe um ponteiro nulo significa q está no fim da lista/*/
        node(*p) = malloc(sizeof(node));
        char *k = malloc(sizeof(char) * (strlen(s) + 1));
        strcpy(k, s);
        p->s = k;
        p->next = NULL;
        return p;
    }
    if(head->next == NULL){                             /*/se o seguinte é nulo está no ultimo elemento existente da lista/*/
        head->next = push(head->next,s);                /*/grava o elemento acabado de criar/*/
        return NULL;
    }
    return push(head->next, s);                         /*/está a percorrer a lista/*/
}

void print(node *head){
    printf("%s",head->s);
    if (head->next != NULL)
        print(head->next);
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
