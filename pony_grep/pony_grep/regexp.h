#ifndef REGEXP_H
#define REGEXP_H

int check_regexp(char *regexp, char *line);
int check_left(char *regexp, char *line);
int check_star(int s, char *regexp, char *line);

#endif
