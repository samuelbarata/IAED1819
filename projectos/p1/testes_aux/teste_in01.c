#include "aux.h"

char randleter(){
   return 'A' + (random() % 26);
}

/* descricao:data:inicio:duracao:sala:responsavel:participantes */
/*     0      1     2       3     4       5          6  7  8    */
int dia=0,mes=0,ano=2019;
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
         printf("%02d%02d%04d:", dia,mes,ano);
         dia++;
         if(dia == 30){dia=0;mes++;}
         if(mes == 30){ano++;mes=0;}
      /*inicio*/
         printf("2359:");
      /*duracao*/
         printf("1440:");
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