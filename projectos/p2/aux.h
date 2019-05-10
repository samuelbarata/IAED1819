/*╭─────────────────────────────────────────────────────────────────────────╮
  │  File:  aux.h                                                           │
  │  Author:  Samuel Barata (94230)                                         │
  │  Description: Contem as bibliotecas, constantes,                        │
  │               e declaracoes de funcoes auxiliares                       │
  ╰─────────────────────────────────────────────────────────────────────────╯
*/

#ifndef AUX_H
#define AUX_H

/*╭─────────────╮
  │ bibliotecas │
  ╰─────────────╯*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"
#include "hash.h"

/*╭───────────────────╮
  │ variaveis globais │
  ╰───────────────────╯*/

d_linked_list adress_book;  /*livro de contactos; inicio e fim da lista ligada*/
buff buffer;                /*auxiliar das varias variaveis existentes*/


/*╭────────────────────╮
  │ funcoes auxiliares │
  ╰────────────────────╯*/
void read_stdin();                          /*le do stdin para a estrutura buffer*/

/*livro contactos*/
void init_adress_book(d_linked_list *);
void destroy_adress_book(d_linked_list *);

contact *cria_contacto();
dominio *cria_dominio(char *str);     /*inicializa um dominio*/

void destroi_contacto(contact *p);
void destroi_dominio(dominio *p);

void push_list(d_linked_list *, contact *);
void pop_list(d_linked_list *, contact *);

void split_email();                         /*divide o email local + dominio(inclui @)*/
void printa_contacto(contact *);            /*imprime um contacto recebendo o seu endereço*/

void printd(char *debug_message);

void destroy_dominios(hash_table *);

#endif
