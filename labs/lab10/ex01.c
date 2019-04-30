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
    node *head = NULL, *p=head;
    char buffer[MAX] = "";
    scanf("%s", buffer);
    head = push(head, buffer);      /*/primeiro elemento da lista/*/
    p = head;                       /*/ultimo elemento da lista/*/
    while(strcmp("x",buffer)){
        p = push(p, buffer);
        scanf("%s", buffer);
    }
    return 0;
}

















node *push(node *head, const char *s){
    node(*p) = malloc(sizeof(node));
    char *k = malloc(sizeof(char) * (strlen(s) + 1));
    strcpy(k, s);
    p->s = k;
    p->next = NULL;
    return p;
}

void print(node *head){
    printf("%s",head->s);
    if (head->next != NULL)
        print(head->next);
}

node *pop(node *head){
    if(head->next->next == NULL){
        free(head->next);
        return head;
    }
    return pop(head->next);
}

node *destroy(node *head){
    node *aux;
    aux = head->next;
    free(head);
    if(aux != NULL)
        destroy(aux);
    return aux;
}
