/*UTF-8*/

#include "aux.h"



int main(){
    /*lista de pointers para as variaveis globais 0-comando 1-nome
    2-local 3-dominio 4-telefone*/
    char **buffer;
    buffer = init_buffer();
    while((scanf("%s", buffer[0])),buffer[0][0]!='x'){
        switch (buffer[0][0]){
            case 'a':
                break;
            case 'l':
                break;
            case 'p':
                break;
            case 'r':
                break;
            case 'e':
                break;
            case 'c':
                break;
        }  
    }
    destroy_buffer(buffer);
    return 0;
}
