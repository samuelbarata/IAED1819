#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    piramide(n);
    return 0;
}

void piramide(int n){
    int linhas, carac, next;
    for(linhas = 1; linhas <=n; linhas++){
        next = 0;
        for(carac = 1; carac <= n*2-1; carac++){
            if(linhas+n-1 < carac || (carac < n)&&(carac+linhas<=n)){
                printf("  ");
            }
            else{
                if(carac <= n)next++;
                else next--;
                printf("%d ",next);
                }
        }
        printf("\n");
    }
}