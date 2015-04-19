#include "sub_str.h"

char *substr(char *source, int start, int length) {
	int i = 0, j = 0;
	char *res = (char*) calloc (length+1, sizeof(char));
	for (i = start;i<start+length;i++) res[j++] = source[i];
	res[j] = '\0';
	return res;
}
char *substrfrom(char *source, int start) {
	int i = start, j = 0;
	char *res = (char*) calloc (1, sizeof(char));
	while(source[i] != '\0') {
		res[j++] = source[i++];
		res = (char*) realloc (res, sizeof(char)*(j+1));
	}
	res[j] = '\0';
	return res;
}
