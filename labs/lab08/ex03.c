#include "ex02.h"

int main(){
	int j, check = 1, temp;
	stack k;
	init(&k);
	while((j = getchar())!=EOF && j!='\n'){
		if(j == '(' || j == '[' || j == '{')
			push(&k, j);
		else if(j == ')' || j == ']' || j == '}'){
			temp = pop(&k);
			if(temp==0){
				check = 0;
			}
			else if(temp == '('){
				if(j!=')'){
					check = 0;
				}
			}
			else if(temp == '['){
				if(j!=']')
					check = 0;
			}
			else if(temp == '{'){
				if(j!='}')
					check = 0;
			}
		}
		if(!check){
			printf("no\n");
			destroy(&k);
			return 0;
		}
	}
	if(is_empty(&k)){
		printf("yes\n");
		destroy(&k);
		return 0;
	}
	printf("no\n");
	destroy(&k);
	return 0;
}
