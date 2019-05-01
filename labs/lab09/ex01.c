#include "ex01aux.h"

int main(){
    int c;
    node (*head);
    debug = 0;
    head = NULL;
    while ((c = getchar())!='0'){
        head = push(head, c);
    }
    print(head);
    return 0;
}
