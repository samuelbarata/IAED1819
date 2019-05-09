#include "hash.h"

/*devolve uma hash para cada objeto [max = hash_size]*/
/*http://www.cse.yorku.ca/~oz/hash.html*/
hash hasher(char *str){
    hash me = 5381;
    int c;
    while ((c = *str++))
        me = ((me << 5) + me) + c; /* hash * 33 + c */
    return me % hash_size;
}

/*HASH TABLES*/

/*inicializa uma hash table com "hash_size" nodes a NULL*/
void init_hash_table(hash_table *HT){
    int i;
    for(i=0;i<hash_size;i++){
        HT[i].head = NULL;
    }
}

void destroy_hash_table(hash_table *HT){
    return;
}

node_linked *encontra(hash_table *HT, char *str){
    hash h = hasher(str);
    node_linked *atual = HT[h].head;
    while(atual){
        if(buffer.comando == 'a' | buffer.comando == 'p' | buffer.comando == 'r' | buffer.comando == 'e'){
            if(!strcmp(((contact *)atual->data)->name, str))
                return atual;
        }
        else{
            if (!strcmp(((dominio *)atual->data)->dom, str))
                return atual;
        }
        atual = atual->next;
    }
    return NULL;
}


/*recebe uma hash table e um contacto ou dominio e grava na hash table*/
void push(hash_table *HT, void *objeto){
    contact *contacto;
    dominio *dom;
    node_linked *node = malloc(sizeof(node_linked));
    hash h;
    if(buffer.comando == 'a'){
        h = hasher(((contact*)objeto)->name);
        contacto = (contact*)objeto;
        /*  criar/incrementar o dominio         */
        dom = (dominio*)encontra(HTdom, buffer.dominio);
        if(dom)
            dom->counter++;
        else{
            dom = cria_dominio(buffer.dominio);
            /*gravar dominio*/
            buffer.comando='x';
            push(HTdom, dom);
        }
        /*                                      */
        contacto->dom = dom;
        push_list(&adress_book, contacto);
    }
    else{   /*comando == 'e'*/
        h = hasher(((dominio *)objeto)->dom);
    }
    node->data = objeto;
    node->next = HT[h].head;
    HT[h].head = node;
}

/*recebe um contacto ou dominio e remove da hash table*/
void pop(hash_table *HT, void *objeto){
    contact *contacto;
    dominio *dom;
    node_linked *atual, *node;
    hash h;
    if(buffer.comando == 'r'){
        h = hasher(((contact *)objeto)->name);
        node = encontra(HTname, ((contact*)objeto)->name);
        contacto = (contact *)objeto;
        dom = contacto->dom;
        destroi_contacto(contacto); /*apaga o contacto*/
        pop(HTdom, dom);
    }
    else{   /*comando e*/
        dom = (dominio *)objeto;
        if (dom->counter>1){
            dom->counter--;
            return;
        }
        node = encontra(HTdom, ((dominio *)objeto)->dom);
        h = hasher(((dominio *)objeto)->dom);
        destroi_dominio(dom);       /*apaga o dominio*/
    }
    atual = HT[h].head;
    if(node == atual){
        HT[h].head = atual->next;
        free(node);                 /*apaga o node*/
        return;
    }
    while(atual->next != node){
        atual=atual->next;
    }
    atual->next = node->next;
    free(node);
}



/*╭──────────────────────────────────────┬─────┬─────────────────────────────────────────╮
  │                                       DEBUG                                          │
  ╰──────────────────────────────────────┴─────┴─────────────────────────────────────────╯
*/

#ifdef DEBUG

/*Imprime um esquema das hashes*/
void debug_hash(char c){
    int i;
    node_linked *k;
    hash_table *HT;
    switch(c){
        case 'd':
            HT=HTdom;
            break;
        case 'n':
            HT=HTname;
            break;
        default:
            return;
    }
    printf("\nHash Table:\n");
    for(i=0;i<hash_size;i++){
        if(HT[i].head!=NULL)
            printf("\nhash%04d:",i);
        for(k=HT[i].head;k!=NULL;k=k->next){
            if(c=='d')
                printf(" %s", ((dominio *)k->data)->dom);
            else
                printf(" %s", ((contact *)k->data)->name);
        }
    }
    printf("\n");
}
#endif
