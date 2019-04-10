#include "ex02.h"

void init(stack * s){
    stack temp = *s;
    temp.cap = 4;
    temp.sz = 0;
}

void push(stack * s, int e){
    stack temp = *s;
    if(temp.sz < temp.cap){
        temp.sz++;
        temp.v = e;
        temp.v++;
    }
}

int pop(stack * s){
    int aux;
    stack temp = *s;
    if(!is_empty(s)){
        temp.sz--;
        aux = temp.v;
        temp.v--;
        return aux;
    }
    return 0;
}

void destroy(stack * s){
    free(s);
}

int is_empty(stack * s){
    stack temp = *s;
    return !(temp.sz > 0);
}
