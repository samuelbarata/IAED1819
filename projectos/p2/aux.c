/*╭─────────────────────────────────────────────╮
  │  File:  aux.c                               │
  │  Author:  Samuel Barata (94230)             │
  │  Description: Contem as funcoes auxiliares  │
  ╰─────────────────────────────────────────────╯
*/

#include "aux.h"


/*Aloca um contacto na memoria e devolve o seu ponteiro*/
contact *malloc_contacto(){
    contact *p;
    p = malloc(sizeof(contact));
    p->next = NULL;
    p->previous = NULL;
    return p;
}

/*recebe o endereço de um contacto e remove-o da memória e atualiza o "livro"*/
void destroi_contacto(contact *p){
    if(p->previous)
        p->previous->next = p->next;
    if(p->next)
        p->next->previous = p->previous;
    free(p->name);
    free(p->local);
    free(p->dominio);
    free(p->phone);
    if(p==projeto2.head)
        projeto2.head = p->next;
    else if(p==projeto2.tail)
        projeto2.tail = p->previous;
    free(p);
}

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

/*pega no email do buffer e divide-o em local/dominio*/
void split_email(){
    char *p;
    p = buffer.email;
    while(p[0]!='@')
        p++;
    strcpy(buffer.dominio, p);
    *p='\0';
    strcpy(buffer.local, buffer.email);
}

/*cria um contacto com os dados contidos no buffer*/
contact *cria_contacto(){
    contact *contacto;
    contacto = malloc_contacto();

    contacto->name = malloc(sizeof(char) * strlen(buffer.nome) + 1);
    strcpy(contacto->name, buffer.nome);

    contacto->local = malloc(sizeof(char) * strlen(buffer.local) + 1);
    strcpy(contacto->local, buffer.local);

    contacto->dominio = malloc(sizeof(char) * strlen(buffer.dominio) + 1);
    strcpy(contacto->dominio, buffer.dominio);

    contacto->phone = malloc(sizeof(char) * strlen(buffer.tel) + 1);
    strcpy(contacto->phone, buffer.tel);

    return contacto;
}

/*imprime um contacto recebendo o seu endereço de memória*/
void printa_contacto(contact *contacto){
    printf("%s %s%s %s\n",
    contacto->name,contacto->local,contacto->dominio,contacto->phone);
}

/*contacto e o recebido
a_comparar percorre a lista toda (primeira chamada deve conter head para
percorrer a lista toda até ao fim)
recursiva*/
int verifica_erros(contact *contacto, contact *a_comparar){
    if(!a_comparar)
        return 0;
    if(!strcmp(contacto->name, a_comparar->name))
        return 1;
    return verifica_erros(contacto,a_comparar->next);
}

/*devolve o endereco de memoria do contacto cujo nome está no buffer*/
contact *encrontra_nome(){
    contact *contacto;
    contacto = projeto2.head;
    while(contacto){
        if(!strcmp(contacto->name, buffer.nome))
            break;
        contacto = contacto->next;
    }
    return contacto;
}

/*apaga todas as memorias alocadas*/
void destroi_lista(){
    while(projeto2.head)
        destroi_contacto(projeto2.head);
}
