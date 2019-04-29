#include "ex01.h"

/*
int main(){
    int c;
    node (*head);
    head = NULL;
    while ((c = getchar())!='0'){
        head = push(head, c);
    }
    print(head);
    return 0;
}*/

node *push(node *head, int e){
    node (*p) = malloc(sizeof(node));       /*p contem o endereço da alocação*/
    p->v = e;
    p->next = head;                         /*endereço anterior*/
    /*/if(debug)printf("push:%p:%d\n", p, p->v);/*/
    return p;
}

void print(node *head){
    putchar(head->v);
    /*/if(debug)printf("next:%p\n",head->next);/*/
    printf("\n");
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
