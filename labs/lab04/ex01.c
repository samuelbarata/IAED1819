#include <stdio.h>
#define VECMAX 100

int main(){
    int n, i, vec[VECMAX],k;
    scanf("%d", &n);
    for(i = 0;i<n;i++){
        scanf("%d", &vec[i]);
    }
    for(i=0;i<n;i++){
        for(k=0;k<vec[i];k++){
            printf("*");
        }
        printf("\n");
    }
}