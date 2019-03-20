#include <stdio.h>
#include <string.h>
#define MAX 80

void read(char var[]){
    int i=0;
    do{
        var[i] = getchar();
        i++;
    }while(var[i-1]!=' ' && var[i-1]!=EOF);
    var[i] = '\0';
}

char cmp(char a[],char b[]){
    int i=0;
    while(1){
        if (a[i]<b[i])      return 'b';
        else if (a[i]>b[i]) return 'a';
        i++;
    }
}

void imprime(char res[]){
    unsigned long int i;
    for(i=0;i<strlen(res)-1;i++) putchar(res[i]);
}


int main(){
    char a[MAX], b[MAX], max;
    read(a);
    read(b);
    max = cmp(a,b);
    switch(max){
        case 'a': imprime(a); break;
        case 'b': imprime(b); break;
    }
    printf("\n");
    return 0;
}