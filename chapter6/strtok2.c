#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int contains(const char* delim, char check) {
	for(int i = 0; i < strlen(delim); i++) {
		if(check == delim[i]) {
			return 1;
		}
	}
	return 0;
}

char* mystrtok(char* str, const char* delim) {
	static int pos;
	static char* stored_str;

	if(str != NULL) {
		stored_str = str;
		pos = 0;
	}

	char* newStr = (char*) malloc(strlen(stored_str));
	for(int i = pos, j = 0; i <= strlen(stored_str); i++, j++) {
		if(contains(delim, stored_str[i]) || stored_str[i] == '\0') {
			pos++;
			newStr[j] = '\0';
			return newStr;
		}
		pos++;
		newStr[j] = stored_str[i];
	}

	return NULL;
}


int main(int argc, char const *argv[])
{
	char delimeters[] = "?,|";
	char str[] = "Oh hi! Please, split with ?, commas, pipes|and|nothing|else.";
	char *splitting;

	splitting = mystrtok(str, delimeters);
	while(splitting != NULL) {
		printf("%s\n", splitting);;
		splitting = mystrtok(NULL, delimeters);	
	}

	printf("\n");

	char *splitting2;

	splitting2 = strtok(str, delimeters);
	while(splitting2 != NULL) {
		printf("%s\n", splitting2);;
		splitting2 = strtok(NULL, delimeters);	
	}

	
	return 0;
}