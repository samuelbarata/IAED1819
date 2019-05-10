/*╭─────────────────────────────────────────────╮
  │  File:  aux.c                               │
  │  Author:  Samuel Barata (94230)             │
  │  Description: Contem as funcoes auxiliares  │
  ╰─────────────────────────────────────────────╯
*/

#include "aux.h"

/*le do stdin e guarda no buffer*/
void read_stdin(){
    if(buffer.comando == 'c')
        scanf("%s", buffer.dominio);
    else{
        scanf("%s", buffer.nome);
        if (buffer.comando == 'a' || buffer.comando == 'e'){
            scanf("%s", buffer.email);
            split_email();
        }
        if (buffer.comando == 'a')
            scanf("%s", buffer.tel);
    }
}

/*inicializa um livro de contactos*/
void init_adress_book(d_linked_list *AB){
    AB->head = NULL;
    AB->tail = NULL;
}

/*apaga todo o livro de contactos*/
void destroy_adress_book(d_linked_list *AB){
    contact *aux;
    while(AB->head!=NULL){
        aux = AB->head->next;
        destroi_contacto(AB->head);
        AB->head = aux;   
    }
}

/*cria um contacto com os dados contidos no buffer*/
contact *cria_contacto(){
    contact *contacto;


    contacto = malloc(sizeof(contact));

    contacto->name = malloc(sizeof(char) * strlen(buffer.nome) + 1);
    strcpy(contacto->name, buffer.nome);

    contacto->local = malloc(sizeof(char) * strlen(buffer.local) + 1);
    strcpy(contacto->local, buffer.local);

    contacto->phone = malloc(sizeof(char) * strlen(buffer.tel) + 1);
    strcpy(contacto->phone, buffer.tel);

    contacto->next=NULL;
    contacto->prev=NULL;
    return contacto;
}

/*cria um dominio a partir da string recebida*/
dominio *cria_dominio(char *str){
    dominio *dom = malloc(sizeof(dominio));
    dom->counter = 1;
    dom->dom = malloc(sizeof(char)*strlen(str)+1);
    strcpy(dom->dom, buffer.dominio);
    return dom;
}

/*recebe o endereço de um contacto e apaga o se conteudo*/
void destroi_contacto(contact *p){
    free(p->name);
    free(p->local);
    free(p->phone);
    free(p);
}

/*recebe o endereço de um dominio e apaga o seu conteudo*/
void destroi_dominio(dominio *p){
    free(p->dom);
    free(p);
}



void push_list(d_linked_list *AB, contact *c){
    if(!AB->head){
        AB->head = c;
        AB->tail = c;
    }else{
        c->prev = AB->tail;
        AB->tail->next = c;
        AB->tail = c;
    }
}

void pop_list(d_linked_list *AB, contact *c){
    if(c->prev)         /*se nao e o primeiro*/
        c->prev->next = c->next;
    if(c->next)         /*se nao e o ultimo*/
        c->next->prev = c->prev;
    if(c==AB->head)      /*se e o primeiro*/
        AB->head = c->next;
    if(c==AB->tail)      /*se e o ultimo*/
        AB->tail = c->prev;

    destroi_contacto(c);
}

/*pega no email do buffer e divide-o em local/dominio*/
void split_email(){
    char *p;
    p = buffer.email;
    while(p[0]!='@')
        p++;
    p++;
    strcpy(buffer.dominio, p);
    p--;
    *p='\0';
    strcpy(buffer.local, buffer.email);
}



/*imprime um contacto recebendo o seu endereço de memória*/
void printa_contacto(contact *contacto){
    printf("%s %s@%s %s\n",
    contacto->name,contacto->local,contacto->dom->dom,contacto->phone);
}

void printd(char *debug_message){
    #ifdef DEBUG
    puts(debug_message);
    #endif
    debug_message++; /*para nao dar warnings de n usada*/
}
