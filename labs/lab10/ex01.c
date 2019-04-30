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
    node *head = NULL, *p;
    char buffer[MAX] = "";
    p = head;       /*/no inicio ambos apontam para o mesmo local/*/
    scanf("%s", buffer);
    while(strcmp("x",buffer)){
        p->next = push(p, buffer);
        scanf("%s", buffer);
    }
    return 0;
}


node *push(node *head, const char *s){
    node(*j) = malloc(sizeof(node));
    char *k = malloc(sizeof(char) * (strlen(s) + 1));
    strcpy(k, s);
    j->s = k;
    j->next = NULL;
    if (head == NULL){          /*/primeiro elemento/*/
        head = j;
    }
    return j;
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
