#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
 /*constantes*/
#define DESC 64
#define DATA 9
#define INIC 5
#define PART DESC
#define DURA 4
#define SALA 2
#define NPART 4
#define NUM 9
#define ESP 10
#define EVE  100
#define TOTAL DESC+DATA+INIC+DURA+SALA+DESC+PART*NPART+NUM
#define CRONO 13
#define DIA 3
#define MES 3
#define EVETOTAL 1000

int sala[ESP]={0,0,0,0,0,0,0,0,0,0};

typedef struct {
	char descricao[DESC],strdata[DATA],cronologia[CRONO];
	int hcomeco, mcomeco, comeco, fim;/*comeco e horas + minutos em minutos*/
	int duracao, sal, numpart;
	char participantes[NPART][PART];
}event;

event tab[ESP][EVE];

void printevento(event evento){
	int i;
	printf("%s %s %.2d%.2d %d Sala%d %s\n",evento.descricao,evento.strdata,evento.hcomeco,evento.mcomeco,
			evento.duracao,evento.sal,evento.participantes[0]);
	printf("*");
	for(i=1;i<evento.numpart;i++){
		printf(" %s",evento.participantes[i]);
	}
	printf("\n");
}

void a(char str[]){
	char *token;
	char dia[DIA],mes[MES],comec[INIC];
	const char s[2]=":";
	int i, espaco, k, inicio, x, y,verifica;
	event evento;
	verifica=0;
	i=0;
	strcpy(evento.descricao,strtok(str, s));
	strcpy(evento.strdata,strtok(NULL, s));
	strncpy(dia,evento.strdata,2);
	strncpy(mes,&evento.strdata[2],2);
	dia[2] ='\0';
	mes[2] ='\0';
	strcpy(evento.cronologia,&evento.strdata[4]);
	strcat(evento.cronologia,mes);
	strcat(evento.cronologia,dia);
	strcpy(comec,strtok(NULL, s));
	inicio=atoi(comec);
	evento.hcomeco=inicio/100;
	evento.mcomeco=inicio%100;
	evento.comeco=evento.hcomeco*60+evento.mcomeco;
	evento.duracao=atoi(strtok(NULL, s));
	evento.sal=atoi(strtok(NULL, s));
	espaco=evento.sal;
	strcat(evento.cronologia,comec);
	while((token=strtok(NULL, s))!=NULL){
		strcpy(evento.participantes[i],token);
		i++;
	}
	evento.numpart=i;
	evento.fim=evento.comeco+evento.duracao;
	for(k=0;k<sala[espaco-1];k++){
		if(strcmp(tab[espaco-1][k].strdata,evento.strdata)==0){
			if((evento.comeco<=tab[espaco-1][k].comeco && tab[espaco-1][k].comeco<evento.fim) || 
				(evento.comeco<tab[espaco-1][k].fim && tab[espaco-1][k].fim<=evento.fim) || 
				(tab[espaco-1][k].comeco<=evento.comeco && evento.comeco<tab[espaco-1][k].fim)){
				printf("Impossivel agendar evento %s. Sala%d ocupada.\n", evento.descricao, evento.sal);
				return ;
			}
		}
	}
	for(i=0;i<ESP;i++){
		if(i==espaco-1){
			continue;
		}	
		for(k=0;k<sala[i];k++){
			if(strcmp(tab[i][k].strdata,evento.strdata)==0){
				if(((evento.comeco<=tab[i][k].comeco && tab[i][k].comeco<evento.fim) || 
				(evento.comeco<tab[i][k].fim && tab[i][k].fim<=evento.fim) || 
				(tab[i][k].comeco<=evento.comeco && evento.comeco<tab[i][k].fim))){
					for(x=0;x<evento.numpart;x++){
						for(y=0;y<tab[i][k].numpart;y++){
							if(strcmp(evento.participantes[x],tab[i][k].participantes[y])==0){
								printf("Impossivel agendar evento %s. Participante %s tem um evento sobreposto.\n",evento.descricao ,evento.participantes[x]);
								verifica=1;
							}
						}	
					}
				}
			}
		}
	}
	if(verifica==1){
		return;
	}
	tab[espaco-1][sala[espaco-1]]=evento;
	sala[espaco-1]++;
}

