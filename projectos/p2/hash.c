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

/*inicializa uma hash table com "hash_size" nodes a NULL*/
void init_hash_table(hash_table *HT){
    int i;
    for(i=0;i<hash_size;i++){
        HT[i].head = NULL;
    }
}

/*faz free de uma hash table*/
void destroy_hash_table(hash_table *HT, char c){
    int i;
    node_linked *aux;
    for(i=0;i<hash_size;i++){
        while(HT[i].head!=NULL){
            aux = HT[i].head->next;
            if(c=='d')/*caso receba um dominio tem de fazer free aos dominio*/
                destroi_dominio((dominio*)HT[i].head->data);
            free(HT[i].head);
            HT[i].head = aux;
        }
    }
    return;
}

/*encontra um node numa determinada hash table*/
node_linked *encontra(hash_table *HT, char *str){
    hash h = hasher(str);
    node_linked *atual = HT[h].head;
    while(atual){
        /*recebe contacto*/
        if(buffer.comando == 'a' || buffer.comando == 'p' || buffer.comando == 'r' || buffer.comando == 'e'){
            if(!strcmp(((contact *)atual->data)->name, str))
                return atual;
        }
        /*recebe dominio*/
        else{
            if (!strcmp(((dominio *)atual->data)->dom, str))
                return atual;
        }
        atual = atual->next;
    }
    return NULL;
}


/*recebe uma hash table e um contacto ou dominio e grava na hash table*/
void *push(hash_table *HT, void *objeto){
    contact *contacto;
    dominio *dom;
    node_linked *node, *aux;
    hash h;
    /*recebe um contacto*/
    if(buffer.comando == 'a'){
        h = hasher(((contact*)objeto)->name);
        contacto = (contact*)objeto;
        push_list(&adress_book, contacto); /*adiciona o contacto ao adressbook*/
    }
    /*recebe um dominio*/
    else{   /*comando == 'e'*/
        aux = encontra(HTdom, ((dominio *)objeto)->dom);
        if(aux){/*se o dominio existe incrementa*/
            destroi_dominio((dominio *)objeto);
            dom = ((dominio*)aux->data);
            dom->counter++;
            return (void*) dom;
        }
        h = hasher(((dominio *)objeto)->dom);
    }
    /*adiciona o node a hash table*/
    node = malloc(sizeof(node_linked));
    node->data = objeto;
    node->next = HT[h].head;
    HT[h].head = node;
    return node->data;
}

/*recebe um contacto ou dominio e remove da hash table*/
void pop(hash_table *HT, void *objeto){
    contact *contacto;
    dominio *dom;
    node_linked *atual, *node;
    hash h;
    /*recebe um contacto*/
    if(buffer.comando == 'r'){
        h = hasher(((contact *)objeto)->name);
        node = encontra(HTname, ((contact*)objeto)->name);
        contacto = (contact *)objeto;
        dom = contacto->dom;
        pop_list(&adress_book, contacto); /*remove e apaga o contacto do adress book*/
        buffer.comando='x'; /*para fazer pop de um dominio*/
        pop(HTdom, dom);
    }
    /*recebe um dominio*/
    else{
        dom = (dominio *)objeto;
        if (dom->counter>1){    /*se existir mais do que um dominio igual decrementa*/
            dom->counter--;
            return;
        }/*se e o unico dominio apaga-o*/
        node = encontra(HTdom, ((dominio *)objeto)->dom);
        h = hasher(((dominio *)objeto)->dom);
        destroi_dominio(dom);       /*apaga o dominio*/
    }
    atual = HT[h].head;
    if(node == atual){/*o node e o primeiro da linked list*/
        HT[h].head = atual->next;
        free(node);
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

/*compilar com -D DEBUG */
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
