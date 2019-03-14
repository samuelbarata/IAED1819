#include <stdio.h>
#define MAX 80

int main(){
    int st[MAX], i,j, end=1;
    scanf("%s", st);
    for(i = 0; st[i] != EOF; i++){printf("%d",i);}
    for(j = 0; j == i; j++){
        if (st[i] != st[j]){
            end = 0;
        }
        i--;
    }
    if(end){
        printf("yes\n");
        return 0;
    }
    printf("no\n");
    return 0;
}