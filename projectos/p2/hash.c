#include "hash.h"

/*inicializa uma hash table*/
hash_table *init_hash_table(){
    hash_table *htable = malloc(sizeof(hash_table)*27+1);




    return htable;
}

/*devolve o endereço de uma lista ligada onde vai guardar a memoria do objeto*/
int hash(){
    char *hasher = buffer.nome;
    unsigned long int hash=0;
    while(hasher[0]){
        hash += hasher[0]*hash;
        hasher++;
    }
    return (int)hash%1000;
}

void *pointer_from_hash(int hash, hash_table (*HThead)){
    int i;
    for(i=0;i<hash;i++,HThead++);
    return HThead;
}

