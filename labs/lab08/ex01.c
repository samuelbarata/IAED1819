#include <stdio.h>
#include <string.h>
#define max 80

int main(){
    char *p, string[max];
    int i,len;
    fgets(string,max,stdin);
    p = string;
    len = strlen(string);
    for(i = 0; i<len; i++,p++){
        printf("%s\n", p);
    }
    return 0;
}
