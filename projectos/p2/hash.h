/*╭─────────────────────────────────────────────────────────────────────────╮
  │  File:  hash.h                                                          │
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

hash_table HTname[hash_size];     /*hash table dos nomes*/
hash_table HTdom[hash_size];      /*hash table dos dominos*/

/*╭────────────────────╮
  │ funcoes auxiliares │
  ╰────────────────────╯*/

hash hasher(char *);              /*gera a hash de uma determinada string*/

void init_hash_table(hash_table *);       /*inicia hash table a NULL*/
void destroy_hash_table(hash_table *);    /*destroi uma hash table*/

void *push(hash_table *, void *);             /*recebe contacto ou dominio e grava*/
void pop(hash_table *, void *);               /*retira contacto / dominio / decrementa dominio*/

node_linked *encontra(hash_table *, char *);  /*recebe uma hash table e encontra o node com a string recebida*/

#ifdef DEBUG /* compilar com -D DEBUG */
void debug_hash(char);        /*printa uma hash table [dd / dn]*/
#endif

#endif
