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
  
#define max_args 9          /*max de argumentos = 6 + 3 participantes*/
#define max_sala 10         /*[1;10]*/
#define max_str 64          /*strings 63 characteres*/
#define max_part 4          /*3 participantes + organizador*/
#define max_eventos 100     /*max eventos 100*/
#define max_arg_str 355     /*max char input*/
#define swap(A,B)  { e_eventos t = A; A = B; B = t;} /*funcao que troca a posicao de 2 eventos*/


/*╭─────────────╮
  │  estruturas │
  ╰─────────────╯*/
typedef struct e_day{
    int d;  /*dia*/
    int m;  /*mes*/
    int a;  /*ano*/
} day;

typedef struct e_coordenada{
    int room;       /*sala [0 - 9]*/
    int evendo_id;  /*indice do evento dentro da sala*/
} coordenada;

typedef struct estrutura_eventos{
    int room;                               /*sala onde o evento esta [0 - 9]*/
    char descricao[max_str];                /*descricao do evento*/
    day dia;                                /*dia do evento*/
    unsigned int tempo;                     /*inicio do evento em minutos */
    int duracao;                            /*duracao do evento em minutos*/
    char participantes[max_part][max_str];  /*o primeiro participante e o organizador*/
    int status;                             /*0 vazio; !0 ocupado*/
    unsigned long int abs_time;             /*tempo desde 01/01/2019*/
} e_eventos;

typedef struct estrutura_sala{
    e_eventos evento[max_eventos];          /*eventos*/
    int total_eventos;                      /*total de eventos na sala atual*/
} e_sala;


/*╭───────────────────╮
  │ variaveis globais │
  ╰───────────────────╯*/

/*memoria de salas que contem eventos*/
e_sala sala[max_sala];
/*memoria dos ultimos argumentos lidos no stdin*/
char args[max_args][max_str]; 

/*╭────────────────────╮
  │ funcoes auxiliares │
  ╰────────────────────╯*/

void read();                                         /*le o que esta no stdin para a var args*/
void lista_evento(coordenada);                       /*recebendo uma coordenada, escreve o evento correspondente*/
day get_day(char arg[]);                             /*recebe "ddmmaaaa" e converte para o formato da estrutura*/
int get_time(char arg[]);                            /*recebe "hhmm" e converte para minutos*/
void sort_inroom(int);                               /*ordena os eventos numa determinada sala*/
void reset_evento(coordenada);                       /*inativa o evento e reduz a contagem da sala*/
coordenada encontra_evento(char descricao[]);        /*recebendo uma descricao devolve a coordenada desse evento*/
int incompatibilidade_eventos(e_eventos, e_eventos); /*ve se 2 dados eventos ocorrem ao mesmo tempo*/
int same_pessoa(char pessoa[], e_eventos);           /*procura uma pessoa num dado evento*/
int char_to_int(char);                               /*recebe um char e converte no inteiro correspondente*/
int str_to_int(char *);                              /*recebe uma string e converte em inteiro*/
unsigned long int calcula_abs(e_eventos);            /*calcula uma medida de tempo de um evento desde 1/1/2019*/
int verifica_sala(e_eventos teste);                  /*verifica se uma sala tem outro evento aquela hora*/
int verifica_pessoas(e_eventos, char);               /*verifica se uma pessoa esta em 2 eventos ao mesmo tempo*/
void grava_evento(e_eventos);                        /*recebe um evento e grava-o na memoria*/
int same_evento(e_eventos, e_eventos);               /*recebe 2 eventos e compara para ver se sao o mesmo*/
