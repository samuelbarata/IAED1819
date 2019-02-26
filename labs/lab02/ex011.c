#include <stdio.h>

int main(){
    int m,n;
    scanf("%d", &m);
    scanf("%d", &n);
    if (m>n){
        printf("%d\n%d\n", n,m);
    }
    else{printf("%d\n%d\n", m,n);}
    return 0;
}