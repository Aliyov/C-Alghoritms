#include <stdio.h>

int gcd(int x, int y){
	if(y == 0){
		return x;
	}
	
	int z = x%y;
	return gcd(y,z);
}


int main(){
	int x, y;
	printf("Enter two numbers: ");
	scanf("%d%d", &x, &y);
	
	int answer = gcd(x,y);
	printf("\nAnswer: %d", answer);
	
	return 0;
}
