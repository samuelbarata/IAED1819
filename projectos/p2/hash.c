#include "hash.h"

/*inicializa uma hash table com "hash_size" nodes*/
void init_hash_table(hash_table *HT){
    int i;
    for(i=0;i<hash_size;i++){
        HT[i].head = NULL;
    }
}

/*devolve uma hash para cada objeto*/
unsigned int hashing(char *str){
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

void destroy_hashnodes(hash_table HThead){
    hash_node *head, *next;
    head = HThead.head;
    while(head){
        next = head->samehash_next;
        free(head);
        head = next;
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
            printf("\nhash%04d:",i);
        for(k=HT[i].head;k!=NULL;k=k->samehash_next){
            printf("\t%s",k->contacto->name);
        }
    }
    printf("\n");
}

void hash_push_nome(contact *contacto){
    unsigned int aux = hashing(contacto->name);
    hash_node *node = malloc(sizeof(node));
    node->contacto = contacto;
    node->samehash_next = HTname[aux].head;
    HTname[aux].head = node;
}

void hash_pop_contacto(contact *contacto){
    hash_node *node;
    unsigned int hash = hashing(contacto->name);
    node = encrontra_hash_node(contacto->name, HTname[hash]);
    delete_node(HTname[hash], node);
}

void delete_node(hash_table HT, hash_node *node){
    hash_node *atual, *aux;
    atual = HT.head;
    if(node == atual){
        HT.head = node->samehash_next;
        free(node);
        return ;
    }
    while(atual->samehash_next!=node){
        atual = atual->samehash_next;
    }
    aux = atual->samehash_next->samehash_next;
    free(atual->samehash_next);
    atual->samehash_next = aux;
}



contact *encontra_pessoa2(char *str){
    unsigned int hash = hashing(str);
    hash_node *aux = encrontra_hash_node(str, HTname[hash]);
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
