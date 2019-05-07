#include "hash.h"

/*inicializa uma hash table com "hash_size" nodes*/
void init_hash_table(hash_table *HT){
    int i;
    for(i=0;i<hash_size;i++){
        HT[i]->head = NULL;
    }
}

/*devolve uma hash para cada objeto*/
unsigned long hash(unsigned char *str){
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    return hash % hash_size;
}

/*recebe um head de uma hash table [primeiro node] e uma hash e devolve
o pointer do node*/
hash_table *pointer_from_hash(int hash, hash_table (*HThead)){
    return HThead + hash;
}

hash_node *delete_node(hash_node (*select), hash_node (*HThead)){
    /*if ()*/
    return NULL;
}

void destroy_hashnodes(hash_table *HThead){
    hash_node *head, *next;
    head = HThead;
    next = head->samehash_next;
    while(head){
        free(head);
        head = next;
        next = head->samehash_next;
    }
    destroy_hashT(HThead++);
}

void destroy_hashT(hash_table *HThead){
    int i;
    hash_node *aux = HThead->head;

    for(i=0;i<hash_size;i++){
        destroy_hashnodes(aux);
        aux++;
    }
    free(HThead);
}
