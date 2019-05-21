/*╭─────────────────────────────────────────────╮
  │  File:  proj2.c                             │
  │  Author:  Samuel Barata (94230)             │
  │  Description: Contem as funcoes principais  │
  ╰─────────────────────────────────────────────╯
*/

#include "estruturas.h"
#include "aux.h"
#include "hash.h"

/*╭─────────────────────────────────────┬───────┬────────────────────────────────────────╮
  │                                      Funcoes                                         │
  ╰─────────────────────────────────────┴───────┴────────────────────────────────────────╯
*/

void adiciona();    /*adiciona um evento ao livro de contactos*/
void lista();       /*lista os contactos por ordem de registo*/
void remove_c();    /*remove um contacto dado um nome*/
void altera_e();    /*altera o email de um contacto dado um nome*/
void procura();     /*procura um contacto dado um nome*/
void cont_dom();    /*conta todos os email com um dado dominio*/
void prefixo();

/*╭───────────────────────────────────────┬────┬─────────────────────────────────────────╮
  │                                        main                                          │
  ╰───────────────────────────────────────┴────┴─────────────────────────────────────────╯
*/

int main(){
    init_adress_book(&adress_book);
    init_hash_table(HTname);
    init_hash_table(HTdom);
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
            case 'P':
                read_stdin();
                prefixo();
                break;
            #ifdef DEBUG
                case 'd':  /*adicionar -D DEBUG no compilador*/
                    /*mostra esquema hash*/
                    scanf("%c", &buffer.comando); /*d = dom; n = names*/
                    debug_hash(buffer.comando);
                    break;
            #endif
        }  
    }
    /*liberta toda a memoria ainda alocada*/
    destroy_adress_book(&adress_book);
    destroy_hash_table(HTname);
    destroy_dominios(HTdom);
    destroy_hash_table(HTdom);
    return 0;
}

/*╭────────────────────────────────┬──────────────────┬──────────────────────────────────╮
  │                                 Funcoes Principais                                   │
  ╰────────────────────────────────┴──────────────────┴──────────────────────────────────╯
*/

/*cria contacto e dominio a partir dos dados do buffer*/
void adiciona(){
    contact *contacto;
    dominio *dom;
    contacto = cria_contacto();
    contacto = adiciona_aux(contacto);
    contacto = push(HTname, contacto);

    buffer.comando='x';
    dom = cria_dominio(buffer.dominio);
    contacto->dom = push(HTdom, dom);
}

/*imprime todos os contactos por ordem de adicao*/
void lista(){
    contact *contacto;
    contacto = adress_book.head;
    while(contacto){
        printa_contacto(contacto);
        contacto = contacto->next;
    }
}

/*procura uma pessoa e se encontrar imprime o seu contacto*/
void procura(){
    contact *contacto;
    node_linked *node = encontra(HTname, buffer.nome);
    if(node){
        contacto = ((contact *)node->data);
        printa_contacto(contacto);
    }
    else
        printf("Nome inexistente.\n");
}

/*se o contacto existir apaga-o*/
void remove_c(){
    contact *contacto;
    node_linked *node = encontra(HTname, buffer.nome);
    if(node){
        contacto = ((contact *)(node->data));
        pop(HTname, contacto);
    }
    else
        printf("Nome inexistente.\n");
}

/*altera o email dado no buffer se a pessoa existir*/
void altera_e(){
    contact *contacto;
    dominio *dom;
    node_linked *node = encontra(HTname, buffer.nome);
    if(node){
        contacto = ((contact *)(node->data));
        contacto->local = realloc(contacto->local, sizeof(char) * strlen(buffer.local)+1);
        strcpy(contacto->local, buffer.local);
        dom = contacto->dom;
        pop(HTdom, dom);
        dom = cria_dominio(buffer.dominio);
        contacto->dom=push(HTdom, dom);
    }
    else
        printf("Nome inexistente.\n");
}

/*recebe um dominio no buffer e conta o numero de email com o mesmo dominio*/
void cont_dom(){
    dominio *dom;
    node_linked *node = encontra(HTdom, buffer.dominio);
    unsigned int counter = 0;
    if(node){
        dom = ((dominio *)node->data);
        counter = dom->counter;
    }
    printf("%s:%u\n", buffer.dominio, counter);
}

void prefixo(){
    int contador=0;
    contact *contacto;
    contacto = adress_book.head;
    while(contacto){
        contador += prefixo_aux(contacto);
        contacto = contacto->next;
    }
    printf("%s:%d\n", buffer.nome, contador);
}
