#include "ex02aux.h"

node *push(node *head, int e){
    node (*p) = malloc(sizeof(node));       /*p contem o endereço da alocação*/
    p->v = e;
    p->next = head;                         /*endereço anterior*/
    if(debug)printf("malloc:%p:%d\n", (void*)p, p->v);
    return p;
}

void print(node *head){
    if(debug)printf("print:%p",(void*)head);
    if(head == NULL)
        return;
    putchar(head->v);
    printf("\n");
    print(head->next);
}

node *pop(node *head){
    node *p;
    p = head->next;
    if(debug)printf("free:%p\n",(void*)head);
    free(head);
    return p;
}

node *destroy(node *head){
    while(head!=NULL){
        head = pop(head);
    }
    return head;
}
