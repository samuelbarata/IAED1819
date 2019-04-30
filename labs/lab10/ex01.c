#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1024

int debug = 0;

typedef struct stru_node{
    struct stru_node *next;
    char *s;
} node;

node *p;

node *pop(node *head);
node *push(node *head, const char *);
node *destroy(node *head);
void print(node *head);

int main(){
    node *head = NULL;
    char buffer[MAX] = "";
    scanf("%s", buffer);
    while(strcmp("x",buffer)){
        if(head == NULL){
            head = push(head, buffer);
            if(debug)printf("head:\t%p\n", (void*)head);
            p = head;                   /*/aponta para a ultima posição da lista/*/
        }
        else{
            p->next = push(p, buffer);
            p = p->next;
            if(debug)printf("p:\t%p\n", (void*)p);
        }
        scanf("%s", buffer);
    }
    print(head);
    destroy(head);
    return 0;
}


node *push(node *head, const char *s){
    node (*j);
    char *k;
    j = malloc(sizeof(node));
    k = malloc(sizeof(char) * (strlen(s) + 1));
    strcpy(k, s);
    j->s = k;
    j->next = NULL;
    if(head == NULL){
        head = j;
    }
    else{
        head->next = j;
    }
    if(debug)printf("j:\t%p\t",(void*)j);
    return j;
}

void print(node *head){
    if (head->next != NULL){
        print(head->next);
        printf("%s\n",head->s);
    }else
        printf("%s\n",head->s);
}

node *pop(node *head){
    node *aux;
    aux = head;
    head = head->next;
    free(aux->s);
    free(aux);
    return head;
}

node *destroy(node *head){
    do{
        head = pop(head);
        if(debug)printf("pop:\t%p\n",(void*)head);
    }while(head!=NULL);
    return head;
}
