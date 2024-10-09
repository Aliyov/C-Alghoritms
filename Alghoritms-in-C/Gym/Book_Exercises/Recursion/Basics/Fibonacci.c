#include <stdio.h>
#include <stdlib.h>


int fibbo(int num){
	if(num==0){
		return 1;
	}
	int result = num + fibbo(num - 1);

	printf("%d\n", result);
	return result;
}

int main(){
	int num;

	printf("Enter value: ");
	scanf("%d", &num);
	
	fibbo(num);

	return 0;
}
