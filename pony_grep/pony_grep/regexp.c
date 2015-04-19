#include "regexp.h"

int check_regexp(char *regexp, char *line) {
	if (regexp[0] == '^') return check_left(regexp+1, line);
	do {
		if (check_left(regexp, line)) return 1;
	} while (*line++ != '\0');
	return 0;
}
int check_left(char *regexp, char *line) {
	if (regexp[0] == '\0') return 1;
	if (regexp[1] == '*') return check_star (regexp[0], regexp+2, line);
	if (regexp[0] == '$' && regexp[1] == '\0') return *line == '\0';
	if (*line != '\0' && (regexp[0] == '.' || regexp[0] == *line)) return check_left(regexp+1, line+1);
	return 0;
}
int check_star (int s, char *regexp, char *line) {
	do {
		if (check_left(regexp, line)) return 1;
	} while(*line != '\0' && (*line++ == s || s == '.'));
	return 0;
}
