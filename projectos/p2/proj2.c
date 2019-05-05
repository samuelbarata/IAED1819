#include "aux.h"

void adiciona_contacto();
void lista_contactos();

int main(){
    /*lista de pointers para as variaveis globais 0-comando 1-nome
    2-local 3-dominio 4-telefone*/
    contact *pointer, *aux;
    projeto2.head = NULL;
    projeto2.tail = NULL;
    projeto2.num_contactos;
    while((scanf("%c", &buffer.comando)),buffer.comando!='x'){
        switch (buffer.comando){
            case 'a':
                read_stdin(&buffer);
                adiciona_contacto();
                printa_contacto(projeto2.tail);
                break;
            case 'l':
                break;
            case 'p':
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


void adiciona_contacto(){
    contact *contacto;
    contacto = cria_contacto();
    if (verifica_erros(contacto, projeto2.head)){
        printf("erro\n");
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


void lista_contactos(){
    contact *contacto;
    contacto = projeto2.head;
    while(contacto != NULL){
        printa_contacto(contacto);
        contacto = contacto->next;
    }
}