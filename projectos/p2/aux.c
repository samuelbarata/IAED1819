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
void init_adress_book(d_linked_list AB){
    AB.head = NULL;
    AB.tail = NULL;
}

/*apaga todo o livro de contactos*/
void destroy_adress_book(d_linked_list AB){
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

    return contacto;
}

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

/***********************************************************************/








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

/*devolve o endereco de memoria do contacto cujo nome esta no buffer
ou NULL se não encontrar*/
contact *encrontra_nome(){
    contact *contacto;
    contacto = projeto2.head;
    while(contacto){
        if(!strcmp(contacto->name, buffer.nome))
            return contacto;
        contacto = contacto->next;
    }
    return NULL;
}

/*apaga todas as memorias alocadas*/
void destroi_lista(){
    while(projeto2.head)
        destroi_contacto(projeto2.head);
}
