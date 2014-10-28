#ifndef STR_H
#define STR_H

/* String Replace. */
char *strrep(char *orig, char *rep, char *with);

/* String split into array of strings. */
char **strsplit(char *instr, const char *delim);

#endif /* STR_H */
