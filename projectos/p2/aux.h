/*╭─────────────────────────────────────────────────────────────────────────╮
  │  File:  aux.h                                                           │
  │  Author:  Samuel Barata (94230)                                         │
  │  Description: Contem as bibliotecas, constantes, estruturas do projeto  │
  │  e declaracoes de funcoes auxiliares                                    │
  ╰─────────────────────────────────────────────────────────────────────────╯
*/

/*╭─────────────╮
  │ bibliotecas │
  ╰─────────────╯*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*╭─────────────╮
  │ constantes  │
  ╰─────────────╯*/
#define max_str 1023
#define max_email 511               /*(511)(@511)*/
#define max_phone 63
#define no_of_args 5                /*numero de argumentos*/

/*╭─────────────╮
  │  estruturas │
  ╰─────────────╯*/
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
    contact *head;
    contact *tail;
} livro;

/*╭───────────────────╮
  │ variaveis globais │
  ╰───────────────────╯*/
livro projeto2; /*livro de contactos; inicio e fim da lista ligada*/
buff buffer;    /*auxiliar das varias variaveis existentes*/

/*╭────────────────────╮
  │ funcoes auxiliares │
  ╰────────────────────╯*/
void read_stdin ();                         /*le do stdin para a estrutura buffer*/
contact *cria_contacto();                   /*cria um contacto com o conteudo do buffer*/
contact *malloc_contacto();                 /*cria um contacto vazio*/
void destroi_contacto(contact *);           /*destroi um contacto recebendo o seu endereço*/
void split_email();                         /*divide o email local + dominio(inclui @)*/
void printa_contacto(contact *);            /*imprime um contacto recebendo o seu endereço*/
int verifica_erros(contact *, contact *);   /*[recursiva] recebe 2 contactos sendo o 2º pertencente ao livro e testa se sao o mesmo ou nao*/
contact *encrontra_nome();                  /*procura o nome do buffer nos contactos do livro*/
void destroi_lista();                       /*free toda a memoria ainda alocada*/
