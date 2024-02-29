#include "shell.h"

/**
 * ze_cd - cd
 * @dt: a ptr to the ds
 * Return: 0
 */

int ze_cd(sh_t *dt)
{
	char *hu;

	hu = ze_goev("HOME");
	if (dt->ags[1] == NULL)
	{
		SETOWD(dt->oldpwd);
		if (chdir(hu) < 0)
			return (FAIL);
		return (1);
	}
	if (ze_comp(dt->ags[1], "-") == 0)
	{
		if (dt->oldpwd == 0)
		{
			SETOWD(dt->oldpwd);
			if (chdir(hu) < 0)
				return (FAIL);
		}
		else
		{
			SETOWD(dt->oldpwd);
			if (chdir(dt->oldpwd) < 0)
				return (FAIL);
		}
	}
	else
	{
		SETOWD(dt->oldpwd);
		if (chdir(dt->ags[1]) < 0)
			return (FAIL);
	}
	return (1);
}
#undef GETCWD
/**
 * ab_pg - exit
 * @dt: a ptr to the dt struct
 * Return: (Success)
 */
int ab_pg(sh_t *dt __attribute__((unused)))
{
	int code, i = 0;

	if (dt->ags[1] == NULL)
	{
		ze_free(dt);
		exit(errno);
	}
	while (dt->ags[1][i])
	{
		if (ze_alche(dt->ags[1][i++]) < 0)
		{
			dt->errmg = ze_rep("Invalid Num\n");
			return (FAIL);
		}
	}
	code = ze_it(dt->ags[1]);
	ze_free(dt);
	exit(code);
}
/**
 * hd_btin - handle and manage the builtins com
 * @dt: a pointer to the dt structure
 * Return: (Success) 0 is returned
 */
int hd_btin(sh_t *dt)
{
	blt_t blt[] = {
		{"exit", ab_pg},
		{"cd", ze_cd},
		{NULL, NULL}
	};
	int idd = 0;

	while ((blt + idd)->com)
	{
		if (ze_comp(dt->ags[0], (blt + idd)->com) == 0)
			return ((blt + idd)->func(dt));
		idd++;
	}
	return (FAIL);
}
