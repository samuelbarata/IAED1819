#include "ex02.h"

int main(){
	int i, j, check = 1,temp;
	stack k;
	init(&k);
	for(i=0;(j = getchar())!=EOF && j!='\n';i++){
		if(j == '(' || j == '[' || j == '{')
			push(k, j);
		if(j == ')' || j == ']' || j == '}'){
			if(is_empty(k)){
				printf("no");
				return 0;
			}
			temp = pop(k);
			if(temp == '('){
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
			printf("no");
			return 0;
		}
	}
	if(is_empty(k))
		printf("yes");
	printf("no");
	return 0;
}
