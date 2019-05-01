#include "ex01aux.h"
/*/./../../compile.sh -Y ex01 ex01aux.c/*/

int main(){
    int c;
    node (*head);
    debug = 0;
    head = NULL;
    scanf("%d",&c);
    while (c!=0){
        head = push(head, c);
        scanf("%d",&c);
    }
    print(head);
    destroy(head);
    return 0;
}
