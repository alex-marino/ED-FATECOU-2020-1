#include <stdlib.h>
#include <string.h>

char* duplica (char* s){
	int n = strlen(s);
	char* d = (char*) malloc ((n+1)*sizeof(char));
	strcpy(d,s);
	return d;
}

