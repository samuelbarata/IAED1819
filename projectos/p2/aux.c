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
    if(p==projeto2.head)
        projeto2.head = p->next;
    else if(p==projeto2.tail)
        projeto2.tail = p->previous;
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
    while(p[0]!='@')
        p++;
    strcpy(buffer.dominio,p);
    *p='\0';
    strcpy(buffer.local, buffer.email);
}

/*buffer -> contacto*/
contact *cria_contacto(){
    contact *contacto;
    contacto = malloc(sizeof(contact));

    contacto->next = NULL;
    contacto->previous = NULL;

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

void printa_contacto(contact *contacto){
    printf("%s %s%s %s\n",contacto->name,contacto->local,contacto->dominio,contacto->phone);
}

int verifica_erros(contact *contacto, contact *a_comparar){
    if(a_comparar==NULL)
        return 0;
    if(!strcmp(contacto->name, a_comparar->name))
        return 1;
    return verifica_erros(contacto,a_comparar->next);
}

contact *encontra_nome(){
    contact *contacto;
    contacto = projeto2.head;
    while(contacto != NULL){
        if(!strcmp(contacto->name, buffer.nome))
            break;
        contacto = contacto->next;
    }
    return contacto;
}

