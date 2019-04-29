#include "ex03aux.h"
/*/gcc ex03.c ex03aux.c -o ex03/*/

int main(){
    char buffer[MAX] = "";
    node *head = NULL;
    fgets(buffer, MAX, stdin);          /*/lê a primeira linha /*/
    while(strcmp(buffer,"x\n")){        /*/enquanto n receber "x" continua a ler/*/
        head = push(head, buffer);      /*/grava a ultima string na pilha/*/
        fgets(buffer, MAX, stdin);      /*/lê a próxima linha/*/
    }
    print(head);                        /*/imprime a pilha/*/
    return 0;
}