void l(){
	int i,k,x,total;
	event organ[EVETOTAL],swap;
	x=0;
	total=0;
	for(i=0;i<ESP;i++){
		for(k=0;k<sala[i];k++){
			organ[x]=tab[i][k];
			x++;
		}
	}
	for(i=0;i<ESP;i++){
		total=total+sala[i];
	}
	for(k=0;k<total-1;k++){
		for(i=0;i<total-k-1;i++){
			if(strcmp(organ[i].cronologia,organ[i+1].cronologia)>0){
				swap=organ[i];
				organ[i]=organ[i+1];
				organ[i+1]=swap;
			}
		}
	}
	for(i=0;i<total;i++){
		printevento(organ[i]);
	}
}

void s(int esp){
	int k,d;
	event swap;
	for(k=0;k<sala[esp-1]-1;k++){
		for (d = 0 ; d < sala[esp-1]-k-1; d++){
			if(strcmp(tab[esp-1][d].cronologia,tab[esp-1][d+1].cronologia)>0){
				swap=tab[esp-1][d];
				tab[esp-1][d]=tab[esp-1][d+1];
				tab[esp-1][d+1]=swap;
			}		
		}
	}
	for(k=0;k<sala[esp-1];k++){
		printevento(tab[esp-1][k]);
	}
}

void r(char str[]){
	int i,k;
	for(i=0;i<ESP;i++){
		for(k=0;k<sala[i];k++){
			if(strcmp(str,tab[i][k].descricao)==0){
				if(k==sala[i]-1){
					sala[i]--;
					return;
				}
				tab[i][k]=tab[i][sala[i]-1];
				sala[i]--;
				return;
			}
		}
	}
	printf("Evento %s inexistente.\n",str);		
}

void i(char str[]){
	event evento;
	const char s[2]=":";
	char descr2[DESC],comec[INIC];
	int inicio;
	int i,k,e,j,x,y,verifica;
	strcpy(descr2,strtok(str, s));
	strcpy(comec,strtok(NULL, s));
	inicio=atoi(comec);
	verifica=0;
	for(i=0;i<ESP;i++){
		for(k=0;k<sala[i];k++){
			if(strcmp(descr2,tab[i][k].descricao)==0){
				evento=tab[i][k];
				evento.hcomeco=inicio/100;
				evento.mcomeco=inicio%100;
				evento.comeco=evento.hcomeco*60+evento.mcomeco;
				evento.fim=evento.comeco+evento.duracao;
				evento.cronologia[8]='\0';
				strcat(evento.cronologia,comec);
				for(j=0;j<sala[i];j++){
					if(strcmp(evento.descricao,tab[i][j].descricao)==0){
						continue;
					}
					if(strcmp(tab[i][j].strdata,evento.strdata)==0){
						if(((evento.comeco<=tab[i][j].comeco && tab[i][j].comeco<evento.fim) || 
						(evento.comeco<tab[i][j].fim && tab[i][j].fim<=evento.fim) || 
						(tab[i][j].comeco<=evento.comeco && evento.comeco<tab[i][j].fim))){
							printf("Impossivel agendar evento %s. Sala%d ocupada.\n",evento.descricao,evento.sal);
							return;
						}
					}	
				}
				for(e=0;e<ESP;e++){
					if(e==i){
						continue;
					}
					for(j=0;j<sala[e];j++){
						if(strcmp(tab[e][j].strdata,evento.strdata)==0){
							if(((evento.comeco<=tab[e][j].comeco && tab[e][j].comeco<evento.fim) || 
							(evento.comeco<tab[e][j].fim && tab[e][j].fim<=evento.fim) || 
							(tab[e][j].comeco<=evento.comeco && evento.comeco<tab[e][j].fim))){
								for(x=0;x<evento.numpart;x++){
									for(y=0;y<tab[e][j].numpart;y++){
										if(strcmp(evento.participantes[x],tab[e][j].participantes[y])==0){
											printf("Impossivel agendar evento %s. Participante %s tem um evento sobreposto.\n",evento.descricao ,evento.participantes[x]);
											verifica=1;
										}
									}
								}
							}
						}
					}
				}
				if(verifica==1){
					return;
				}
				tab[i][k]=evento;
				return;
			}
		}
	}
	printf("Evento %s inexistente.\n",descr2);
}

