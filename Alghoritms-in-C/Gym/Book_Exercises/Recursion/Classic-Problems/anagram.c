#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(char *x, char *y){
	char temp = *x; 
	*x = *y;
	*y = temp;
}

void generateAnagrams(char *str, int start, int end){
	if(start == end){
		printf("%s\n", str);
	}else{
		for(int i=start; i<=end; i++){
			swap((str+start), (str+i));
			generateAnagrams(str, start+1, end);
			swap((str+start), (str+i));
		}
	}
}


int main(){
	char str[11];
	printf("Enter a string: ");
	scanf("%10s", str);

	int n = strlen(str);
	printf("All possible anagrams:\n");
	generateAnagrams(str, 0, n-1);

	return 0;
}