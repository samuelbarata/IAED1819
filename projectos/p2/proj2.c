#include "aux.h"


void adiciona_contacto(contact *);

int main(){
    /*lista de pointers para as variaveis globais 0-comando 1-nome
    2-local 3-dominio 4-telefone*/
    contact *pointer, *aux;
    projeto2.head = NULL;
    projeto2.tail = NULL;
    projeto2.num_contactos;
    while((scanf("%c", buffer.comando)),buffer.comando!='x'){
        switch (buffer.comando){
            case 'a':
                read_stdin(&buffer);
                aux = cria_contacto();
                verifica_erros(aux);
                printa_contacto(pointer);
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


void adiciona_contacto(contact *pointer){
    contact *contacto;
    contacto = cria_contacto();
}
