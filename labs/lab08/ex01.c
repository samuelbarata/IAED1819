#include <stdio.h>
#include <string.h>
#define max 80

int main(){
    char *p, string[max];
    fgets(string,max,stdin);
    p = string;
    while(*p!='\n'){
        printf("%s", p);
        p++;
    }
    return 0;
}
