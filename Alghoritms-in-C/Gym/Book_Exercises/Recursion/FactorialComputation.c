#include <stdio.h>
#include <stdlib.h>

int factor(int num){
	if(num == 0){
		return 1;
	}
	printf("%d\n", num);
	return num * factor(num-1);
}


int main(){
	int num;
	printf("Enter value: ");
	scanf("%d", &num);	
	
	int result = factor(num);
	printf("Result: %d", result);
	return 0;

}
