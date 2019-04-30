#include <stdio.h>
#include <stdlib.h>

int debug = 0;

typedef struct str_node  {
    struct str_node *next, *previous;
    char c;
} node;

typedef struct  {
    struct str_node *head, *last;
} list;

list* mk_list();                /* cria nova lista vazia */
void free_list(list* l);        /* liberta toda a memoria associada a lista */
void add_last(list* l, char c); /* adiciona o char c como o ultimo elemento da lista */
int is_paly(const list * ls);   /* calcula se a dada lista e um palindromo */

int main(){
    list *lista;
    char c;
    lista = mk_list();          /*/cria uma lista/*/
    while((c=getchar())!=EOF && c!='\n'){
        add_last(lista, c);     /*/adiciona elementos/*/
    }
    if(is_paly(lista))
        printf("yes\n");
    else
        printf("no\n");
    free_list(lista);           /*/apaga a lista/*/
    return 0;
}

list* mk_list(){
    list *lista;
    lista = malloc(sizeof(list));
    lista->head = NULL;
    lista->last = NULL;
    return lista;
}

void free_list(list* l){
    node *aux;
    while(l->head != NULL){
        aux = l->head;
        l->head = aux->next;
        free(aux);
    }
    l->last = NULL;/*/desnecessário, mas neste momento a lista está vazia e pronta a der reutilizada/*/
    free(l);
}

void add_last(list* l, char c){
    node *aux;
    aux = malloc(sizeof(node));
    aux->previous = l->last;
    aux->next = NULL;
    l->last = aux;
    if(l->head == NULL)
        l->head = aux;
    if(aux!=l->head)
        aux->previous->next = aux;
    aux->c = c;
}


int is_paly(const list * ls){
    node *inicio, *fim;
    inicio = ls->head;
    fim = ls->last;
    while(inicio != NULL){          /*ultimo node aponta pra NULL*/
        if(debug)printf("ini:%p:%c\tfim:%p:%c\n",(void*)inicio,inicio->c,(void*)fim,fim->c);
        if(inicio->c != fim->c)
            return 0;
        fim = fim->previous;
        inicio = inicio->next;
    }
    return 1;
}
