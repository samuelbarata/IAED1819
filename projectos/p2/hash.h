#ifndef HASH_H
#define HASH_H

#include "aux.h"
#define hash_size 1009

typedef struct hash_node{
    /*struct hash_node *samehash_prev;*/
    contact *contacto;
    struct hash_node *samehash_next;
} hash_node;

typedef struct hash_table{
    struct hash_node *head;
} hash_table;


void init_hash_table(hash_table *);
unsigned long hash(unsigned char *); /*devolve a hash de uma string em buffer.nome*/
hash_table *pointer_from_hash(int, hash_table *);
hash_node *delete_node(hash_node *, hash_node *);
void destroy_hashnodes(hash_table *);
void destroy_hashT(hash_table *);

#endif
