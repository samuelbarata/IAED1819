#include "aux.h"

/*aloca memoria para a variavel global de argumentos*/
char **init_buffer(){
    char **buffer;
    buffer = malloc(sizeof(char *) * no_of_args +1);
    buffer[0] = malloc(sizeof(char)+1);
    buffer[1] = malloc(sizeof(char) * max_str + 1); /*nome*/
    buffer[2] = malloc(sizeof(char) * max_str + 1); /*local*/
    buffer[3] = malloc(sizeof(char) * max_str + 1); /*dominio*/
    buffer[4] = malloc(sizeof(char) * max_phone + 1); /*tel*/
    return buffer;
}

void destroy_buffer(char **buffer){
    char *atual;
    int i;
    for(i=4, atual = buffer[i]; i>=0; i--){
        atual = buffer[i];
        free(atual);
    }
    free(buffer);
}
