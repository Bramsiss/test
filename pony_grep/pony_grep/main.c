#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "regexp.h"
#include "sub_str.h"

int main(void) {
    unsigned int N = 0, i = 0;   
    char *buf, *regexp1, *regexp2, *line;
	unsigned int bufElements = 1, bufCounter = 0, strLenElements = 1, j = 0, both = 0, *strLen;
	printf("Input text for search.\nUse grep [-i] regexp for regular expression.\nInput 'exit' for finish programm.\n");
	buf = (char*) calloc (bufElements, sizeof(char));
	strLen = (unsigned int*) calloc (strLenElements, sizeof(unsigned int));
	while(1) {
		line = (char *) calloc(256, sizeof(char));
		gets(line);

		if (strcmp(line, "exit") == 0) break;
		else if (strcmp(substr(line, 0, 4), "grep") == 0) {
			if (strcmp(substr(line, 5, 3), "-i ") == 0) {
				regexp1 = strlwr(substrfrom(line, 8));
				regexp2 = strupr(substrfrom(line, 8));
				both = 1;
			} else {
				regexp1 = substrfrom(line, 5);
				both = 0;
			}
			N = 0;
			for (i = 0;i<strLenElements-1;i++) {
				line = (char*) calloc (strLen[i]+1, sizeof(char));
				for (j = 0;j<strLen[i];j++) {
					line[j] = buf[N+j];
				}
				line[strLen[i]] = '\0';
				N+=strLen[i];
				if (check_regexp(regexp1, line) && both == 0) puts(line);
				if (both == 1 && (check_regexp(regexp1, line) || check_regexp(regexp2, line))) puts(line);
				if (i != strLenElements-2) free(line);
			}
		} else {
			bufElements += (strlen(line));
			buf = (char*) realloc (buf, sizeof(char)*bufElements);
			strLen = (unsigned int*) realloc (strLen, sizeof(unsigned int)*strLenElements++);
			strLen[strLenElements-2l] = strlen(line);
			for (i = 0;i<strlen(line);i++) {
				buf[bufCounter++] = line[i];
			}
		}
		
		free(line);
	}
	free(buf);
	getchar();
	return 0;
}
