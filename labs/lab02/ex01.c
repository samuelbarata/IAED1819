#include <stdio.h>
int main(){
    int a,b,c;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    if(a<b){
        a = b;
    }
    if(a<c){
        a = c;
    }
    printf("%d\n",a);
    return 0;
}