#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_str 1023
#define max_phone 63
#define no_of_args 5                /*numero de argumentos*/

typedef struct contacto{            /*vai ser usada uma lista duplamente ligada*/
    struct contacto *previous;      /*memoria do contacto anterior*/
    char *name;                     /*maximo de 1023 caracteres ([0-9a-zA-Z-_]+)*/
    char *local,/*@*/*dominio;      /*maximo de 0511 caracteres ([0-9a-zA-Z-_.] @ [0-9a-zA-Z-_.])*/
    char *phone;                    /*maximo de 0063 caracteres ([0-9\-]+)*/
    struct contacto *next;          /*memoria do contacto seguinte*/
}   contact;

char **init_buffer();               /*aloca memoria para a variavel global de argumentos*/
void destroy_buffer(char **);       /*free do buffer*/
