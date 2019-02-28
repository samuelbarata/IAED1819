#include <stdio.h>

#define VARIAVEL 0
/*variavel global inalteravel*/

void aula01(){
    printf("aula01\n");
}

float c_to_f(int c){
    return ((c-32)*5/9);
}

void aula02(){
    printf("aula02\n");
    /*compile: "gcc -o [output name] -ansi -pedantic -Wextra -Wall [input.c]"*/
    int i;
    i=0;
    while (i<10){
        printf("%d ",i);
        i++;
    }
    printf("\n");
    int c;
    c = 100;
    printf("%dºC = %fF\n", c, c_to_f(c));
    printf("tab = \\t\t<--tab\n");
    c = 25;
    printf("nº espaços:%3d\t%6d\n", c, c_to_f(c));
    printf("tab = \\t\t<--tab");
}


void aula03(){
    float f;
    f = 1.209865;
    /*%.2f mostra um float com 2 casas decimais*/
    printf("%.2f\n",f);
    printf("variavel global no inicio do codigo #define <nome> <valor> [nao usa ;]\n");
    for(/*inicializacao, acontece no inicio; pode estar vazio*/;/*executa enquanto*/f++<30;/*acontece a cada ciclo; pode estar vazio*/){printf(" ");}
    printf("\nO que quero ler [float]:");
    scanf("%f",&/*onde guardar*/f);
    /*& le o endereco da variavel*/
    int x=0;
    int y=++x; /*x = x + 1; y = x*/
    int z=x++; /*y = x; x = x + 1*/
}

void teste_random(){
    int a,b;
    a = 10^8;
    b = -3;
    printf("%d\n", a+b);
}

void aula04(){}
void aula05(){}
void aula06(){}
void aula07(){}
void aula08(){}
void aula09(){}
void aula10(){}


int main(){

    /*teste_random();*/

    printf("Introduza o numero da aula que quer ver [1 - 3]: ");
    int aula = 0;
    scanf("%d", &aula);
    switch(aula){
        case 0: return 0;
        case 1: aula01();
        case 2: aula02();
        case 3: aula03();
        case 4: aula04();
        case 5: aula05();
        case 6: aula06();
        case 7: aula07();
        case 8: aula08();
        case 9: aula09();
        case 10: aula10();
    }
    printf("\n");
    return 0;
}