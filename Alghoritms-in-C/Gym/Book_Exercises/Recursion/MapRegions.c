#include <stdio.h>
#include <stdlib.h>

#define R 20
#define C 20

void printFile(FILE *fp){
	char ch;
	while(fscanf(fp,"%c", &ch)!= EOF){
		printf("%c", ch);
	}
}

int checkBorder(FILE *fp, int row, int col){
	for(int i=row; i<=row; i++){
		for(int j=col; j<=col+1;


void processFile(FILE *fp){
	int counter = 1;
	char ch;
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			fscanf(fp, "%c", &ch);
			if(ch == '.'){
				int number = checkBorder(fp, i, j);
				if(number == 1){
					printf("%d", counter);
				}else{
					printf("%d", counter);
					counter++;
				}
			}
			printf("%c", ch);
		}
		
	}
}


int main(){
	FILE *fp = fopen("map.txt", "r");
	if(fp == NULL){
		perror("\nCant open the file");
		exit(1);
	}
	
	processFile(fp);

	return 0;
}
