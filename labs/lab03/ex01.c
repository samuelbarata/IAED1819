#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    quadrado(n);
    return 0;
}

void quadrado(int n){
    int a,b,counter;
    for (a = 1; a<=n; a++){
        b = a;
        for (counter = 0; counter<n; counter++){
            printf("%d\t",b);
            b++;
        }
        printf("\n");
    }
}