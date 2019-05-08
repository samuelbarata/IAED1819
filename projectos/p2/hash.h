#ifndef HASH_H
#define HASH_H

#include "aux.h"
#define hash_size 5

typedef struct hash_node{
    contact *contacto;
    struct hash_node *samehash_next;
} hash_node;

typedef struct hash_table{
    struct hash_node *head;
} hash_table;

hash_table HTname[hash_size];
hash_table HTdom[hash_size];

void init_hash_table(hash_table *);                 /*recebe uma hash table e inicia tudo a NULL*/
unsigned int hashing(char *);                       /*devolve a hash de uma string em buffer.nome*/
hash_table *pointer_from_hash(int, hash_table *);
void delete_node(hash_table , hash_node *);        /*apaga um node da hashtable*/
void destroy_hashnodes(hash_table);
void destroy_hashT(hash_table *);                   /*destroi uma hash table*/
void hash_push_nome(contact *contacto);
void hash_pop_contacto(contact *contacto);



hash_node *encrontra_hash_node(char *str, hash_table HT);
contact *encontra_pessoa2(char *);


void debug_hash(hash_table *HT);

#endif
