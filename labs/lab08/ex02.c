#include <ex02.h>

int main(){
    stack k;
    init(*k);
    push(*k, 1);
    push(*k, 2);
    printf("%d %d", pop(*k),pop(*k));
    destroy(*k);
    return 0;
}

void init(stack * s){
    *s.cap = 4;
    *s.sz = 0;
}

void push(stack * s, int e){
    if(s.sz < s.cap){
        *s.sz++;
        *s.v = e;
        *s.v++;
    }
}

int pop(stack * s){
    int aux;
    if(!is_empty(s)){
        *s.sz--;
        aux = *s.v;
        *s.v--;
        return aux;
    }
    return 0;
}

void destroy(stack * s){
    free(s);
}

int is_empty(stack * s){
    return !(*s.sz > 0);
}