///---------------------------------------------------------------editor size---------------------------------------------------------------\\\
#include <stdio.h>
/*
commands to dir:    cd .. && cd .. && cd media/psf/Home/Desktop/My\ Cloud\ Offline\ Files/IST/1Ano/IAED
base directory:     /media/psf/Home/Desktop/My Cloud Offline Files/IST/1Ano/IAED/
compile file:       gcc -o [output_file_name] [file_name.c]
run file:           ./[output_file_name]
*/

#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

void name()
{
	printf(" ________  ________  _____ ______   ___  ___  _______   ___\n");
	printf("|\\   ____\\|\\   __  \\|\\   _ \\  _   \\|\\  \\|\\  \\|\\  ___ \\ |\\  \\\n");
	printf("\\ \\  \\___|\\ \\  \\|\\  \\ \\  \\\\\\__\\ \\  \\ \\  \\\\\\  \\ \\   __/|\\ \\  \\\n");
	printf(" \\ \\_____  \\ \\   __  \\ \\  \\\\|__| \\  \\ \\  \\\\\\  \\ \\  \\_|/_\\ \\  \\\n");
	printf("  \\|____|\\  \\ \\  \\ \\  \\ \\  \\    \\ \\  \\ \\  \\\\\\  \\ \\  \\_|\\ \\ \\  \\____\n");
	printf("    ____\\_\\  \\ \\__\\ \\__\\ \\__\\    \\ \\__\\ \\_______\\ \\_______\\ \\_______\\\n");
	printf("   |\\_________\\|__|\\|__|\\|__|     \\|__|\\|_______|\\|_______|\\|_______|\n");
	printf("   \\|_________|\n");
	printf("\n");
	printf(" ________  ________  ________  ________  _________  ________\n");
	printf("|\\   __  \\|\\   __  \\|\\   __  \\|\\   __  \\|\\___   ___\\\\   __  \\\n");
	printf("\\ \\  \\|\\ /\\ \\  \\|\\  \\ \\  \\|\\  \\ \\  \\|\\  \\|___ \\  \\_\\ \\  \\|\\  \\\n");
	printf(" \\ \\   __  \\ \\   __  \\ \\   _  _\\ \\   __  \\   \\ \\  \\ \\ \\   __  \\\n");
	printf("  \\ \\  \\|\\  \\ \\  \\ \\  \\ \\  \\\\  \\\\ \\  \\ \\  \\   \\ \\  \\ \\ \\  \\ \\  \\\n");
	printf("   \\ \\_______\\ \\__\\ \\__\\ \\__\\\\ _\\\\ \\__\\ \\__\\   \\ \\__\\ \\ \\__\\ \\__\\\n");
	printf("    \\|_______|\\|__|\\|__|\\|__|\\|__|\\|__|\\|__|    \\|__|  \\|__|\\|__|\n\n");
	printf("Samuel Barata 2017\n\n");
	printf("Press enter to continue\n\n");
	getchar();
}



