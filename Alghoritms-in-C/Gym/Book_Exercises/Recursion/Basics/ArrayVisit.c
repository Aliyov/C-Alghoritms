#include <stdio.h>
#include <stdlib.h>

int visit(int array[], int size){
	if(size < 0){
		return 1;
	}
	
	printf("%d\n", array[size]);
	return visit(array,size-1);
}
int main(){
	int array[] = {2,4,6,8,10,12,14};
	int size = sizeof(array)/sizeof(array[0])-1;
	visit(array, size);
	return 0;
}
