#include "ex03aux.h"

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

void ht_init(node **tab, unsigned long int m);            /* inicializa a tabela */
void ht_reset(node **tab, unsigned long int m);           /* apaga todos os elementos da tabela */
void ht_add(node **tab, unsigned long int m, char *s);    /* adiciona a string s à tabela */
void ht_delete(node **tab, unsigned long int m, char *s); /* apaga a string s da tabela */
int ht_exists(node **tab, unsigned long int m, char *s);  /* retorna diferente de 0 se s estiver na tabela*/
static unsigned long djb2(char * str);

int main(){
    node **table = NULL;
    /*hash m = hash_size;
    ht_init(table, m); /* inicializa a tabela */
    while (1){
        
        printf("%sIsto e complicadissimo\nnao percebo o q sao estes parametros todos nas funcoes\nbtw, parem o programa ou ficam sem ram [^C]%s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
        table = malloc(200000);
    }
    return 0;
}

static unsigned long djb2(char * str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    return hash%hash_size;
}

void ht_init(node **tab, unsigned long int m){
    unsigned int i;
    for(i=0;i<m;i++){
        tab[i] = malloc(sizeof(node*));
        tab[i] = NULL;
    }
}

void ht_delete(node **tab, unsigned long int m, char *s){
    hash h = djb2(s);
    if(ht_exists(tab, m, s)){
        if(!strcmp(s, tab[h]->s))
            free(tab[h]->s);

    }
    else
        printf("n existe\n");
}

int ht_exists(node **tab, unsigned long int m, char *s){
    return 1;    
}
