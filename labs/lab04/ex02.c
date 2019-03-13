#include <stdio.h>
#define VECMAX 100

int main(){
    int n, i, vec[VECMAX], linha,max=0;
    scanf("%d", &n);
    for(i = 0;i<n;i++){
        scanf("%d", &vec[i]);
    }
    for(i=0;i<n;i++){
        if(vec[i]>max)max=vec[i];
    }
    for(linha=1;linha<=max;linha++){
        for(i=0;i<n;i++){
            if(vec[i]>=linha){printf("*");}
            else{printf(" ");}
        }
        printf("\n");
    }
    return 0;
}