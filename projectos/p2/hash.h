#ifndef HASH_H
#define HASH_H

#include "aux.h"


typedef struct hash_node{
    struct hash_node *phnode;
    contact *contacto;
    struct hash_node *nhnode;
} hash_node;

typedef struct hash_table{
    int indice;
    hash_node *nhnode;
} hash_table;




hash_table *init_hash_table();
int hash(); /*devolve a hash de uma string em buffer.nome*/
void *pointer_from_hash(int , hash_table *);













#endif
