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

//void destroy_hash_table(hash_table *HT){
//    return;
//}

node_linked *encontra(hash_table *HT, char *str){
    hash h = hasher(str);
    node_linked *atual = HT[h].head;
    while(atual){
        if(buffer.comando == 'a' | buffer.comando == 'p' | buffer.comando == 'r' | buffer.comando == 'e'){
            if(!strcmp(((contact *)atual->data)->name, str))
                return atual->data;
        }
        else{
            if (!strcmp(((dominio *)atual->data)->dom, str))
                return atual->data;
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
        contacto = encontra(HTname, ((contact*)objeto))->data;
        /*  criar/incrementar o dominio         */
        dom = encontra(HTdom, buffer.dominio);
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
        push_list(adress_book, contacto);
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

/*Imprime um esquema das hashes*/
void debug_hash_n(){
    int i;
    hash_node *k;
    printf("\nName Hash Table:\n");
    for(i=0;i<hash_size;i++){
        if(HTname[i].head!=NULL)
            printf("\nhash%04d:",i);
        for(k=HTname[i].head;k!=NULL;k=k->samehash_next){
            printf(" %s",k->contacto->name);
        }
    }
    printf("\n");
}

/*Imprime um esquema das hashes*/
void debug_hash_d(){
    int i;
    dominio *k;
    printf("\n\nDomain Hash Table:\n");
    for(i=0;i<hash_size;i++){
        if(HDom[i].dom!=NULL)
            printf("\nhash%04d:",i);
        for(k=HDom[i].dom;k!=NULL;k=k->samehash_next){
            printf(" %s:%u",k->dom, k->counter);
        }
    }
    printf("\n");
}
