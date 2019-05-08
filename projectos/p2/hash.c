#include "hash.h"

/*inicializa uma hash table com "hash_size" nodes*/
void init_hash_table(){
    int i;
    for(i=0;i<hash_size;i++){
        HTname[i].head = NULL;
    }
}

/*devolve uma hash para cada objeto*/
/*http://www.cse.yorku.ca/~oz/hash.html*/
hash hasher(char *str){
    hash me = 5381;
    int c;
    while ((c = *str++))
        me = ((me << 5) + me) + c; /* hash * 33 + c */
    return me % hash_size;
}

void destroy_hashnodes(hash_table HThead){
    hash_node *head, *next;
    head = HThead.head;
    while(head){
        next = head->samehash_next;
        free(head);
        head = next;
    }
}

void destroy_hashT(){
    int i;
    for(i=0;i<hash_size;i++){
        destroy_hashnodes(HTname[i]);
    }
}

void hash_push_nome(contact *contacto){
    hash aux = hasher(contacto->name);
    hash_node *node = malloc(sizeof(hash_node));
    node->contacto = contacto;
    node->samehash_next = HTname[aux].head;
    HTname[aux].head = node;
}

void hash_pop_contacto(contact *contacto){
    hash_node *node;
    hash me = hasher(contacto->name);
    node = encrontra_hash_node(contacto->name, HTname[me]);
    delete_node(HTname, node, me);
}

void delete_node(hash_table *HT, hash_node *node, hash me){
    hash_node *atual;
    atual = HT[me].head;
    if(node == atual){
        HT[me].head = node->samehash_next;
        free(node);
        return ;
    }
    while(atual->samehash_next!=node){
        atual = atual->samehash_next;
    }
    atual->samehash_next = node->samehash_next;
    free(node);
}



contact *encontra_pessoa2(char *str){
    hash me = hasher(str);
    hash_node *aux = encrontra_hash_node(str, HTname[me]);
    if(aux)
        return aux->contacto;
    return NULL;
}

hash_node *encrontra_hash_node(char *str, hash_table HT){
    hash_node *atual = HT.head;
    while(atual){
        if(!strcmp(str, atual->contacto->name))
            return atual;
        atual = atual->samehash_next;
    }
    return NULL;
}

/*DOMINIOS*/
void init_hash_dominio(){
    int i;
    for(i=0;i<hash_size;i++){
        HDom[i].dom = NULL;
    }
}
void destroy_hashD(){
    int i;
    for(i=0;i<hash_size;i++){
        destroy_nodes(HDom[i]);
    }
}
void destroy_nodes(hash_dominio HDom){
    dominio *head, *next;
    head = HDom.dom;
    while(head){
        next = head->samehash_next;
        free(head->dom);
        free(head);
        head = next;
    }
}

dominio *hash_push_dominio(char *str){
    hash me = hasher(str);
    dominio *dom = hash_find_dom(str);
    if(dom){
        dom->counter++;
        return dom;
    }
    dom = malloc(sizeof(dominio));
    dom->dom = malloc(sizeof(char)*strlen(str)+1);
    strcpy(dom->dom, str);
    dom->counter = 1;
    dom->samehash_next = HDom[me].dom;
    HDom[me].dom = dom;
    return dom;
}

void hash_pop_dominio(dominio *dom){
    dom->counter--;
    if(!dom->counter)
        delete_dom(dom);
}

void delete_dom(dominio *dom){
    hash me = hasher(dom->dom);
    dominio *head = HDom[me].dom, *atual;
    atual = head;
    if(dom == atual){
        HDom[me].dom = dom->samehash_next;
        free(dom->dom);
        free(dom);
        return ;
    }
    while(atual->samehash_next != dom){
        atual = atual->samehash_next;
    }
    atual->samehash_next = dom->samehash_next;
    free(dom);
}

dominio *hash_find_dom(char *str){
    hash me = hasher(str);
    dominio *head = HDom[me].dom, *atual = head;
    while(atual){
        if (!strcmp(str, atual->dom))
            return atual;
        atual = atual->samehash_next;
    }
    return NULL;
}

/*╭──────────────────────────────────────┬─────┬─────────────────────────────────────────╮
  │                                       DEBUG                                          │
  ╰──────────────────────────────────────┴─────┴─────────────────────────────────────────╯*/

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
