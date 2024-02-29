#ifndef PROJECT_H
#define PROJECT_H


#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

void no_prom(char **arg_vector);
int promptve(char *arg_vector[], int eCou, char **e_v);
int op_proc(char *arg_vector[], int eCou, char **e_v);
char *gev(char *name, char **e_v);
void own_env(char **e_v);

char *op_scopy(char *de, char *sr);
int op_slen(const char *sa);
char *op_sconc(char *de, char *sr);
char *op_sdup(char *str);
int op_scmp(char *m1, char *m2);
int op_sncmp(const char *m1, const char *m2, size_t n);

char *ppf(char *pth, char *fse);

char *_memset(char *pre2, char b, unsigned int n);
void *_calloc(unsigned int arr_mem, int lenz);

#endif
