#include <stdio.h>
#include <stdlib.h>

#define max_str 1022    // 1 -> 1022
#define local   510     // 1 -> 510
#define dominio 1       // 1 -> 510
#define max_phone 63    // 1 -> 63
#define n 10000         // 0 -> fds, n exagerem...


/*gera uma letra A-Z ao calhas*/
char randleter(){
    return 'A' + (random() % 26);
}

/*cria um comando ao calhas com maior probabilidade de sair 'a'*/
char randcmd(){
    int x = (random() % 70);
    switch(x){
        case 2:
            return 'l';
        case 3:
        case 4:
        case 5:
            return 'p';
        case 6:
        case 7:
        case 8:
        case 0:
        case 1:
        case 15:
        case 16:
        case 17:
            return 'r';
        case 9:
        case 10:
        case 11:
        case 18:
        case 19:
        case 20:
            return 'e';
        case 12:
        case 13:
        case 14:
            return 'c';
        default:
            return 'a';
   }
}

/*gera n inputs para o projeto*/
int main(){
    char c;
    for(int i = 0;i < n;i++){
        printf("%c", c=randcmd());
        if(c == 'a' | c == 'p' | c =='r' | c == 'e'){
            printf(" ");
            for(int k = 0; k<max_str; k++){
                putchar(randleter());
            }
            
        }
        if(c == 'a'|c=='e'){
            printf(" ");
            for(int k=0; k<local; k++){
                putchar(randleter());
            }
            printf("@");
        }
        if (c == 'a' |c == 'e'|c=='c'){
            if(c=='c')printf(" ");
            for(int k=0; k<dominio; k++){
                putchar(randleter());
            }
        }
        if(c=='a'){
            printf(" ");
            for(int k=0; k<max_phone; k++){
                putchar(randleter());
            }
        }
        printf("\n");
    }
    printf("l\n");
    printf("x\n");
}
