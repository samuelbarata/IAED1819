/*UTF-8*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_str 1023
#define max_phone 63
#define no_of_args 5                /*numero de argumentos*/

typedef struct contacto{            /*vai ser usada uma lista duplamente ligada*/
    struct contacto *previous;      /*memória do contacto anterior*/
    char *name;                     /*máximo de 1023 caracteres ([0-9a-zA-Z-_]+)*/
    char *local,/*@*/*dominio;      /*máximo de 0511 caracteres ([0-9a-zA-Z-_.] @ [0-9a-zA-Z-_.])*/
    char *phone;                    /*máximo de 0063 caracteres ([0-9\-]+)*/
    struct contacto *next;          /*memória do contacto seguinte*/
}   contact;

char **init_buffer();               /*aloca memoria para a variavel global de argumentos*/
void destroy_buffer(char **);            /*free do buffer*/
