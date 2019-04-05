#include "aux.h"

char randleter(){
   return 'A' + (random() % 26);
}

/* descricao:data:inicio:duracao:sala:responsavel:participantes */
/*     0      1     2       3     4       5          6  7  8    */
int hh=0,mm=0;
int main(){
   for(int sala = 0;sala<max_sala;sala++){
      for(int even=0; even<max_eventos; even++){
         putchar('a');
         putchar(' ');
         for(int i=0;i<63;i++){
            putchar(randleter());
         }
         putchar(':');
      /*data*/
         printf("30122050:");
      /*inicio*/
         printf("%02d%02d:",hh,mm);
         mm++;
         if(mm==60){mm=0;hh+=1;}
         if(hh==24)hh=0;
      /*duracao*/
         printf("1:");
      /*sala*/
         printf("%d:",sala+1);
      /*responsavel*/
         for (int i = 0; i < 63; i++){
            putchar(randleter());
         }
         putchar(':');
      /*participantes*/      
         for (int i = 0; i < 63; i++){
            putchar(randleter());
         }
         putchar(':');
         for (int i = 0; i < 63; i++){
            putchar(randleter());
         }
         putchar(':');
         for (int i = 0; i < 63; i++){
            putchar(randleter());
         }
         putchar('\n');
      }
   }
   printf("l\nx\n");
}