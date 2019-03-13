#include <stdio.h>
#define VECMAX 100

int main(){
    int n, i, vec[VECMAX], linha;
    scanf("%d", &n);
    for(i = 0;i<n;i++){
        scanf("%d", &vec[i]);
    }
    for(linha=1;linha<=n;linha++){
        for(i=0;i<n;i++){
            if(vec[i]<=linha){printf("*");}
            else{printf(" ");}
        }
        printf("\n");
    }
    return 0;
}