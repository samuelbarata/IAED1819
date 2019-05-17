#include <stdio.h>
#include <stdlib.h>

#define max_str 1021    // 1 -> 1022
#define local   509     // 1 -> 510
#define dominio 509     // 1 -> 510
#define max_phone 62    // 1 -> 63
#define n 100000        // 0 -> fds, n exagerem...


/*gera uma letra A-Z ao calhas*/
char randleter(){
    return 'A' + (random() % 26);
}

/*cria um comando ao calhas com maior probabilidade de sair 'a'*/
char randcmd(){
    int x = (random() % 70);
    switch(x){
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
    unsigned size;
    for(int i = 0;i < n;i++){
        printf("%c", c=randcmd());
        if(c == 'a' | c == 'p' | c =='r' | c == 'e'){
            printf(" ");
            size = random()%max_str;
            for(int k = 0; k<size+1; k++){
                putchar(randleter());
            }
            
        }
        if(c == 'a'|c=='e'){
            printf(" ");
            size = random() % local;
            for(int k=0; k<size+1; k++){
                putchar(randleter());
            }
            printf("@");
        }
        if (c == 'a' |c == 'e'|c=='c'){
            if(c=='c')printf(" ");
            size = random() % dominio;
            for(int k=0; k<size+1; k++){
                putchar(randleter());
            }
        }
        if(c=='a'){
            printf(" ");
            size = random() % max_phone;
            for(int k=0; k<size+1; k++){
                putchar(randleter());
            }
        }
        printf("\n");
    }
    printf("l\n");
    printf("x\n");
}
