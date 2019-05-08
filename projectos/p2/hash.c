#include "hash.h"

/*inicializa uma hash table com "hash_size" nodes*/
void init_hash_table(hash_table *HT){
    int i;
    for(i=0;i<hash_size;i++){
        HT[i].head = NULL;
    }
}

/*devolve uma hash para cada objeto*/
hash hasher(char *str){
    hash me = 5381;
    int c;
    while ((c = *str++))
        me = ((me << 5) + me) + c; /* hash * 33 + c */
    return me % hash_size;
}

/*Recbe uma hash table e uma hash e devolve a head da lista correspondente*/
hash_table *pointer_from_hash(int me, hash_table (*HThead)){
    return (HThead + me);
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
            /*printf("\t%p:",(void *)k);*/
            printf("%s",k->contacto->name);
        }
    }
    printf("\n");
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
dominio *hash_push_dominio(char *str){
    hash me = hasher(str);
    dominio *dom = malloc();
    return dom;
}
