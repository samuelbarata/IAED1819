#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *v;  /* contents of the stack */
    int cap; /* capacity of v, i.e. how many elements v  can fit */
    int sz; /* number of elements currently stored in v */
} stack;


void init(stack * s); /* initialize stack s as empty and with initial capacity 4 */
void push(stack * s, int e); /* push e on top of the stack  (reallocate v if necessary) */
int pop(stack * s); /* remove top element from stack and remove it (not necessary to reallocate v) */
int is_empty(stack * s); /* return 1 iff s represents the empty stack, return 0 otherwise */
void destroy(stack * s); /* frees memory associated with the stack */

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