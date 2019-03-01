#include <stdio.h>

int main(){
    int a,count,d;
    float b,c;
    scanf("%d", &a);
    count=0;
    for(b=1;b<=a;b++){
        c = a/b;
        d = a/b;
        if(d == c){
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}