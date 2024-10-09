#include <stdio.h>
#include <stdlib.h>


int fibbo(int num){
	if(num==0 || num == 1){
		return num;
	}
	int result = fibbo(num - 1) + fibbo(num - 2);

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