void beg(){
    /* https://ozh.github.io/ascii-tables/
     1    Printf
     2    \
     3    Variables
     4    Scanf
     5    If
     6    Operators
     7    Switch case
     8    Loops
	 9	  Conditions
	 10   Arrays
	 11   Procedimentos
	 12   Pointers
	 13   Strings
	 14   Struct
     
     0    Exit
     */
	getchar();
	printf("//====[]===============\\\\\n||  1 || Printf        ||\n||  2 || \\             ||\n||  3 || Variables     ||\n||  4 || Scanf         ||\n||  5 || If            ||\n||  6 || Operators     ||\n||  7 || Switch case   ||\n||  8 || Loops         ||\n||  9 || Conditions    ||\n|| 10 || Arrays        ||\n|| 11 || Procedimentos ||\n|| 12 || Pointers      ||\n|| 13 || Strings       ||\n|| 14 || Struct        ||\n||    ||               ||\n||  0 || Exit          ||\n\\\\====[]===============//\n");
}
int fmlt(float a, float b){
    printf("%f * %f = %f\n",a,b,a*b);
    return (a*b);
}
int asum (int MyArray[], int size){
    int sum = 0;
    for (int i=0; i < size; i++){
        sum += MyArray[i];//== sum = sum + MyArray[i]
    }
    return sum;
}
int somatorio(){
    int in1=0, in2=0, maior=0, menor=0, soma=0;
    printf("Introduz 2 numeros sff\n");
    scanf(" %d %d", &in1, &in2);
    if(in1<in2){
        maior=in2;
        menor=in1;
    }
    else if (in1>in2){
        maior=in1;
        menor=in2;
    }
    else{
        printf("WHYYYYYYYYYYY???");
        return(500);
    }
    do {
        printf("%d + ", menor);
        soma+=menor;
        menor++;
    }while (maior!=menor);
    printf("%d ", menor);
    soma+=menor;
    printf("= %d :)", soma);
    return (soma);
}
void void_ex(){
    printf("I'm a void\n");
    printf("I'm a void\n");
    printf("I'm a void\n");
}
void getValue(int *my_pointer){
	*my_pointer=10000;
	return;
}
struct aluno {
    int id;
    char name[20];
    float media;
};
union myUnion {
    int myInt;
    char myChar;
};
void cont(){
	printf("Press return to continue...\n\n");
	getchar();
}

