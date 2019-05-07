#ifndef HASH_H
#define HASH_H

#include "aux.h"
#define hash_size 3

typedef struct hash_node{
    /*struct hash_node *samehash_prev;*/
    contact *contacto;
    struct hash_node *samehash_next;
} hash_node;

typedef struct hash_table{
    struct hash_node *head;
} hash_table;

hash_table HTname[hash_size];
hash_table HTdom[hash_size];

void init_hash_table(hash_table *);
unsigned int hash(unsigned char *); /*devolve a hash de uma string em buffer.nome*/
hash_table *pointer_from_hash(int, hash_table *);
void delete_node(hash_table *, hash_node *);
void destroy_hashnodes(hash_table);
void destroy_hashT(hash_table *);
void hash_push_nome(contact *contacto);
void hash_pop_nome(contact *contacto);



contact *encontra_pessoa2(contact *contacto);



void debug_hash(hash_table *HT);

#endif
