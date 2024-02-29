#include "project.h"

/**
 * ppf - validate
 * @pth: All enviroment varible PATH
 * @fse: name the command
 * Return: path the fse
 **/
char *ppf(char *pth, char *fse)
{
	struct stat stul;
	char *p_nme;
	char *tuk = NULL;
	int i;

	tuk = strtok(pth, ":");
	for (i = 0; tuk != NULL; i++)
	{
		p_nme = malloc((op_slen(tuk) + op_slen(fse) + 2) * sizeof(char));
		if (p_nme == NULL)
		{
			free(p_nme);
			return (fse);
		}
		op_scopy(p_nme, tuk);
		op_sconc(p_nme, "/");
		op_sconc(p_nme, fse);
		if (stat(p_nme, &stul) == 0)
			return (p_nme);
		free(p_nme);
		tuk = strtok(NULL, ":");
	}
	return (NULL);
}
