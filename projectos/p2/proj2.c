/*╭─────────────────────────────────────────────╮
  │  File:  proj1.c                             │
  │  Author:  Samuel Barata (94230)             │
  │  Description: Contem as funcoes principais  │
  ╰─────────────────────────────────────────────╯
*/

#include "estruturas.h"
#include "aux.h"
#include "hash.h"

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
    init_hash_dominio(HDom);
    init_hash_table(HTname);
    projeto2.head = NULL; /*inicializa o livro de contactos como vazio*/
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
            case 'd':
                debug_hash(HTname);
                break;
        }  
    }
    /*liberta toda a memoria ainda alocada*/
    destroi_lista();
    destroy_hashT(HTname);
    destroy_hashD(HDom);
    return 0;
}

/*╭────────────────────────────────┬──────────────────┬──────────────────────────────────╮
  │                                 Funcoes Principais                                   │
  ╰────────────────────────────────┴──────────────────┴──────────────────────────────────╯*/

/*o buffer contem a informacao do contacto;
cria contacto;
copia os campos;
verifica para erros
adiciona ao "livro" ou apaga*/
void adiciona(){
    contact *contacto;
    contacto = cria_contacto();
    if (encontra_pessoa2(contacto->name)){
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
    hash_push_nome(contacto);
    contacto->dom = hash_push_dominio(buffer.dominio);
}

/*imprime todos os contactos por ordem de adicao*/
void lista(){
    contact *contacto;
    contacto = projeto2.head;
    while(contacto){
        printa_contacto(contacto);
        contacto = contacto->next;
    }
}

/*procura uma pessoa e se encontrar imprime o seu contacto*/
void procura(){
    contact *contacto;
    contacto = encontra_pessoa2(buffer.nome);
    if(contacto)
        printa_contacto(contacto);
    else
        printf("Nome inexistente.\n");
}

/*se o contacto existir apaga-o*/
void remove_c(){
    contact *contacto;
    contacto = encontra_pessoa2(buffer.nome);
    if(contacto){
        hash_pop_contacto(contacto);
        hash_pop_dominio(contacto->dom);
        destroi_contacto(contacto);
    }
    else
        printf("Nome inexistente.\n");
}

/*altera o email dado no buffer se a pessoa existir*/
void altera_e(){
    contact *contacto;
    dominio *dom;
    contacto = encontra_pessoa2(buffer.nome);
    if(contacto){
        contacto->local = realloc(contacto->local, sizeof(char) * strlen(buffer.local)+1);
        strcpy(contacto->local, buffer.local);

        dom = contacto->dom;
        hash_pop_dominio(dom);
        contacto->dom = hash_push_dominio(buffer.dominio);
    }
    else
        printf("Nome inexistente.\n");
}

/*recebe um dominio no buffer e conta o numero de email com o mesmo dominio*/
void cont_dom(){
    dominio *dom = hash_find_dom(buffer.dominio);
    unsigned int counter = 0;
    if(dom)
        counter = dom->counter;
    printf("%s:%u\n", buffer.dominio, counter);
}
