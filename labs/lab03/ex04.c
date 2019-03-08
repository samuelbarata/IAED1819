#include <stdio.h>

int main(){
    int in, total, str[500],i, inside;
    inside=0;
    for(total=0;in!=EOF;total++){
        in = getchar();
        str[total] = in;
    }
    for(i=0;i<total-1;i++){
        if(str[i] == ' '){
            inside = 0;
            putchar(str[i]);
        }
        else if(inside){putchar(str[i]);}
        else if(inside == 0 && (str[i]!='0' && str[i]!=' ')){
            inside = 1;
            putchar(str[i]);
        }
        else if(inside == 0 && (str[i]=='0' && str[i+1]==' ')){
            putchar(str[i]);
        }
    }
    printf("\n");
    return 0;
}