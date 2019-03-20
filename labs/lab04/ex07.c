#include <stdio.h>
#include <string.h>
#define MAX 80

int leLinha(char s[]){
    int i;
    for(i=0; s[i-1] != '\n' ; i++){s[i] = getchar();}
    s[i]='\0';
    return i-1;
}

void apagaCaracter(char s[], char c, char res[]){
    int i, re=0, len = strlen(s);
    for(i=0; i<=len;i++){
        if(s[i] != c){
            res[re] = s[i];
            re++;
        }
    }
}

void printlinha(char s[]){
    int i, len = strlen(s);
    for(i = 0; i<len-1; i++){
        putchar(s[i]);
    }
}

int main(){
    char s[MAX],c ,res[MAX];
    leLinha(s); /*s tem a string*/
    c = getchar();
    apagaCaracter(s, c, res);
    printlinha(res);
    printf("\n");
    return 0;
}