#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>
#include "macro.h"

extern char **environ;


/**
 * struct sh_dt - global ds
 * @line: the line inp
 * @ags: the ags token
 * @errmg: the global paz
 * @com: the parsed com
 * @idd: the com idd
 * @oldpwd: the old paz
 * @envt: the envt
 *
 */
typedef struct sh_dt
{
	char *line;
	char **ags;
	char *com;
	char *errmg;
	char *oldpwd;
	unsigned long int idd;
	char *envt;
} sh_t;


/**
 * struct bt_in - Manage the bt_in functions
 * @com: the command line on string form
 * @func: the associated function
 */
typedef struct bt_in
{
	char *com;
	int (*func)(sh_t *dt);
} blt_t;


int re_ne(sh_t *);
int sp_ne(sh_t *);
int pa_ne(sh_t *);
int p_md(sh_t *);

char *ze_rep(char *sng);
char *ze_conc(char *fs, char *se);
int ze_siz(char *sng);
char *ze_char(char *sng, char cze);
int ze_comp(char *sn1, char *sn2);

char *ze_copy(char *dst, char *src);

void *ze_ralloc(void *pr, unsigned int osz, unsigned int nsz);
char *ze_mmst(char *s, char bte, unsigned int numb);
char *ze_mmcopy(char *dst, char *src, unsigned int numb);
int ze_free(sh_t *);

void *fill_ds(void *apa, int elem, unsigned int sze);
void sig_hand(int signo);
char *ze_goev(char *pnme);
void idx_c(sh_t *dt);
void ds_v(char *arr, int sze);

char *ze_arg(unsigned int numb);
int sizint(int numb);
int ze_it(char *cze);
int perr(sh_t *dt);
int wr_his(sh_t *dt);
int ze_alche(int cze);

int pazFm_c(sh_t *dt);
void isfm(sh_t *dt);
int isbtin(sh_t *dt);

int ab_pg(sh_t *dt);
int ze_cd(sh_t *dt);
int hd_btin(sh_t *dt);
int chk_btin(sh_t *dt);

#endif
