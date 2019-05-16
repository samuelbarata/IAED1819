/*╭─────────────────────────────────────────────────────────────────────────╮
  │  File:  estruturas.h                                                    │
  │  Author:  Samuel Barata (94230)                                         │
  │  Description: Contem as Estruturas do projeto                           │
  ╰─────────────────────────────────────────────────────────────────────────╯
*/
#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

/*╭─────────────╮
  │ constantes  │
  ╰─────────────╯*/
#define max_str 1024    /*caracteres maximos numa string*/
#define max_email 512   /*caracteres maximos nos emails*/
#define max_phone 64    /*caracteres maximos no telefone*/

/*╭─────────────╮
  │  estruturas │
  ╰─────────────╯*/

/*hash; usada nas hash tables*/
typedef unsigned int hash;

/*estrutura de uma double linked list [head = first; tail = last]*/
typedef struct d_linked_list{
    struct contact *head, *tail;
} d_linked_list;

/*hash_tables sao linked lists contem a head a apontar para o ultimo */
/*node a ser adicionado*/
typedef struct hash_table{
    struct node_linked *head;
} hash_table;

/*node de linked list, contem:  */
/*data -> contacto/dominio      */
/*next node -> node_linked      */
typedef struct node_linked{
    struct node_linked *next;
    void *data;
} node_linked;

/*contem um dominio [dom] e o numero de ocorrencias [counter]*/
typedef struct dominio{
    unsigned int counter;
    char *dom;
} dominio;

/*contacto:*/
/*prev -> contacto anterior*/
/*name -> nome*/
/*local -> primeira parte endereco email*/
/*dom -> dominio*/
/*phone -> telefone*/
/*next-> contacto seguinte*/
typedef struct contact{
    struct contact *prev;
    char *name;   /*maximo de 1023 caracteres ([0-9a-zA-Z-_]+)*/
    char *local;  /*maximo de 0511 caracteres ([0-9a-zA-Z-_.])*/
    dominio *dom; /*maximo de 0511 caracteres (@[0-9a-zA-Z-_.])*/
    char *phone;
    struct contact *next;
} contact;

/*buff usado na variavel global buffer para receber informacao do stdin*/
typedef struct buff{
    char comando;
    char nome[max_str];
    char email[max_email];
    char tel[max_phone];
    char local[max_email-2], dominio[max_email-1];
} buff;

#endif