void t(char str[]){
	event evento;
	const char s[2]=":";
	char descr2[DESC];
	int i,k,e,j,x,y,verifica,duracao;
	strcpy(descr2,strtok(str, s));
	duracao=atoi(strtok(NULL, s));
	verifica=0;
	for(i=0;i<ESP;i++){
		for(k=0;k<sala[i];k++){
			if(strcmp(descr2,tab[i][k].descricao)==0){
				evento=tab[i][k];
				evento.duracao=duracao;
				evento.fim=evento.comeco+evento.duracao;
				for(j=0;j<sala[i];j++){
					if(strcmp(evento.descricao,tab[i][j].descricao)==0){
						continue;
					}
					if(strcmp(tab[i][j].strdata,evento.strdata)==0){
						if(((evento.comeco<=tab[i][j].comeco && tab[i][j].comeco<evento.fim) || 
						(evento.comeco<tab[i][j].fim && tab[i][j].fim<=evento.fim) || 
						(tab[i][j].comeco<=evento.comeco && evento.comeco<tab[i][j].fim))){
							printf("Impossivel agendar evento %s. Sala%d ocupada.\n",evento.descricao,evento.sal);
							return;
						}
					}	
				}
				for(e=0;e<ESP;e++){
					if(e==i){
						continue;
					}
					for(j=0;j<sala[e];j++){
						if(strcmp(tab[e][j].strdata,evento.strdata)==0){
							if(((evento.comeco<=tab[e][j].comeco && tab[e][j].comeco<evento.fim) || 
							(evento.comeco<tab[e][j].fim && tab[e][j].fim<=evento.fim) || 
							(tab[e][j].comeco<=evento.comeco && evento.comeco<tab[e][j].fim))){
								for(x=0;x<evento.numpart;x++){
									for(y=0;y<tab[e][j].numpart;y++){
										if(strcmp(evento.participantes[x],tab[e][j].participantes[y])==0){
											printf("Impossivel agendar evento %s. Participante %s tem um evento sobreposto.\n",evento.descricao ,evento.participantes[x]);
											verifica=1;
										}
									}
								}
							}
						}
					}
				}
				if(verifica==1){
					return;
				}
				tab[i][k]=evento;
				return;
			}
		}
	}
	printf("Evento %s inexistente.\n",descr2);
}

void m(char str[]){
	event evento;
	const char s[2]=":";
	char descr2[DESC];
	int espaco,i,k,j;
	strcpy(descr2,strtok(str, s));
	espaco=atoi(strtok(NULL, s));
	for(i=0;i<ESP;i++){
		for(k=0;k<sala[i];k++){
			if(strcmp(descr2,tab[i][k].descricao)==0){
				evento=tab[i][k];
				evento.sal=espaco;
				for(j=0;j<sala[espaco-1];j++){
					if(strcmp(tab[espaco-1][j].strdata,evento.strdata)==0){
						if(((evento.comeco<=tab[espaco-1][j].comeco && tab[espaco-1][j].comeco<evento.fim) || 
						(evento.comeco<tab[espaco-1][j].fim && tab[espaco-1][j].fim<=evento.fim) || 
						(tab[espaco-1][j].comeco<=evento.comeco && evento.comeco<tab[espaco-1][j].fim))){
							printf("Impossivel agendar evento %s. Sala%d ocupada.\n",evento.descricao,evento.sal);
							return;
						}
					}	
				}
				tab[espaco-1][sala[espaco-1]]=evento;
				sala[espaco-1]++;
				if(k==sala[i]-1){
					sala[i]--;
					return;
				}
				tab[i][k]=tab[i][sala[i]-1];
				sala[i]--;
				return;
			}
		}
	}
	printf("Evento %s inexistente.\n",descr2);
}

