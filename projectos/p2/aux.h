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

void init_adress_book(d_linked_list *);     /*inicializa lista duplamente ligada*/
void destroy_adress_book(d_linked_list *);  /*destroi lista duplamente ligada*/

contact *cria_contacto();             /*cria um contacto a partir do buffer*/
dominio *cria_dominio(char *);        /*cria um dominio a partir da string recebida*/

void destroi_contacto(contact *);       /*recebe contacto e apaga o seu conteudo*/
void destroi_dominio(dominio *);        /*recebe dominio e apaga seu conteudo*/
void destroy_dominios(hash_table *);    /*destroi todos os dominios dentro de uma hash table*/

void push_list(d_linked_list *, contact *); /*adiciona um conacto a uma double linked list*/
void pop_list(d_linked_list *, contact *);  /*remove um conacto a uma double linked list*/

void split_email();                         /*divide o email em local@dominio no buffer*/
void printa_contacto(contact *);            /*imprime um contacto recebendo o seu endereço*/


#endif
