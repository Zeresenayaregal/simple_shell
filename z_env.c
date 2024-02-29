#include "project.h"
/**
 * gev - get variable enviriomment
 * @name: name the variable envirionment
 * @e_v: environment variable
 * Return: char value envirionment
 **/
char *gev(char *name, char **e_v)
{
	char *tk1, *tk2, *e_nme, *cr_ev = NULL;
	int id;

	e_nme = op_sdup(name);

	for (id = 0; e_v[id] && e_v; id++)
	{
		cr_ev = NULL;
		tk2 = NULL;
		cr_ev = op_sdup(e_v[id]);
		tk1 = strtok(cr_ev, "=");
		tk2 = op_sdup(strtok(NULL, "="));
		if (op_scmp(e_nme, tk1) == 0)
			break;
		free(cr_ev);
		free(tk2);
	}
	free(cr_ev);
	cr_ev = NULL;
	free(e_nme);
	return (tk2);
}