void A(char str[]){
	event evento;
	const char s[2]=":";
	char descr2[DESC],partic[PART];
	int i,k,e,j,x,y,verifica;
	strcpy(descr2,strtok(str, s));
	strcpy(partic,strtok(NULL, s));
	verifica=0;
	for(i=0;i<ESP;i++){
		for(k=0;k<sala[i];k++){
			if(strcmp(descr2,tab[i][k].descricao)==0){
				evento=tab[i][k];
				if(evento.numpart<=4){
					for(x=0;x<evento.numpart;x++){
						if(strcmp(evento.participantes[x],partic)==0){
							return;
						}
					}
					strcpy(evento.participantes[evento.numpart],partic);
					evento.numpart++;
				}	
				verifica=1;
				break;
			}
		}
		if(verifica==1){
			break;
		}
	}
	if(verifica==1){
		for(e=0;e<ESP;e++){
			if(e==i){
				continue;
			}
			for(j=0;j<sala[e];j++){
				if(strcmp(tab[e][j].strdata,evento.strdata)==0){
					if(((evento.comeco<=tab[e][j].comeco && tab[e][j].comeco<evento.fim) || 
					(evento.comeco<tab[e][j].fim && tab[e][j].fim<=evento.fim) || 
					(tab[e][j].comeco<=evento.comeco && evento.comeco<tab[e][j].fim))){
						for(x=0;x<evento.numpart;x++){
							for(y=0;y<tab[e][j].numpart;y++){
								if(strcmp(evento.participantes[x],tab[e][j].participantes[y])==0){
									printf("Impossivel adicionar participante. Participante %s tem um evento sobreposto.\n",partic);
									return;
								}
							}
						}
					}
				}
			}
		}
		if(evento.numpart>4){
			printf("Impossivel adicionar participante. Evento %s ja tem 3 participantes.\n",descr2);
			return;
		}	
		tab[i][k]=evento;
		return;
	}
	printf("Evento %s inexistente.\n",descr2);
}

void R(char str[]){
	event evento;
	const char s[2]=":";
	char descr[DESC],partic[PART];
	int i,k,x,y,verifica,verifica2;
	strcpy(descr,strtok(str, s));
	strcpy(partic,strtok(NULL, s));
	verifica=0;
	verifica2=0;
	for(i=0;i<ESP;i++){
		for(k=0;k<sala[i];k++){
			if(strcmp(descr,tab[i][k].descricao)==0){
				verifica=1;
				evento=tab[i][k];
				for(x=1;x<evento.numpart;x++){
					if(strcmp(evento.participantes[x],partic)==0){
						verifica2=1;
						if(evento.numpart>2){
							if(x==evento.numpart-1){
								evento.numpart--;
							}
							else{
								for(y=x;y<evento.numpart-1;y++){
									strcpy(evento.participantes[y],evento.participantes[y+1]);
								}
								evento.numpart--;
							}
						tab[i][k]=evento;
						return;
						}
					}
				}
				if(verifica2==1){
					printf("Impossivel remover participante. Participante %s e o unico participante no evento %s.\n",partic,descr);
					return;
				}
			}
		}
	}
	if(verifica!=1){
		printf("Evento %s inexistente.\n",descr);
	}
}

int main(){
	char carater,
		 str[TOTAL],
		 command;
	int k,valor;
	k=0;
	command=getchar();
	while(command!='x'){
		k=0;
		if(command!='l'){
			getchar();
		}
		while((carater=getchar())!='\n'){
			str[k]=carater;
			k++;
		}
		str[k]='\0';
		switch(command){
			case 'a' :
				a(str);
				break;
			case 'l':
				l();
				break;
			case 's':
				valor=atoi(str);
				s(valor);
				break;
			case 'r' :
				r(str);
				break;
			case 'i' :
				i(str);
				break;
			case 't' :
				t(str);
				break;
			case 'm' :
				m(str);
				break;
			case 'A' :
				A(str);
				break;
			case 'R' :
				R(str);
				break;
		}
		command=getchar();
	}
	return 0;
}
















