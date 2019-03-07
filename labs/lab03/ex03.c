#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    cruz(n);
    return 0;
}

void cruz(int n){
    int l,c;
    char k;
    for(l = 0;l<n;l++){
        for(c = 0;c<n;c++){
            if(c+l == n-1 || c == l){k = '*';}
            else{k='-';}
            printf("%c ", k);
        }
        printf("\n");
    }
}