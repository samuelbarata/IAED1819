/*╭─────────────────────────────────────────────╮
  │  File:  proj1.c                             │
  │  Author:  Samuel Barata (94230)             │
  │  Description: Contem as funcoes principais  │
  ╰─────────────────────────────────────────────╯
*/

#include "aux.h"


/*╭─────────────────────────────────────┬───────┬────────────────────────────────────────╮
  │                                      Funcoes                                         │
  ╰─────────────────────────────────────┴───────┴────────────────────────────────────────╯*/

void adiciona_evento();             /*adiciona um evento*/
void lista_eventos();               /*lista os eventos todos*/
void lista_eventos_sala();          /*lista os eventos de uma sala*/
void remove_evento();               /*remove um evento*/
void altera_hora();                 /*altera a hora de um evento*/
void altera_duracao();              /*altera a duracao de um evento*/
void altera_sala();                 /*altera a sala de um evento*/
void adiciona_participante();       /*adiciona participante a um evento*/
void remove_participante();         /*remove participante de um evento*/
void conta_ze();                    /*conta o numero de responsaveis Ze*/

/*╭───────────────────────────────────────┬────┬─────────────────────────────────────────╮
  │                                        main                                          │
  ╰───────────────────────────────────────┴────┴─────────────────────────────────────────╯*/
  
int main(){
    char cmd;   /*variavel onde a instrucao vai estar guradada*/
    coordenada coor;
    /*inicializacao dos eventos*/
    for (coor.room = 0; coor.room < max_sala; coor.room++){
        sala[coor.room].total_eventos = 0;
        for(coor.evendo_id = 0; coor.evendo_id < max_eventos; coor.evendo_id++)
            reset_evento(coor);
        sala[coor.room].total_eventos = 0;
    }
    /*main loop*/
    do{
        scanf("%c", &cmd);
        switch(cmd){
            case 'a':
                read();
                adiciona_evento();
                break;
            case 'l':
                lista_eventos();
                break;
            case 's':
                read();
                lista_eventos_sala();
                break;
            case 'r':
                read();
                remove_evento();
                break;
            case 'i':
                read();
                altera_hora();
                break;
            case 't':
                read();
                altera_duracao();
                break;
            case 'm':
                read();
                altera_sala();
                break;
            case 'A':
                read();
                adiciona_participante();
                break;
            case 'R':
                read();
                remove_participante();
                break;
            case 'Z':
                conta_ze();
                break;
        }
    }while(cmd!='x');
    return 0;
}


/*╭────────────────────────────────┬──────────────────┬──────────────────────────────────╮
  │                                 Funcoes Principais                                   │
  ╰────────────────────────────────┴──────────────────┴──────────────────────────────────╯*/

/*atraves da variavel global args cria um evento, depois verifica se ele pode ser adicionado,
se poder, vai ser adicionado no primeiro espaco disponivel*/
void adiciona_evento(){
    /* descricao:data:inicio:duracao:sala:responsavel:participantes */
    /*     0      1     2       3     4       5          6  7  8    */
    int erro = 0;
    e_eventos novo;
    /*cria o evento*/
    novo.room = str_to_int(args[4]) - 1;
    strcpy(novo.participantes[2], "");
    strcpy(novo.participantes[3], "");
    strcpy(novo.descricao, args[0]);
    strcpy(novo.participantes[0], args[5]);
    strcpy(novo.participantes[1], args[6]);
    strcpy(novo.participantes[2], args[7]);
    strcpy(novo.participantes[3], args[8]);
    novo.dia = get_day(args[1]);
    novo.tempo = get_time(args[2]);
    novo.duracao = str_to_int(args[3]);
    novo.abs_time = calcula_abs(novo);
    /*ativa o evento*/
    novo.status = 1;
    strcpy(args[6], ""); /*apaga os participantes da variavel global pois nem sempre estao 3 participantes*/
    strcpy(args[7], ""); /*logo, da proxima vez q esta funcao for chamada, se so tivesse 1 participante*/
    strcpy(args[8], ""); /*iam ser atribuidos os ultimos 2 participantes do evento anterior*/
    /*avalia os erros*/
    erro += verifica_sala(novo);
    if(erro)
        return ;
    erro += verifica_pessoas(novo, 'a');
    if(!erro)
        grava_evento(novo);
}

