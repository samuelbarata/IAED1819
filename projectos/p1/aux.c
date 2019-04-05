/*╭─────────────────────────────────────────────╮
  │  File:  aux.c                               │
  │  Author:  Samuel Barata (94230)             │
  │  Description: Contem as funcoes auxiliares  │
  ╰─────────────────────────────────────────────╯
*/

#include "aux.h"

/*le os argumentos do stdin para a variavel global args searados pelos :*/
void read(){
    int i = 0;
    char *aux, str[max_arg_str];
    getchar(); /*elimina o espaco entre o comando e os args*/
    fgets(str, max_arg_str, stdin);
    aux = strtok(str, ":\n");
    while (aux != NULL){
        strcpy(args[i++], aux);
        aux = strtok(NULL, ":\n");
    }
}

/*recebe a coordenada de um evento e escreve-o*/
void lista_evento(coordenada coor){
    /* 
    <descricao> <data> <inicio> <duracao> Sala<sala> <responsavel>
    * <participante1>[ <participante2>][ <participante3>]*/
    int horas, minutos;
    horas = sala[coor.room].evento[coor.evendo_id].tempo / 60;
    minutos = sala[coor.room].evento[coor.evendo_id].tempo % 60;
    printf("%s ", sala[coor.room].evento[coor.evendo_id].descricao);
    printf("%02d%02d%04d ", sala[coor.room].evento[coor.evendo_id].dia.d, sala[coor.room].evento[coor.evendo_id].dia.m,
           sala[coor.room].evento[coor.evendo_id].dia.a);
    printf("%02d%02d ", horas, minutos);
    printf("%d ", sala[coor.room].evento[coor.evendo_id].duracao);
    printf("Sala%d ", coor.room + 1);
    printf("%s\n", sala[coor.room].evento[coor.evendo_id].participantes[0]);
    printf("* %s", sala[coor.room].evento[coor.evendo_id].participantes[1]);
    if (strcmp(sala[coor.room].evento[coor.evendo_id].participantes[2], ""))
        printf(" %s", sala[coor.room].evento[coor.evendo_id].participantes[2]);
    if (strcmp(sala[coor.room].evento[coor.evendo_id].participantes[3], ""))
        printf(" %s", sala[coor.room].evento[coor.evendo_id].participantes[3]);
    printf("\n");
}

/*ddmmaaaa --> day;*/
/*recebe uma string do tipo ddmmaaaa e converte para a estrutura day*/
day get_day(char arg[]){
    day dia;
    dia.d = char_to_int(arg[0]) * 10 + char_to_int(arg[1]);
    dia.m = char_to_int(arg[2]) * 10 + char_to_int(arg[3]);
    dia.a = char_to_int(arg[4]) * 1000 + char_to_int(arg[5]) * 100 + char_to_int(arg[6]) * 10 + char_to_int(arg[7]);
    return dia;
}

/*hhmm --> int min*/
/*recebe uma string hhmm e converte para minutos*/
int get_time(char arg[]){
    int aux = str_to_int(arg);
    /*       minutos         horas       */
    return (aux % 100) + ((aux / 100) * 60);
}

/*recebe uma sala e ordena os respetivos eventos*/
void sort_inroom(int room){
    int i, k, index_min;
    unsigned long int aux1 = 0, aux2 = 0;
    for (i = 0; i < sala[room].total_eventos; i++){
        index_min = i;
        aux1 = sala[room].evento[i].abs_time;
        aux2 = sala[room].evento[i].tempo;
        for (k = i + 1; k < sala[room].total_eventos; k++){
            /*verifica se o evento a comparar ocorre antes do evento menor anterior*/
            if (aux1 > sala[room].evento[k].abs_time ||
            (aux1 == sala[room].evento[k].abs_time && aux2 > sala[room].evento[k].tempo)){
                aux1 = sala[room].evento[k].abs_time;
                aux2 = sala[room].evento[k].tempo;
                index_min = k;
            }
        }
        if (index_min != i)
            swap(sala[room].evento[i], sala[room].evento[index_min]);
    }
}

/*recebe as coordenadas de um evento, inativa-o, reduz a contagem de eventos dessa sala 
e mete troca o ultimo evento dessa sala para ocupar o seu lugar*/
void reset_evento(coordenada coor){
    int i = coor.room, k = coor.evendo_id;
    sala[i].evento[k].status = 0;
    sala[i].total_eventos--;
    sala[i].evento[k].room = i;
    if (sala[i].total_eventos > 0)
        swap(sala[i].evento[k], sala[i].evento[sala[i].total_eventos]);
}

