#include <stdio.h>
/*Dá Erro n sei pq*/
int main(){
    int n,i;
    float max,a,min;
    
    scanf("%d", &n);
    
    scanf("%f", &max);
    min = max;
    for(i = 1; i < n; i++){
        
        scanf("%f", &a);
        if(a>max){
            max = a;
        }
        if(a < min){
            min = a;
        }
    }
    
    printf("min: %f, max: %f\n", min, max);
    return 0;
}