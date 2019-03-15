#include <stdio.h>
#define MAX 80

int main(){
    int i,j, end=1;
    char st[MAX];
    scanf("%s", st);
    for(i = 0; st[i] != '\0'; i++){}
    i--;
    for(j = 0; j < i; ){
        if (st[i] != st[j]){
            end = 0;
            break;
        }
        i--;
        j++;
    }
    if(end){
        printf("yes\n");
        return 0;
    }
    printf("no\n");
    return 0;
}