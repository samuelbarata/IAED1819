#include "hash.h"

/*inicializa uma hash table*/
hash_table *init_hash_table(){
    hash_table *htable = malloc(sizeof(hash_table)*27+1);




    return htable;
}

/*devolve o endereço de uma lista ligada onde vai guardar a memoria do objeto
0-9-.   -> 0
a/A     -> 1
b/B     -> 2
z/z     -> 26*/
int hash(){
    char hasher = buffer.nome[strlen(buffer.nome)-1];
    if(hasher<65)
        return 0;
    if(hasher>=65 && hasher<=90)
        return hasher - 'A'+1;
    return hasher - 'a'+1;
}

void *pointer_from_hash(int hash, hash_table (*HThead)){
    int i;
    for(i=0;i<hash;i++,HThead++);
    return HThead;
}