/*lista os eventos numa determinada sala por ordem, 
recebe o numero da sala atravez de  args[0]*/
void lista_eventos_sala(){
    coordenada coor;
    coor.room = str_to_int(args[0])-1;
    sort_inroom(coor.room);
    for (coor.evendo_id = 0; coor.evendo_id < sala[coor.room].total_eventos; coor.evendo_id++)
        lista_evento(coor);
}

/*altera a hora de um determinado evento para a hora recebida em args*/
void altera_hora(){
    e_eventos aux;
    coordenada coor = encontra_evento(args[0]);
    if (coor.evendo_id == 100){
        printf("Evento %s inexistente.\n", args[0]);
        return;
    }
    aux = sala[coor.room].evento[coor.evendo_id];
    aux.tempo = get_time(args[1]);
    if(!verifica_sala(aux))
        if (!verifica_pessoas(aux, 'a'))
            sala[coor.room].evento[coor.evendo_id].tempo = aux.tempo;
}

/*altera a sala de um determniado evento para a sala recebia em args*/
void altera_sala(){
    coordenada aux, res;
    e_eventos temp;
    res.room = str_to_int(args[1]) - 1;     /*destino*/
    aux = encontra_evento(args[0]);         /*origem*/
    if (aux.evendo_id == 100){
        printf("Evento %s inexistente.\n", args[0]);
        return;
    }
    temp = sala[aux.room].evento[aux.evendo_id];
    temp.room = res.room;
    if(!verifica_sala(temp)){
        reset_evento(aux);
        grava_evento(temp);
    }
}

/*apaga um evento recebido em args*/
void remove_evento(){
    coordenada coor = encontra_evento(args[0]);
    if (coor.evendo_id == 100){
        printf("Evento %s inexistente.\n", args[0]);
        return ;
    }
    reset_evento(coor);   
}

/*altera a duracao de um evento recebido em args*/
void altera_duracao(){
    e_eventos aux;
    coordenada coor = encontra_evento(args[0]);
    if (coor.evendo_id == 100){
        printf("Evento %s inexistente.\n", args[0]);
        return ;
    }
    aux = sala[coor.room].evento[coor.evendo_id];    
    aux.duracao = str_to_int(args[1]);
    if(!verifica_sala(aux))
        if (!verifica_pessoas(aux, 'a'))
            sala[coor.room].evento[coor.evendo_id].duracao = aux.duracao;
}

/*adiciona um participante a um evento (args[1] e args[0])*/
void adiciona_participante(){
    e_eventos aux;
    int i;
    coordenada coor = encontra_evento(args[0]);
    if (coor.evendo_id == 100){
        printf("Evento %s inexistente.\n", args[0]);
        return ;
    }
    aux = sala[coor.room].evento[coor.evendo_id];
    /*verifica se a pessoa ja esta no evento*/
    for(i=0;i<max_part;i++){
        if (!strcmp(args[1], aux.participantes[i]))
            return ;
    }    
    /*encontra a primeira posicao vazia*/
    for(i=0;i<max_part;i++)
        if(!strcmp(sala[coor.room].evento[coor.evendo_id].participantes[i],"")){
            strcpy(aux.participantes[i], args[1]);
            if (!verifica_pessoas(aux, 'A'))
                strcpy(sala[coor.room].evento[coor.evendo_id].participantes[i], args[1]);
            return;
        }
    /*se nao houver espaco*/
    printf("Impossivel adicionar participante. Evento %s ja tem 3 participantes.\n", sala[coor.room].evento[coor.evendo_id].descricao);
}

