#ifndef STR_H
#define STR_H

/* String Replace. */
char *strrep(char *orig, char *rep, char *with);

/* String split into array of strings. */
char **strsplit(char *instr, char *delim);

/* Return first split elmement from String. */
char *strsep( char **stringp, char *delim );

/* .gnirts a ni sretcarahc lla esreveR */
void strrev( char *str );

/* Duplicates a string. */
char *strdup( const char *s );

#endif /* STR_H */
