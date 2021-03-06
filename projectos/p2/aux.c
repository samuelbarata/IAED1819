/*╭─────────────────────────────────────────────╮
  │  File:  aux.c                               │
  │  Author:  Samuel Barata (94230)             │
  │  Description: Contem as funcoes auxiliares  │
  ╰─────────────────────────────────────────────╯
*/

#include "aux.h"

/*╭───────╮
  │ input │
  ╰───────╯*/

/*le do stdin e guarda no buffer*/
void read_stdin(){
    if(buffer.comando == 'c')
        scanf("%s", buffer.dominio);
    else{
        scanf("%s", buffer.nome); /*no caso do comando P vai ler o prefixo*/
        if (buffer.comando == 'a' || buffer.comando == 'e'){
            scanf("%s", buffer.email);
            split_email();
        }
        if (buffer.comando == 'a')
            scanf("%s", buffer.tel);
    }
}

/*╭────────────────╮
  │ inicializacoes │
  ╰────────────────╯*/

/*inicializa um livro de contactos*/
void init_adress_book(d_linked_list *AB){
    AB->head = NULL;
    AB->tail = NULL;
}

/*╭───────────╮
  │ geradores │
  ╰───────────╯*/

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

/*╭─────────────╮
  │ destrutores │
  ╰─────────────╯*/

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

/*apaga todo o livro de contactos*/
void destroy_adress_book(d_linked_list *AB){
    contact *aux;
    while(AB->head!=NULL){
        aux = AB->head->next;
        destroi_contacto(AB->head);
        AB->head = aux;   
    }
}

/*destroi todos os dominios ainda alocados numa hash table*/
void destroy_dominios(hash_table *HT){
    int i;
    node_linked *node, *aux;
    for(i=0;i<hash_size;i++){
        node = HT[i].head;
        while(node){    
            aux = node->next;
            destroi_dominio(node->data);
            node = aux;
        }
    }  
}

/*╭───────────────────────────────────────────╮
  │ operacoes sobre listas duplamente ligadas │
  ╰───────────────────────────────────────────╯*/

/*adiciona o contacto a uma double linked list*/
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

/*remove e apaga o contacto de uma double linked list*/
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

/*╭────────────────────╮
  │ funcoes auxiliares │
  ╰────────────────────╯*/

/*pega no email do buffer e divide-o em local@dominio*/
void split_email(){
    char *p;
    p = buffer.email;
    do{
        p++;
    } while(p[0]!='@');      /*avança ate a posicao do @*/
    *p = '\0';              /*substitui o @ por \0 para definir o fim do local*/
    p++;                    /*avanca para o inicio do dominio*/
    strcpy(buffer.dominio, p);          /*copia o dominio*/
    strcpy(buffer.local, buffer.email);
}

/*imprime um contacto recebendo o seu endereço de memoria*/
void printa_contacto(contact *contacto){
    printf("%s %s@%s %s\n",
    contacto->name,contacto->local,contacto->dom->dom,contacto->phone);
}

/*verifica se o contacto existe, se existir adiciona prefixo*/
contact* adiciona_aux(contact *contacto){
    if (encontra(HTname, contacto->name)){
        contacto->name=realloc(contacto->name, strlen(contacto->name)+3);/*sizeof(char)=1*/
        strcat(contacto->name, "_1");
        return adiciona_aux(contacto);
    }
    return contacto;
}

/*verifica se um dado contacto contem o prefixo em buffer.nome, devolve 0 se nao tiver e 1 se tiver*/
int prefixo_aux(contact *contacto){
    int i, len=strlen(buffer.nome);
    char *nome1=buffer.nome, *nome2=contacto->name;
    for(i=0;i<len;i++)
        if((*nome1)!=(*nome2))
            return 0;
    
    return 1;
}
