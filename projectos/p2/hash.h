/*╭─────────────────────────────────────────────────────────────────────────╮
  │  File:  aux.h                                                           │
  │  Author:  Samuel Barata (94230)                                         │
  │  Description: Contem declaracoes de funcoes auxiliares de hashe tables  │
  ╰─────────────────────────────────────────────────────────────────────────╯
*/

#ifndef HASH_H
#define HASH_H

#include "estruturas.h"
#include "aux.h"

#define hash_size 1999 /*https://en.wikipedia.org/wiki/List_of_prime_numbers*/

/*╭───────────────────╮
  │ variaveis globais │
  ╰───────────────────╯*/

hash_table HTname[hash_size];
hash_table HTdom[hash_size];

typedef unsigned int hash;
hash hasher(char *);                        /*devolve a hash de uma string*/

/*hash tables*/
void init_hash_table(hash_table *);         /*inicia hash table dos nomes a NULL*/
//void destroy_hash_table(hash_table *);    /*destroi uma hash table*/

node_linked *encontra(hash_table *, char *);       /*recebe uma hash table e encontra o node com a string recebida*/
void push(hash_table *, void *);            /*recebe contacto ou dominio e grava*/
void pop(hash_table *, void *);


void delete_node(hash_table *, hash_node *, hash);        /*apaga um node da hashtable*/
void destroy_hashnodes(hash_table);
void destroy_hashT();                   /*destroi uma hash table*/
void hash_push_nome(contact *contacto);
void hash_pop_contacto(contact *contacto);
contact *encontra_pessoa2(char *);
hash *encrontra_hash_node(char *str, hash_table HT);

void init_hash_dominio();
void destroy_hashD();
void destroy_nodes(hash_dominio );
dominio *hash_push_dominio(char *);
void hash_pop_dominio(dominio *);
void delete_dom(dominio *);
dominio *hash_find_dom(char *);

void debug_hash_n();
void debug_hash_d();

#endif
