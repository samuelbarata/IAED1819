/*╭─────────────────────────────────────────────╮
  │  File:  proj1.c                             │
  │  Author:  Samuel Barata (94230)             │
  │  Description: Contem as funcoes principais  │
  ╰─────────────────────────────────────────────╯
*/

#include "aux.h"

/*╭─────────────────────────────────────┬───────┬────────────────────────────────────────╮
  │                                      Funcoes                                         │
  ╰─────────────────────────────────────┴───────┴────────────────────────────────────────╯*/

void adiciona();    /*adiciona um evento ao livro de contactos*/
void lista();       /*lista os contactos por ordem de registo*/
void remove_c();    /*remove um contacto dado um nome*/
void altera_e();    /*altera o email de um contacto dado um nome*/
void procura();     /*procura um contacto dado um nome*/
void cont_dom();    /*conta todos os email com um dado dominio*/

/*╭───────────────────────────────────────┬────┬─────────────────────────────────────────╮
  │                                        main                                          │
  ╰───────────────────────────────────────┴────┴─────────────────────────────────────────╯*/

int main(){
    projeto2.head = NULL;   /*inicializa o livro de contactos como vazio*/
    projeto2.tail = NULL;
    while((scanf("%c", &buffer.comando)),buffer.comando!='x'){
        switch (buffer.comando){
            case 'a':
                read_stdin();
                adiciona();
                break;
            case 'l':
                lista();
                break;
            case 'p':
                read_stdin();
                procura();
                break;
            case 'r':
                read_stdin();
                remove_c();
                break;
            case 'e':
                read_stdin();
                altera_e();
                break;
            case 'c':
                read_stdin();
                cont_dom();
                break;
        }  
    }
    /*liberta toda a memoria ainda alocada*/
    destroi_lista();
    return 0;
}

/*╭────────────────────────────────┬──────────────────┬──────────────────────────────────╮
  │                                 Funcoes Principais                                   │
  ╰────────────────────────────────┴──────────────────┴──────────────────────────────────╯*/

/**/
void adiciona(){
    contact *contacto;
    contacto = cria_contacto();
    if (verifica_erros(contacto, projeto2.head)){
        printf("Nome existente.\n");
        destroi_contacto(contacto);
        return;
    }
    if(!projeto2.head){
        projeto2.head = contacto;
        projeto2.tail = contacto;
    }else{
        contacto->previous = projeto2.tail;
        projeto2.tail->next = contacto;
        projeto2.tail = contacto;
    }
}

/**/
void lista(){
    contact *contacto;
    contacto = projeto2.head;
    while(contacto != NULL){
        printa_contacto(contacto);
        contacto = contacto->next;
    }
}

/**/
void procura(){
    contact *contacto;
    contacto = encrontra_nome();
    if(contacto)
        printa_contacto(contacto);
    else
        printf("Nome inexistente.\n");
}

/**/
void remove_c(){
    contact *contacto;
    contacto = encrontra_nome();
    if(contacto)
        destroi_contacto(contacto);
    else
        printf("Nome inexistente.\n");
}

/**/
void altera_e(){
    contact *contacto;
    contacto = encrontra_nome();
    if (contacto){
        contacto->local = realloc(contacto->local, sizeof(char)*strlen(buffer.local)+1);
        contacto->dominio = realloc(contacto->dominio, sizeof(char) * strlen(buffer.dominio) + 1);
        strcpy(contacto->local, buffer.local);
        strcpy(contacto->dominio, buffer.dominio);
    }
    else
        printf("Nome inexistente.\n");
}

/**/
void cont_dom(){
    unsigned long int contador = 0;
    contact *contacto;
    char *dom;
    contacto = projeto2.head;
    while(contacto != NULL){
        dom = contacto->dominio;
        dom++;
        if(!strcmp(dom, buffer.dominio))
            contador++;
        contacto = contacto->next;
    }
    printf("%s:%lu\n", buffer.dominio, contador);
}
