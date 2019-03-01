#include <stdio.h>

int main(){
    int n, counter;
    float acomula, num;
    scanf("%d",&n);/*n+ de numeros*/
    for(counter = 1;counter <= n;counter++){
        scanf("%f",&num);
        acomula += num;
    }
    printf("%.2f\n", acomula/n);
    return 0;
}