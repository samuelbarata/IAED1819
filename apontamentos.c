#include <stdio.h>

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


void aula03(){}

int main(){
    printf("Introduza o numero da aula que quer ver: ");
    int aula = 0;
    scanf("%d", &aula);
    switch(aula){
        case 1: aula01();
        case 2: aula02();
        case 3: aula03();
    }
    printf("\n");
    return 0;
}