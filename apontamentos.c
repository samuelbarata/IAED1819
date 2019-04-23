#include <stdio.h>
#include <string.h>
/*EOF = End of File*/
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
    int z=x++; /*z = x; x = x + 1*/
}

void teste_random(){
    int a,b;
    a = 10^8;
    b = -3;
    printf("%d\n", a+b);
}

void aula04(){
    /* < f.txt input file*/
    /* > o.txt output file*/
    char a = 'A';
    printf("O caracter %c corresponde ao ASCII dec:%d, hex:%x\n", a, a, a);
    int b = getchar();
    putchar(b);/*Ainda n percebo bem estas funcs*/

    /*Vetores e Matrizes*/
    int vetor[5];
    int matrix[5][5];
}

void aula05(){
    /*tabelas e vetores sao passados por referencia [como listas em python]; podem ser alteradas fora da sua funcao*/
    typedef struct avali {
        int num;
        char disciplina[7];
        double nota;
    }Avaliacao;
    Avaliacao samuel;
    samuel.num = 94230;
    strcpy(samuel.disciplina, "IAED");
    samuel.nota = 19.9;

    typedef int Inteiro;
    /*Escrever Inteiro == int*/
}

int aula6 = 06;
void aula06(){
    char a,b; /*1 byte [8 bits]*/
    strcmp(a,b); /*sao iguais devolve 0; pode dar <0 ou >0 de acordo com o primeiro caracter diferente*/
    short int c;
    long int d;
    unsigned long int e; /*n tem sinal logo fica com mais espaço, ao usar o long fica com ainda mais espaço*/
    int f, i1, i2; /*4 bytes*/

    /*float < double < long double*/
    sizeof(e); /*diz o n+ de bits acho eu*/
    /*
    char %c
    int %d
    float %f
    hexa %x
    unsigned %u
    */
    int i1, i2;
    float g;
    /*divisao completa entre 2 inteiros:*/
    g = i1 /(float) i2;

    /*aprender enum*/

    /*variaveis globais sao declaradas fora das funçoes e sao sempre inicializadas a 0*/
    aula6 = 05; /*declarada fora*/
    static k = 3; /*nao global*/
    const char msg[] = "Ola people"; /*const n altera valor*/
    char codes [][3] = {"AA","AB","BA","BB"};
    /*! = not*/
    /*!0 = 1*/
    /*
    & = AND bit a bit
    ^ XOR 
    << SHL
    >> SHR
    74 | 184 faz a soma binaria
    */
    /*condicao ? true : false*/
    (i1 & 1) ? "yes" : "no";
    /*so ve o ultimo bit logo diz sim se o numero for par e nao se for impar*/
    /*break; para o ciclo ou a funcao*/
}

void aula07(){
/*
selection sort{
    percorrer um array, encontrar o menor elemento; por no inicio; repetir para os restantes;
    comparacoes = N²/2
    trocas = N
    nao é estavel pq ordem de chaves duplicadas n é mantida
}
Insertion Sort{
    elemento a elemento, pegar nele e mover até ao sitio ideal
    deslocando os outros elementos para a esquerda ou para a direita;
    melhor caso:    N-1 comparacoes
    pior caso:      N²-1 comparacoes
    alg. estável
}
Bubble Sort{
    a começar no inicio compara com o seguinte; troca se for maior q o seguinte
    repete atépercorrer tudo sem trocar nenhuma vez
    
}
*/}

void aula08(){
    /*Outros sorts*/
}

void aula09(){
    int x = 10;
    int *px = &x; /*posição de memoria de x q é um int; igual aos [R0] de AC*//*&x devolve a memoria de x*/
    printf("%d\n", *px);
    *px = 5;
    printf("%d\n", *px);
    printf("%d\n", x);
    int *p = g();   /*aloca nova memoria*/
    free(p);        /*liberta a memoria*/
    
}
int * g(){
    int *px = malloc(sizeof(int));
    *px = 10;
    return px;
}

void aula10(){
    char buffer[256];
    char *string[10];
    int i;
    for(i=0;i<10;i++){
        puts("introd");
        scanf("%s", buffer);
        string[i]=malloc(sizeof(char)+(strlen(buffer)+1));
        strcpy(string[i],buffer);
    }
    /*------------*/
    struct node{
        int data;
        struct node *next;
    };
    
}

void aula11(){}
void aula12() {}
void aula13() {}

int main(){

    /*teste_random();*/
    /*long %ld*/
    printf("Introduz o numero da aula que quer ver [1 - 10]: ");
    int aula = 0;
    scanf("%d", &aula);
    switch(aula){
        case 0: return 0;
        case 1: aula01();break;
        case 2: aula02();break;
        case 3: aula03();break;
        case 4: aula04();break;
        case 5: aula05();break;
        case 6: aula06();break;
        case 7: aula07();break;
        case 8: aula08();break;
        case 9: aula09();break;
        case 10: aula10();break;
        case 11: aula11();break;
        case 12: aula12();break;
        case 13: aula13();break;
        default: return 404;
    }
    printf("\n");
    return 0;
}
