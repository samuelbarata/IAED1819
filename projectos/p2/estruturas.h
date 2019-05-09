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
#define max_str 1023    /*caracteres maximos numa string*/
#define max_email 511   /*caracteres maximos nos emails: (511)@(511)*/
#define max_phone 63    /*caracteres maximos no telefone*/

/*╭─────────────╮
  │  estruturas │
  ╰─────────────╯*/

/*estrutura de uma double linked list [head = first; tail = last]*/
typedef struct d_linked_list{
    struct contact *head, *tail;
} d_linked_list;

/*hash_tables sao linked lists contem a head*/
typedef struct hash_table{
    struct node_linked *head;
} hash_table;

/*node de linked list, contem conteudo e next node*/
typedef struct node_linked{
    struct node_linked *next;
    void *data;
} node_linked;

/*contem um dominio e o numero de ocorrencias*/
typedef struct dominio{
    unsigned int counter;
    char *dom;
} dominio;

/*contem um contacto, nome email e telefone*/
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
    char nome[max_str+1];
    char email[max_str+1];
    char tel[max_phone+1];
    char local[max_email], dominio[max_email];
} buff;

#endif
