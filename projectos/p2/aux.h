#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_str 1023
#define max_email 511
#define max_phone 63
#define no_of_args 5                /*numero de argumentos*/


typedef struct cont{            /*vai ser usada uma lista duplamente ligada*/
    struct cont *previous;      /*memoria do contacto anterior*/
    char *name;                     /*maximo de 1023 caracteres ([0-9a-zA-Z-_]+)*/
    char *local,*dominio;           /*maximo de 0511 caracteres ([0-9a-zA-Z-_.] + @[0-9a-zA-Z-_.])*/
    char *phone;                    /*maximo de 0063 caracteres ([0-9\-]+)*/
    struct cont *next;          /*memoria do contacto seguinte*/
}   contact;

typedef struct buff{
    char comando;
    char nome[max_str];
    char email[max_str];
    char tel[max_phone];
    char local[max_email], dominio[max_email];
} buff;

typedef struct livro{
    unsigned long int num_contactos;
    contact *head;
    contact *tail;
} livro;

livro projeto2;
buff buffer;


void read_stdin ();
contact *cria_contacto();
contact *malloc_contacto();
void destroi_contacto(contact *);
void split_email();
void printa_contacto(contact *);
int verifica_erros(contact *, contact *);
contact *encrontra_nome();
