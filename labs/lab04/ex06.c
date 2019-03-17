#include <stdio.h>
#define MAX 80

int maiusculas(char s[]);

int main(){
    char s[MAX];
    return maiusculas(s);
}

int maiusculas(char s[]){
    int i, m, dif = 'a'-'A';
    for(i=0; s[i-1] != EOF ; i++){s[i] = getchar();}
    m=i-1;
    for(i=0; i < m; i++){
        if (s[i] >= 'a'){
            printf("%c", s[i]-dif);
        }
        else{
            printf("%c", s[i]);
        }
    }
    printf("\n");
    return m;
}