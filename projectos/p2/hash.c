#include "hash.h"

/*inicializa uma hash table com "hash_size" nodes*/
void init_hash_table(hash_table *HT){
    int i;
    for(i=0;i<hash_size;i++){
        HT[i].head = NULL;
    }
}

/*devolve uma hash para cada objeto*/
unsigned int hash(unsigned char *str){
    unsigned hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    return hash % hash_size;
}

/*Recbe uma hash table e uma hash e devolve a head da lista correspondente*/
hash_table *pointer_from_hash(int hash, hash_table (*HThead)){
    return (HThead + hash);
}

void delete_node(hash_table *head, hash_node *node){
    hash_node *atual, *aux;
    atual = head->head;
    if(node == atual){
        aux = atual->samehash_next;
        free(atual);
        head->head=aux;
        return ;
    }
    while(atual->samehash_next!=node){
        atual = atual->samehash_next;
    }
    aux = atual->samehash_next->samehash_next;
    /*free()*/
    free(atual->samehash_next);
    atual->samehash_next = aux;
    return ;
}

void destroy_hashnodes(hash_table HThead){
    hash_node *head, *next;
    head = HThead.head;
    next = head->samehash_next;
    while(head){
        free(head);
        head = next;
        next = head->samehash_next;
    }
}

void destroy_hashT(hash_table *HT){
    int i;
    for(i=0;i<hash_size;i++){
        destroy_hashnodes(HT[i]);
    }
}


void debug_hash(hash_table *HT){
    int i;
    hash_node *k;
    for(i=0;i<hash_size;i++){
        if(HT[i].head!=NULL)
            printf("hash%04d:",i);
        for(k=HT[i].head;k!=NULL;k=k->samehash_next){
            printf(" %s",k->contacto->name);
        }
        printf("\n");
    }
}

void hash_push_nome(contact *contacto){
    unsigned int aux = hash(contacto->name);
    hash_node *node = malloc(sizeof(node));
    node->contacto = contacto;
    node->samehash_next = HTname[aux].head;
    HTname[aux].head = node;
}

void hash_pop_nome(contact *contacto){

}

contact *encontra_pessoa2(contact *contacto){
    unsigned int hash = hash(contacto->name);
    return encrontra_nome2(contacto, HTname[hash]);
}

contact *encrontra_nome2(contact *contacto, hash_table HT){
    hash_node *atual = HT.head;
    while(atual){
        if(!strcmp(contacto->name, atual->contacto->name))
            return contacto;
        atual = atual->samehash_next;
    }
    return NULL;
}
