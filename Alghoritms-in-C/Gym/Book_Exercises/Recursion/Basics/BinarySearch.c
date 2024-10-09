#include <stdio.h>
#include <stdlib.h>

void binary_search(int arr[],int value, int low, int high){
	
	int x = (high+low)/2;
	if(value == arr[x]){
		printf("\nValue find in %d", x);
		return;
	}
	(value < arr[x]) ? binary_search(arr, value, low, x) : binary_search(arr, value, x, high);
}
	

int main(){
	int value;
	int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	int len = sizeof(arr)/sizeof(arr[0]);

	printf("Enter value: ");
	scanf("%d", &value);
	
	int high = len;
	int low = 0;
	binary_search(arr, value, low, high);
	
	return 0;
}
