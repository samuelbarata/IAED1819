/*╭─────────────────────────────────────────────────────────────────────────╮
  │  File:  aux.h                                                           │
  │  Author:  Samuel Barata (94230)                                         │
  │  Description: Contem as bibliotecas, constantes, estruturas do projeto  │
  │  e declaracoes de funcoes auxiliares                                    │
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
contact *encrontra_nome();                  /*procura o nome do buffer nos contactos do livro*/
void destroi_lista();                       /*free toda a memoria ainda alocada*/

#endif
