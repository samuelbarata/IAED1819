#include "ex03aux.h"

void ht_init(node **tab, unsigned long int m);            /* inicializa a tabela */
void ht_reset(node **tab, unsigned long int m);           /* apaga todos os elementos da tabela */
void ht_add(node **tab, unsigned long int m, char *s);    /* adiciona a string s à tabela */
void ht_delete(node **tab, unsigned long int m, char *s); /* apaga a string s da tabela */
int ht_exists(node **tab, unsigned long int m, char *s);  /* retorna diferente de 0 se s estiver na tabela*/
static unsigned long djb2(char * str);


#define SIZE 737

unsigned int hash(char *str)
{
    unsigned int h = 5437;
    int times = 0;

    while (*str && times < 3)
    {
        h = h * 31 + *str;
        times++;
        str++;
    }

    return h;
}

int main()
{

    node *hashtable[SIZE];
    char str[SIZE];
    int h, i;

    for (i = 0; i < SIZE; i++)
        hashtable[i] = NULL;

    scanf("%s", str);
    while (strcmp(str, "EXIT"))
    {
        h = hash(str) % SIZE;

        if (hashtable[h] == NULL)
            hashtable[h] = mk_list();

        add_last(hashtable[h], str);
        scanf("%s", str);
    }

    printf("introduza o prefixo\n");
    scanf("%s", str);

    h = hash(str) % SIZE;
    print(hashtable[h]);

    return 0;
}
