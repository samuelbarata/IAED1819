/*╭─────────────────────────────────────────────────────────────────────────╮
  │  File:  aux.h                                                           │
  │  Author:  Samuel Barata (94230)                                         │
  │  Description: Contem as Estruturas do projeto                           │
  ╰─────────────────────────────────────────────────────────────────────────╯
*/

#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

/*╭─────────────╮
  │ constantes  │
  ╰─────────────╯*/
#define max_str 1023
#define max_email 511   /*(511)@(511)*/
#define max_phone 63

/*╭─────────────╮
  │  estruturas │
  ╰─────────────╯*/

/**/
typedef struct dominio{
    unsigned int counter;
    char *dom;
    struct dominio *samehash_next;
} dominio;

typedef struct hash_dominio{
    struct dominio *dom;
} hash_dominio;


typedef struct contact{         /*vai ser usada uma lista duplamente ligada*/
    struct contact *previous;   /*memoria do contacto anterior*/
    char *name;                 /*maximo de 1023 caracteres ([0-9a-zA-Z-_]+)*/
    char *local;                /*maximo de 0511 caracteres ([0-9a-zA-Z-_.])*/
    dominio *dom;               /*maximo de 0511 caracteres (@[0-9a-zA-Z-_.])*/
    char *phone;                /*maximo de 0063 caracteres ([0-9\-]+)*/
    struct contact *next;       /*memoria do contacto seguinte*/
}   contact;

typedef struct buff{
    char comando;
    char nome[max_str];
    char email[max_str];
    char tel[max_phone];
    char local[max_email], dominio[max_email];
} buff;


typedef struct hash_node{
    contact *contacto;
    struct hash_node *samehash_next;
} hash_node;

typedef struct hash_table{
    struct hash_node *head;
} hash_table;


typedef struct livro{
    contact *head;
    contact *tail;
} livro;


#endif
