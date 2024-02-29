#include "shell.h"
/**
 * pazFm_c - check if the given filename is a path
 * @dt: the dt struct ptter
 *
 * Return: (1)
 */
int pazFm_c(sh_t *dt)
{
	if (ze_char(dt->ags[0], '/') != 0)
	{
		dt->com = ze_rep(dt->ags[0]);
		return (1);
	}
	return (FAIL);
}
#define DILIM ":"
/**
 * isfm - chekc if the given fikenname is short form
 * @dt: the dt struct ptter
 *
 * Return: (1)
 */
void isfm(sh_t *dt)
{
	char *path, *token, *_path;
	struct stat st;
	int et_fg = 0;

	path = ze_goev("PATH");
	_path = ze_rep(path);
	token = strtok(_path, DILIM);
	while (token)
	{
		dt->com = ze_conc(token, dt->ags[0]);
		if (stat(dt->com, &st) == 0)
		{
			et_fg += 1;
			break;
		}
		free(dt->com);
		token = strtok(NULL, DILIM);
	}
	if (et_fg == 0)
	{
		dt->com = ze_rep(dt->ags[0]);
	}
	free(_path);
}
#undef DILIM
/**
 * isbtin - checks if the command is bt_in
 * @dt: a ptter to the dt structure
 *
 * Return: (1) 0 is returned
 */
int isbtin(sh_t *dt)
{
	blt_t blt[] = {
		{"exit", ab_pg},
		{"cd", ze_cd},
		{NULL, NULL}
	};
	int i;

	for (i = 0; (blt + i)->com; i++)
	{
		if (ze_comp(dt->ags[0], (blt + i)->com) == 0)
			return (1);
	}
	return (NEUTRAL);
}
