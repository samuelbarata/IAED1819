#include <stdio.h>
#define MAX 80

int leLinha(char s[]);

int main(){
    char s[MAX];
    return leLinha(s);
}

int leLinha(char s[]){
    int i, m;
    for(i=0; s[i-1] != EOF ; i++){s[i] = getchar();}
    m=i-1;
    for(i=0; i < m; i++){printf("%c", s[i]);}
    printf("\n");
    return m;
}