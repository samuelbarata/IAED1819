#include <stdio.h>

int main(){
    int in, inside;
    char str;
    inside=0;
    do{
        in = getchar();
        if(in==EOF)break;
        if(!inside && in == ' ')putchar('0');
        if(in == ' '){
            inside = 0;
            putchar(in);
        }
        else if(inside){putchar(in);}
        else if(inside == 0 && (in!='0' && in!=' ')){
            inside = 1;
            putchar(in);
        }
    }while(in != EOF);
    printf("\n");
    return 0;
}