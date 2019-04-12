#include "ex02.h"

void init(stack * s){
    (*s).v = malloc(sizeof(int)*max);
    (*s).cap = max;
    (*s).sz = 0;
}

void push(stack * s, int e){
    if((*s).sz < (*s).cap){
        (*s).sz++;
        *(*s).v = e;
        (*s).v++;
    }
}

int pop(stack * s){
    int aux;
    if(!is_empty(s)){
        (*s).sz--;
        aux = *(*s).v;
        (*s).v--;
        return aux;
    }
    return 0;
}

void destroy(stack * s){
    free(s);
}

int is_empty(stack * s){
    return !((*s).sz > 0);
}
