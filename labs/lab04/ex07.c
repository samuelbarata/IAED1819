#include <stdio.h>
#include <string.h>
#define MAX 80

/*##################NAO FUNCIONA###############*/

void leLinha(char s[]){
    int i;
    for(i=0; s[i-1] != EOF ; i++){s[i] = getchar();}
    /*return i-1;*/
}

void apagaCaracter(char s[], char c, char res[]){
    int i, re=0, le = strlen(s);
    for(i=0; i<le;i++){
        if(s[i] != c){
            res[re] = s[i];
            re++;
        }
    }
}

void printlinha(char s[]){
    int len = strlen(s),i;
    for(i = 0; i<len; i++){
        putchar(s[i]);
    }
}

int main(){
    char s[MAX], c, res[MAX];
    int le;
    leLinha(s); /*s tem a string e m tem o comprimento*/
    le = strlen(s);
    c = s[le-3];
    printf("%c\n", c);
    apagaCaracter(s, c, res);
    printlinha(res);
    printf("\n");
    return 0;
}