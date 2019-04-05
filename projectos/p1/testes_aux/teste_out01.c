#include "aux.h"

char randleter(){return 'A' + (random() % 26);}

/* descricao:data:inicio:duracao:sala:responsavel:participantes */
/*     0      1     2       3     4       5          6  7  8    */


e_sala tabela[max_sala];
char args[max_args][max_str]; /*memoria dos ultimos argumentos lidos no stdin*/

void read(){
    int i=0;
    char *aux, str[max_arg_str];
    getchar();                          /*elimina o espaco entre o comando e os args*/
    fgets(str, max_arg_str, stdin);
    aux = strtok(str, ":\n");
    while (aux != NULL){
        strcpy(args[i], aux);
        i++;
        aux = strtok(NULL, ":\n");
    }
}


void reset_evento(coordenada coor){
    int i = coor.room, k = coor.evendo_id;
    tabela[i].evento[k].status = 0;
    strcpy(tabela[i].evento[k].descricao , "");
    tabela[i].evento[k].dia.d = 0;
    tabela[i].evento[k].dia.m = 0;
    tabela[i].evento[k].dia.a = 0;
    tabela[i].evento[k].tempo = 0;
    tabela[i].evento[k].duracao = 0;
    strcpy(tabela[i].evento[k].participantes[3], "");
    strcpy(tabela[i].evento[k].participantes[0], "");
    strcpy(tabela[i].evento[k].participantes[1], "");
    strcpy(tabela[i].evento[k].participantes[2], "");
    tabela[i].total_eventos--;
    tabela[i].evento[k].abs_time = 0;
    tabela[i].evento[k].room = i;
}

void lista_evento(){
 /*
    <descricao> <data> <inicio> <duracao> Sala<sala> <responsavel>
    * <participante1> <participante2> <participante3>
*/
    printf("%s ", args[0]);
    printf("%s ",args[1]);
    printf("%s ", args[2]);
    printf("%s ", args[3]);
    printf("Sala%s ",args[4]);
    printf("%s\n",args[5]);
    printf("* %s", args[6]);
    printf(" %s", args[7]);
    printf(" %s", args[8]);
    printf("\n");
}


int main(){
    char cmd;   /*variavel onde a instrucao vai estar guradada*/
    int exit = 0;
    coordenada coor;
    /*inicializacao dos eventos*/
    for (coor.room = 0; coor.room < max_sala; coor.room++){
        for(coor.evendo_id = 0; coor.evendo_id < max_eventos; coor.evendo_id++){
            reset_evento(coor);
        }
        tabela[coor.room].total_eventos = 0;
    }

    while (!exit)
    {
        scanf("%c", &cmd);
        switch (cmd)
        {
        case 'a':
            read();
            lista_evento();
            break;
        case 'x':
            exit = 1;
            break;
        }
    }
    return 0;
}