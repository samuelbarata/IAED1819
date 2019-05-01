#include "ex03aux.h"
/*/./../../compile.sh -Y ex03 ex03aux.c/*/

int main(){
    char buffer[MAX] = "";
    node *head = NULL;
    scanf("%s",buffer);                 /*/lê a primeira linha /*/
    while(strcmp(buffer,"x")){          /*/enquanto n receber "x" continua a ler/*/
        head = push(head, buffer);      /*/grava a ultima string na pilha/*/
        scanf("%s",buffer);             /*/lê a próxima linha/*/
    }
    print(head);                        /*/imprime a pilha/*/
    return 0;
}
