#include <stdio.h>

int main(){
    int n,counter, digit;
    scanf("%d",&n);
    digit = 0;
    for(counter = 0; n>0; counter++){
        digit+=n%10;
        n/=10;
    }
    printf("%d\n%d\n",counter, digit);
    return 0;
}