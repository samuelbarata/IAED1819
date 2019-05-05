#include "aux.h"

void adiciona();
void lista();

int main(){
    contact *pointer, *aux;
    projeto2.head = NULL;
    projeto2.tail = NULL;
    projeto2.num_contactos;
    while((scanf("%c", &buffer.comando)),buffer.comando!='x'){
        switch (buffer.comando){
            case 'a':
                read_stdin();
                adiciona();
                printa_contacto(projeto2.tail);
                break;
            case 'l':
                lista();
                break;
            case 'p':
                read_stdin();
                procura();
                break;
            case 'r':
                break;
            case 'e':
                break;
            case 'c':
                break;
        }  
    }
    return 0;
}


void adiciona(){
    contact *contacto;
    contacto = cria_contacto();
    if (verifica_erros(contacto, projeto2.head)){
        printf("Nome existente.\n");
        destroi_contacto(contacto);
        return;
    }
    projeto2.num_contactos++;
    if(!projeto2.head){
        projeto2.head = contacto;
        projeto2.tail = contacto;
    }else{
        contacto->previous = projeto2.tail;
        projeto2.tail->next = contacto;
        projeto2.tail = contacto;
    }
}


void lista(){
    contact *contacto;
    contacto = projeto2.head;
    while(contacto != NULL){
        printa_contacto(contacto);
        contacto = contacto->next;
    }
}


void procura(){
    contact *contacto;
    contacto = projeto2.head;
    while(contacto != NULL){
        if(!strcmp(contacto->name, buffer.nome))
            break;
        contacto = contacto->next;
    }
    if(contacto)
        printa_contacto(contacto);
    else
        printf("Nome inexistente.\n");
}

