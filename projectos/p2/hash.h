#ifndef HASH_H
#define HASH_H

#include "estruturas.h"
#include "aux.h"
#define hash_size 1999 /*https://en.wikipedia.org/wiki/List_of_prime_numbers*/

typedef unsigned int hash;



hash_table HTname[hash_size];
hash_dominio HDom[hash_size];


hash hasher(char *);                                /*devolve a hash de uma string*/

void init_hash_table(hash_table *);                 /*recebe uma hash table e inicia tudo a NULL*/
void delete_node(hash_table *, hash_node *, hash);        /*apaga um node da hashtable*/
void destroy_hashnodes(hash_table);
void destroy_hashT(hash_table *);                   /*destroi uma hash table*/
void hash_push_nome(contact *contacto);
void hash_pop_contacto(contact *contacto);
contact *encontra_pessoa2(char *);
hash_node *encrontra_hash_node(char *str, hash_table HT);


void init_hash_dominio(hash_dominio *);
void destroy_hashD(hash_dominio *);
void destroy_nodes(hash_dominio );
dominio *hash_push_dominio(char *);
void hash_pop_dominio(dominio *);
void delete_dom(dominio *);
dominio *hash_find_dom(char *);


void debug_hash(hash_table *HT);

#endif
