#include <stdio.h>
#include <stdlib.h>

int SEG = 0;                      //pra experimentar o Segfault meter a 1


void swap(int *, int *);
int main(){
    int *py, *px;                   //ponteiro para um inteiro

    int x;                          //aloca na memoria uma variavel x do tipo inteiro
    py = malloc(sizeof(int));       //aloca na memória uma coisa com o tamanho de um inteiro e grava o endereço em py
    px = &x;                        //&x devolve o endereço de x, logo, px aponta para x

    //*px: conteudo gravado no endereço px
    *py = 5;
    printf("%p: %d\n", py, *py);

    x=3;
    printf("%p: %d\n", px, *px);

    //usa-se o * para ir buscar o conteudo apontado por ou escrever nesse mesmo local
    //não usar * significa que estamos a mudar o endereço

    //se o espaço do malloc n chega podemos alargar esse espaço
    py = realloc(py,sizeof(int)*2);         //se houver espaço estica a memoria, caso contrario move tudo para outro espaço


    free(py);                       //liberta a memória py
                                    //só podemos fazer free de memórias alocadas por nós [malloc] n podemos fazer de memórias alocadas pelo sistems [int x]

    /*/Erros
    Segfault ocorre quando tentamos aceder a "nada"/*/
    int *pz;
    if(SEG)             //variavel global antes main, ativar para experimentar erros
        *pz = 5;
    
    /*/^ ao corer a linha anterior tentamos gravar 5 no local para onde pz aponta, como não foi definido, dá erro;

    memory leak é quando perdemos o endereço de uma memoria alocada, deixando assim de poder fazer free/*/
    

    //Funções
    void swap(int *, int *);
    //a função swap recebe os ponteiros, logo:
    int a = 420, b = 69;
    printf("antes:\n\ta: %d, b: %d\n", a, b);
    swap(&a, &b); //&a e &b passa a posição de memória das variaveis, trocando assim os seua valores
    printf("depois:\n\ta: %d, b: %d\n", a, b);

    //Estruturas
    typedef struct ponto {double x; double y;} Ponto;
    Ponto ola, *meu_ponto;
    meu_ponto = &ola;
    (*meu_ponto).x = 3;     //através do ponteiro mudamos o conteudo de ola.x
    meu_ponto->y = 69;      //exatamente igual

    return 0;
}

void swap(int *a, int *b){      //recebe endereços
    int aux = *a;               //grava o conteudo de a
    *a = *b;                    //grava o conteudo de b na memória a
    *b = aux;                   //grava o conteudo de a na memória b
    //como está a efetuar operações diretamente na memória, apos esta função os valores de *a e *b estão trocados
}