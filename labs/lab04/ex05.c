#include <stdio.h>
#define MAX 80

int leLinha(char s[]);

int main(){
    char s[MAX];
    int i, m;
    m = leLinha(s);
    for(i=0; i < m; i++){printf("%c", s[i]);}
    printf("\n");
    return 0;
}

int leLinha(char s[]){
    int i;
    for(i=0; s[i-1] != EOF ; i++){s[i] = getchar();}
    return i-1;
}