#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void generateCombi(char **matches, int matchCount, char *result, int level){
	if(level == matchCount){
		result[level] = '\0';
		printf("%s\n", result);
		return;
	}

	for(int i=0; matches[level][i] != '\0'; i++){
		result[level] = matches[level][i];
		generateCombi(matches, matchCount, result, level+1);
	}
}

int main(){
	FILE *fp = fopen("football.txt", "r");
	if(fp == NULL){
		perror("\nCant open the file\n");
		return 1;
	}

	char **matches = (char**)malloc(100 * sizeof(char*));
	int matchCount = 0;
	char line[100];

	while(fgets(line, sizeof(line), fp) != NULL){
		line[strcspn(line, "\n")] = '\0';
		matches[matchCount] = strdup(line);
		matchCount++;
	}
	
	fclose(fp);

	char *result = malloc((matchCount+1) * sizeof(char));

	generateCombi(matches, matchCount, result, 0);

	for(int i=0; i<matchCount; i++){
		free(matches[i]);
	}

	free(matches);
	free(result);
	
	return 0;
}