void mainc(){
    char my_String[/*numero de caracteres se em branco = 255*/] = {'S', 'a', 'm', 'u', 'e', 'l', '\0'}; //  \0 --> null --> define o fim do Array
    char my_Name[6] = "Samuel";
    char string1[12] = "Hello";
    char string2[12] = "World!";
    char string3[12];
    int classs=0;
    int age, i8;
    long int sec;
    int array[3]={12,5,2000};
    struct aluno samuel;
    samuel.id = 1837;
    strcpy(samuel.name,"Samuel Barata");
    samuel.media = 13.45;
    /*union myUnion lol;
    lol.myChar = 9;
    lol.myInt = 4;*/
    do{
        beg();
        printf("\nChoose a number:\n");
        scanf(" %d", &classs);
        switch(classs){
            case 0:
                break;
            case 1:
                //Escrever
                printf("\nPara escrever texto usa-se\nprintf(\"\");\n");
				cont();
                break;
            case 2:
                ///Comandos
                /*
                 +----+----------------------+
                 | \n | nova linha           |
                 | \t | tabulacao horizontal |
                 | \v | tabulacao vertical   |
                 | %% | %                    |
                 | \\ | \                    |
                 | \' | '                    |
                 | \" | "                    |
                 | \? | ?                    |
                 +----+----------------------+
                 */
                printf("+----+----------------------+\n| \\n | nova linha           |\n| \\t | tabulacao horizontal |\n| \\v | tabulacao vertical   |\n| %%%% | %%                    |\n| \\\\ | \\                    |\n| \\\' | \'                    |\n| \\\" | \"                    |\n| \\\? | \?                    |\n+----+----------------------+\n");
                printf("Ver tabulacoes.c\n\n");
                cont();
                break;
            case 3:
                //definir variaveis
                //int ar = 23;                                                    //numero inteiro    %d
                //char br = 'a';                                                  //caracteres        %c        --> para string %s
                //float cr = 0.425346;                                            //decimal            %f
                //double dr = 0.2384956786534563789456234876523789569;            //double float        %lf *large float
                printf("\nTipos de variaveis: int, char, float, double\n");
                printf("Ver soma3.c\n\n");
                printf("int\t\t numero inteiro (%%d)\nchar\t\t caracter *** = 'apenas um caracter dentro de single quotes'(%%c)\nfloat\t\t decimal (%%f)\nbool\t\t boolean (0 ou 1)\ndouble float\t long float (%%lf))\n\n");
                printf("If this variables are declares inside int main() they are Local Variables and can only be used inside main(), if we want to use them between functions, we have to declare them outside (Global Variables)\n\n");
                cont();
                break;
            case 4:
                ///pedir e devolver algo
                printf("printf(\"\\nhow old are you?\\n\");\nscanf(\"%%d\",&age);\nsec=(age*365*24*3600*3600);\nprintf(\"You are %%ld seconds old!!\\n\", sec);\n\n");
                printf("\nhow old are you?\n");
                scanf("%d",&age);                                                // ,&age    significa que o valor de %d vai sr atribuido ‡ variavel age
                sec=(age*365*24*60*60);                                   	     //            converte anos em seguntos
                printf("You are %ld seconds old!!\n", sec);                      // , age    significa que o valor devolvido vai ser o da variavel age
                cont();
                break;
            case 5:
                ///if statement
                printf("if (condicao) {...}\n");
                printf("if (input==0){\n\tprintf(\"the number is 0\\n\");\n}\nelse if (input==1){\n\tprintf(\"the number is 1\\n\");\n}\nelse{\n\tprintf(\"the number is greater then 1\\n\");\n}\n\n");
                int ifss;
                printf("type a number\n");
                scanf(" %d",&ifss);
                if (ifss==0){
                    printf("the number is 0\n");
                }
                else if (ifss==1){
                    printf("the number is 1\n");
                }
                else{
                    printf("the number is greater then 1\n");
                }
                cont();
                break;
            case 6:
                ///Operators
                /*
                 +----+----------------------------+
                 | +  |  Soma                      |
                 | -  |  Subtraco                  |
                 | /  |  Divisao                   |
                 | *  |  Multiplicacao             |
                 | =  |  A=B A assume o valor de B |
                 | == |  Verifica se A==B          |
                 | != |  Diferente                 |
                 | >  |  Maior                     |
                 | >= |  Maior ou Igual            |
                 | <  |  Menor                     |
                 | <= |  Menor ou Igual            |
                 | <> |  Diferente                 |
                 | ~  |  Negacao                   |
                 | && |  AND                       |
                 | || |  OR                        |
                 | !  |  NOT                       |
                 +----+----------------------------+
                 */
                printf("+----+----------------------------+\n| +  |  Soma                      |\n| -  |  Subtraco                  |\n| /  |  Divisao                   |\n| *  |  Multiplicacao             |\n| =  |  A=B A assume o valor de B |\n| == |  Verifica se A==B          |\n| != |  Diferente                 |\n| >  |  Maior                     |\n| >= |  Maior ou Igual            |\n| <  |  Menor                     |\n| <= |  Menor ou Igual            |\n| <> |  Diferente                 |\n| ~  |  Negacao                   |\n| && |  AND                       |\n| || |  OR                        |\n| !  |  NOT                       |\n+----+----------------------------+\n");
                cont();
                break;
            case 7:
                ///Switch Case
                printf("int day=8;\nwhile(day!=0){\n\tprintf(\"Escolhe um numero de 0 a 7: \");\n\tscanf(\" %%d\", &day);\n\tswitch(day){\n\t\tcase 1:\n\t\t\tprintf(\"Domingo\\n\\n\");\n\t\tbreak;\n\t\tcase 2:\n\t\t\tprintf(\"Segunda-Feira\\n\\n\");\n\t\tbreak;\n\t\tcase 3:\n\t\t\tprintf(\"Terca-Feira\\n\\n\");\n\t\tbreak;\n\t\tcase 4:\n\t\t\tprintf(\"Quarta-Feira\\n\\n\");\n\t\tbreak;\n\t\tcase 5:\n\t\t\tprintf(\"Quinta-Feira\\n\\n\");\n\t\tbreak;\n\t\tcase 6:\n\t\t\tprintf(\"Sexta-Feira\\n\\n\");\n\t\tbreak;\n\t\tcase 7:\n\t\t\tprintf(\"Sabado\\n\\n\");\n\t\tbreak;\n\t}\n}\n");
                int day=8;
                while(day!=0){
                    printf("Escolhe um numero de 0 a 7: ");
                    scanf(" %d", &day);
                    switch(day){
                        case 1:
                            printf("Domingo\n\n");
                            break;
                        case 2:
                            printf("Segunda-Feira\n\n");
                            break;
                        case 3:
                            printf("Terca-Feira\n\n");
                            break;
                        case 4:
                            printf("Quarta-Feira\n\n");
                            break;
                        case 5:
                            printf("Quinta-Feira\n\n");
                            break;
                        case 6:
                            printf("Sexta-Feira\n\n");
                            break;
                        case 7:
                            printf("Sabado\n\n");
                            break;
                    }
                }
                printf("\n");
                break;
            case 8:
                ///Loops
                printf("+======================================+===========================================================+\n|              Loop types              |                        Description                        |\n+======================================+===========================================================+\n| while(Condition){...}                | Repete enquanto a condicao for verdadeira                 |\n+--------------------------------------+-----------------------------------------------------------+\n| do{...}while(Condition);             | Igual ao While mas a condicao e apenas avaliada no final  |\n+--------------------------------------+-----------------------------------------------------------+\n| for(init; condition; increment){...} | press 1 for more information or 0 to exit                 |\n+--------------------------------------+-----------------------------------------------------------+\n\n");
                scanf(" %d", &i8);
                switch (i8){
                    case 11:
                        printf("Append \"-std=c99\" to compiler options\n");
                    case 1:
                        printf("\nMore Info:\ninit:\t\tint i=0\t\t--> The first value\ncondition:\t(i < 10)\t--> When to stop\nincrement:\ti++\t\t--> Counting\n\n");
                        printf("Example:\nfor(int i=0; i<=10; i++){\n\tprintf(\"%%d\",i);\n}\n");
                        for(int i=0; i<=10; i++){ //compiler options: -std=c99
                            printf("%d ",i);
                        }
                        printf("\n\n");
                        break;
                    default:
                        break;
                }
                cont();
                break;
            case 9:
                ///Conditions
                //(/*Logical expression*/) ? (/*If true*/) : (/*If false*/);
                printf("(Logical expression) \? (If true) : (If false)\n\n");
                printf("scanf(\" %%d%%d\", &a, &b);\nc = (a<b) \? b : a\nprintf(\"%%d  is THE GREATEST\\n\", c);\n\n");
                printf("Insert 2 numbers\n");
                int a,b,c;
                scanf(" %d %d", &a, &b);
                c = (a<b) ? b : a;
                printf("%d is THE GREATEST\n",c);
                cont();
                break;
            case 10:
                ///ARRAYS
                printf("Single Dimension arrays:\n");
                printf("int array[3]={12,5,2000}\nfor(int i=0; i<3;i++){\n\tprintf(\"Array[%%d] = %%d\\n\", i, array[i]);\n}\n\n");
                //int array[3]={12,5,2000};    //Declarado no inÌcio
                for(int i=0; i<3;i++){
                    printf("Array[%d] = %d\n", i, array[i]);
                }
                cont();
				getchar();
                printf("Multiple Dimension arrays:\n\n");
                printf("int array2 [2] [3]= {//2 rows 3 collums\n\t{1,5,7},\n\t{3,58,4},\n};\nfor(int i=0; i<2; i++){\n\tfor(int f=0; f<3; f++){\n\t\tprintf(\"array2[%%d][%%d] = %%d\\n\", i,f,array2[i][f]);\n\t}\n}\n");
                int array2 [2] [3]= {//2 rows 3 collums
                    {1,5,7},    //row0
                    {3,58,4},    //row1
                };
                for(int i=0; i<2; i++){
                    for(int f=0; f<3; f++){
                        printf("array2[%d][%d] = %d\n", i,f,array2[i][f]);
                    }
                }
                cont();
                printf("\nPara somar os valores todos de um array{12,5,2000}:\n\nint sum = 0;\nfor (int i=0; i < size; i++){\n\tsum += MyArray[i];\n}\n");
                int sum = asum(array,3);
                printf("sum = %d\n\n", sum);
                cont();
                break;
            case 11:
                ///VOID
                printf("\nVoid e uma função e pode ser chamada ao longo do codigo, sao usadas para repetir algo varias vezes de modo a minimizar a escrita\n\nvoid void_ex(){\n\tprintf(\"I'm a void\\n\");\n\tprintf(\"I'm a void\\n\");\n\tprintf(\"I'm a void\\n\");\n}\nvoid_ex();\n\n");
                void_ex();
                printf("\n\n");
				cont();
                break;
            case 12:
                ///POINTERS
				printf("A pointer is a variable whose value is the address of another variable\n\n");
				printf("int val = 30;\nint *pointer_p = &val;\n");
				int val = 30;
				int *pointer_p = &val; //*sicgifica que vamos declarar um pointer (adress of another variable (
				printf("Adress of val is: %x = pointer_p: %x\n\n",&val,pointer_p); //Adress where the variable is stored (Hexadeccimal)
				cont();
				getchar();
				printf("Usar o asterisco motra o valor guardado naquele local\nprintf(\"%%d\",*pointer_p);\n%d\n\n",*pointer_p);
				cont();
				printf("Também se pode usar o mesmo com Arrays:\n\nint val_array[3]={3,4,5};\nint *pointer_array[3];\nfor (int i = 0; i<3; i++){\n\tpointer_array[i] = &val_array[i];\n}\nfor (int i = 0; i<3; i++){ \n\tprintf(\"pointer_array[%%d] = %%d\\n\",i,*pointer_array[i]);\n}\n");
				int val_array[3]={3,4,5};
				int *pointer_array[3];
				for (int i = 0; i<3; i++){
					pointer_array[i] = &val_array[i]; //assign the adress os array elements
				}
				for (int i = 0; i<3; i++){
					printf("pointer_array[%d] = %d\n",i,*pointer_array[i]);
				}
                cont();
                break;
            case 13:
                ///STRING
                printf("char my_String[7] = {'S', 'a', 'm', 'u', 'e', 'l', '\\0'};\nchar my_Name[] = \"Samuel\";\nprintf(\"my_String = %%s\\nmy_Name = %%s\\n\", my_String, my_Name);\n\n");
                //char my_String[7] = {'S', 'a', 'm', 'u', 'e', 'l', '\0'}; //  \0 --> null --> define o fim do Array
                //char my_Name[] = "Samuel";
                printf("my_String = %s\nmy_Name = %s\n\n", my_String, my_Name);
                printf("#include <string.h>\n");
                printf("char string1[12] = \"Hello\";\nchar string2[12] = \"World!\";\nchar string3[12];\n");
                //char string1[12] = "Hello";
                //char string2[12] = "World!";
                //char string3[12];
                printf("Para copiar o valor de uma variavel (string 1) para outra (string 3) usa-se strcpy(destinations,source);\n\nstrcpy(string3, string1);\n");
                strcpy(string3, string1); ///strcpy(dest,source)
                printf("%s\n\n", string3);
                printf("Para juntar 2 Strings usa-se strcat(string1, string2)\nprintf(\"%%s\", string1);\n");
                strcat(string1, string2); ///add string 2 to string 1
                printf("%s\n\n", string1);
                
                printf("Para ver o comprimento de uma string usa-se strlen(string_name);\nint length_string1 = strlen(string1);\nprintf(\"%%d\", length_string1);\n");
                unsigned long int length_string1 = strlen(string1); ///strlen(string) = number of charecters in the string
				printf("%lu\n\n", length_string1);
                cont();
                break;
            case 14:
                ///STRUCT
                printf("As estroturas definem-se fora do main assim:\nstruct aluno {\n\tint id;\n\t\n\tchar name[20];\n\tfloat media;\n};\n\nPara criar um novo aluno usa-se:\nstruct aluno samuel;\n\nPara atribuir valores ao \"Samuel\" usa-se:\nsamuel.id = 1837;\nstrcpy(samuel.name,\"Samuel Barata\");\nsamuel.media = 13.45;\n\n");
                cont();
                break;
            /*case 15:
                ///Unions
                
                break;*/
            default:
				///404
                printf("\nError 404: number not found\n");
				getchar();
                break;
        }
    } while (classs!=0);
    name();
	//putc(<#int#>, <#FILE *#>);
	//puts
	//gets
    //returnfname
    //calculadora
    //maior
    //string
}





void variable_types(){
    int inteiro = 0;
    float decimal = 0.01;
    
}

int main(){
    name();
    mainc();
    return 0;
}