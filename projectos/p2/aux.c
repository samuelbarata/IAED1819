#include "aux.h"

contact *malloc_contacto(){
    contact *p;
    p = malloc(sizeof(contact));
    p->next = NULL;
    p->previous = NULL;
    return p;
}

void destroi_contacto(contact *p){
    if(p->previous)
        p->previous = p->next;
    if(p->next)
        p->next->previous = p->previous;
    free(p->name);
    free(p->local);
    free(p->dominio);
    free(p->phone);
    free(p);
}

void read_stdin(){
    if(buffer.comando == 'c')
        scanf("%s", buffer.dominio);
    else{
            scanf("%s", buffer.nome);
        if (buffer.comando == 'a' || buffer.comando == 'e'){
            scanf("%s", buffer.email);
            split_email(&buffer);
        }
        if (buffer.comando == 'a')
            scanf("%s", buffer.tel);
    }
}

void split_email(){
    char *p;
    p = buffer.email;
    while(p!='@')
        p++;
    strcpy(buffer.dominio,p);
    *p='\0';
    strcpy(buffer.local, buffer.email);
}

/*buffer -> contacto*/
contact *cria_contacto(){

}

void printa_contacto(contact *contacto){
    printf("%s %s%s %s\n",contacto->name,contacto->local,contacto->dominio,contacto->phone);
}