/*remove um participante de um evento (args[1] e args[0]*/
void remove_participante(){
    int i;
    coordenada coor = encontra_evento(args[0]);
    if (coor.evendo_id == 100){
        printf("Evento %s inexistente.\n", args[0]);
        return ;
    }
    for(i=1;i<max_part;i++)     /*encontra a posicao do participante*/
        if(!strcmp(sala[coor.room].evento[coor.evendo_id].participantes[i],args[1])){
            if (!strcmp(sala[coor.room].evento[coor.evendo_id].participantes[2], "")){
                printf("Impossivel remover participante. Participante %s e o unico participante no evento %s.\n",
                        sala[coor.room].evento[coor.evendo_id].participantes[1], sala[coor.room].evento[coor.evendo_id].descricao);
                return;
            }
            for(;i<max_part-1;i++){
                strcpy(sala[coor.room].evento[coor.evendo_id].participantes[i], sala[coor.room].evento[coor.evendo_id].participantes[i+1]);
            }
            strcpy(sala[coor.room].evento[coor.evendo_id].participantes[3], "");
            return;
        }
}

/*Escreve todos os eventos ativos por ordem cronologica*/
void lista_eventos(){
    int i, breaker = 0, sorter[max_sala] = {0,0,0,0,0,0,0,0,0,0}; /*proximo evento de cada sala a ser comparado*/
    coordenada next;                                        /*coordenadas do evento de menor tempo nao ordenado*/
    unsigned long int aux1 = 0, aux2 = 0;  
    /*ordena inicialmente as 10 salas*/
    for(i=0;i<max_sala;i++){
        sort_inroom(i);
        /*testa para ver se existe pelo menos 1 evento*/
        if(sorter[i] == sala[i].total_eventos)
            breaker += 1;
    }

    /*breaker == 10 quando => 10 salas nao tem mais eventos por ordenar*/
    while(breaker!=10){
        breaker = 0;
        for(i=0;i<max_sala;i++){    /*seleciona o primeiro evento ativo nao ordenado*/
            if(sorter[i]<sala[i].total_eventos){
                next.evendo_id=sorter[i];
                next.room = i;
                break;
            }
        }

        aux1 = sala[next.room].evento[next.evendo_id].abs_time;
        aux2 = sala[next.room].evento[next.evendo_id].tempo;
        /*escolhe o menor das 10 salas*/
        for(i=0;i<max_sala;i++){
            if(sorter[i]<sala[i].total_eventos){
                /*se o dia for menor, atualiza o menor*/
                if(aux1 > sala[i].evento[sorter[i]].abs_time){
                        aux1 = sala[i].evento[sorter[i]].abs_time;
                        aux2 = sala[i].evento[sorter[i]].tempo;
                        next.room = i;
                        next.evendo_id = sorter[i];
                }
                /*se o dia for igual e a hora for menor, atualiza o menor*/
                else if(aux1 == sala[i].evento[sorter[i]].abs_time){
                    if(aux2 > sala[i].evento[sorter[i]].tempo){
                        aux1 = sala[i].evento[sorter[i]].abs_time;
                        aux2 = sala[i].evento[sorter[i]].tempo;
                        next.room = i;
                        next.evendo_id = sorter[i];
                    }
                }
            }
        }
        lista_evento(next);     /*imprime o menor*/
        sorter[next.room]++;    /*aumenta o numero de eventos ordenados nesta sala*/
        /*testa para ver se ja estao todos ordenados*/
        for(i=0;i<max_sala;i++)
            if(sorter[i] == sala[i].total_eventos)
                breaker += 1;
    }
}

/*conta o numero de responsaveis Ze*/
void conta_ze(){
    int ze = 0, room, id;
    for(room=0;room<max_sala;room++)    /*percorre as salas*/
        for(id=0;id<max_eventos;id++)   /*percorre os eventos*/
            if (!strcmp(sala[room].evento[id].participantes[0], "Ze") && sala[room].evento[id].status)
                ze++;
    printf("Ze e organizador de %d eventos\n", ze);
}
