#include "ex02.h"

void init(stack * s){
    (*s).v = malloc(sizeof(int)*max);
    (*s).cap = max;
    (*s).sz = 0;
}

void push(stack * s, int e){
    int *k;
    if(s->sz==s->cap){
        s->v = realloc(s->v, sizeof(int)*s->cap*2);
        s->cap = (s->cap) * 2;
    }
    k = s->v;
    k += s->sz;
    (*k) = e;
    (*s).sz++;
}

int pop(stack * s){
    int *aux;
    if(!is_empty(s)){
        s->sz--;
        aux = s->v;
        aux += s->sz;
        return *aux;
    }
    return 0;
}

void destroy(stack * s){
    free(s->v);
}

int is_empty(stack * s){
    return !s->sz;
}
