#include "ex01.h"

int is_eq(node *h1, node *h2);   /* compara duas listas*/
node *rev(node *head);           /* devolve uma nova lista que corresponda a lista dada invertida */

int main(){
    int c;
    node (*head), *p;
    head = NULL;
    while ((c = getchar())!='\n'){
        head = push(head, c);
    }
    p = rev(head);
    if(is_eq(p, head)){
        printf("yes\n");
        return 0;
    }
    printf("no\n");
    return 0;
}

int is_eq(node *h1, node *h2){
    if(h1 == NULL && h2 == NULL)
        return 1;
    if(h1->v == h2->v)
        return is_eq(h1->next, h2->next);
    return 0;
}  

node *rev(node *head){
    node *p = NULL, *local_head = head;
    p = push(p, local_head->v);
    while (local_head->next != NULL){
        local_head = local_head->next;
        p = push(p, local_head->v);
    }
    return p;
}