/*recebe a descricao de um evento e devolve as coordenadas (sala, id) do mesmo, 
se devolver (100,100) o evento nao existe*/
coordenada encontra_evento(char descricao[]){
    int room, i;
    coordenada res;
    res.evendo_id = 100;
    res.room = 100;
    for (room = 0; room < max_sala; room++)
        for (i = 0; i < sala[room].total_eventos; i++)
            if (!strcmp(descricao, sala[room].evento[i].descricao))
            {
                res.room = room;
                res.evendo_id = i;
                return res;
            }
    return res;
}

/*verifica se 2 eventos ocorrem ao mesmo tempo; 0 = compativeis, !0 = incompativeis*/
int incompatibilidade_eventos(e_eventos original, e_eventos novo){
    int inicio1, inicio2, fim1, fim2;
    inicio1 = original.tempo;
    fim1 = inicio1 + original.duracao;
    inicio2 = novo.tempo;
    fim2 = inicio2 + novo.duracao;
    /*Se o evento ocorre no mesmo dia*/
    if (original.dia.a == novo.dia.a && original.dia.m == novo.dia.m && original.dia.d == novo.dia.d){
        if (inicio2 >= fim1)
            return 0;
        if (fim2 <= inicio1)
            return 0;
        return 1;
    }
    return 0;
}

/*devolve 1 se a "pessoa" estiver no evento "novo" e 0 caso contrario*/
int same_pessoa(char pessoa[], e_eventos novo){
    int k;
    for (k = 0; k < max_part; k++){
        if (!strcmp(pessoa, novo.participantes[k])){
            if (!strcmp(novo.participantes[k], ""))
                return 0;
            return 1;
        }
    }
    return 0;
}

/*recebe uma string e converte em inteiro*/
int str_to_int(char *str){
    int i, res = 0;
    for (i = 0; str[i] != '\0'; i++)
        res = res * 10 + char_to_int(str[i]);
    return res;
}

/*recebe um char e converte em inteiro*/
int char_to_int(char x){
    return x - '0';
}

/*recebe um evento e calcula o seu "tempo absoluto", este 
tempo e utilizado para fazer as ordenacoes dos eventos*/
unsigned long int calcula_abs(e_eventos arg){
    int dia, mes, ano;
    ano = arg.dia.a - 2019;
    mes = arg.dia.m;
    dia = arg.dia.d;
    return (dia) + (mes * 100) + (ano * 10000);
}

/*verifica se uma pessoa tem outro evento ao mesmo tempo*/
int verifica_pessoas(e_eventos teste, char f_call){
    int j, evt_a_cmp, k, erro = 0;
    for (j = 0; j < max_sala; j++)
        /*percorre os eventos dessa sala*/
        for (evt_a_cmp = 0; evt_a_cmp < sala[j].total_eventos; evt_a_cmp++)
            if (incompatibilidade_eventos(sala[j].evento[evt_a_cmp], teste))
                /*verifica se e o prorpio evento, se absoluto == 0*/
                if (!same_evento(sala[j].evento[evt_a_cmp], teste))
                    for (k = 0; k < max_part; k++)
                        /*verifica se a pessoa esta no outro evento a mesma hora*/
                        if (same_pessoa(sala[j].evento[evt_a_cmp].participantes[k], teste)){
                            /*seleciona qual a mensagem de erro com base na funcao que a chama*/
                            switch (f_call){
                                case 'a':
                                    printf("Impossivel agendar evento %s. Participante %s tem um evento sobreposto.\n",
                                        teste.descricao, sala[j].evento[evt_a_cmp].participantes[k]);
                                    break;
                                case 'A':
                                    printf("Impossivel adicionar participante. Participante %s tem um evento sobreposto.\n",
                                       sala[j].evento[evt_a_cmp].participantes[k]);
                            }
                            erro += 1;
                        }
    return erro;
}

/*verifica se uma sala tem outro evento ao mesmo tempo, devolve 0 se nao tiver*/
int verifica_sala(e_eventos teste){
    int evt_a_cmp, erro = 0;
    for (evt_a_cmp = 0; evt_a_cmp < sala[teste.room].total_eventos; evt_a_cmp++){
        if (!same_evento(sala[teste.room].evento[evt_a_cmp], teste)){
            /*compara com eventos na mesma sala pra ver se estao na mesma hora*/
            erro += incompatibilidade_eventos(sala[teste.room].evento[evt_a_cmp], teste);
            if (erro){
                printf("Impossivel agendar evento %s. Sala%d ocupada.\n", teste.descricao, teste.room + 1);
                return erro;
            }
        }
    }
    return erro;
}

/*recebe um evento e grava-o na memoria*/
void grava_evento(e_eventos novo){
    int j;
    j = sala[novo.room].total_eventos;
    sala[novo.room].evento[j] = novo;
    sala[novo.room].total_eventos++;
}

/*Se os eventos forem iguais da 1, caso contrario 0*/
int same_evento(e_eventos A, e_eventos B){
    return !strcmp(A.descricao, B.descricao);
}
