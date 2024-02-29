#include "shell.h"
/**
 * ze_copy - copy a str from src to dest
 * @src: the string src
 * @dst: the string dest
 *
 * Return: the pointer to dst
 */
char *ze_copy(char *dst, char *src)
{
	int i;

	i = 0;

	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
/**
 * ze_alche - check if the inp
 * @cze: the char to be check
 *
 * Return: 1 / 0
 */
int ze_alche(int cze)
{
	if ((cze >= 65 && cze <= 90) || (cze >= 97 && cze <= 122))
	{
		return (1);
	}
	return (FAIL);
}

/**
 * ze_conc - concatenates two string in a path form
 * @fs: the fs given destination
 * @se: the se given src
 *
 * Return: (Success) to the newly string
 */
char *ze_conc(char *fs, char *se)
{
	int l1, l2, i = 0, j = 0;
	char *ess;

	l1 = ze_siz(fs);
	l2 = ze_siz(se);
	ess = malloc((l1 + l2 + 2) * sizeof(char));
	if (!ess)
		return (NULL);
	*ess = '\0';
	while (fs[j])
		ess[i++] = fs[j++];
	ess[i++] = '/';
	j = 0;
	while (se[j])
		ess[i++] = se[j++];
	ess[i] = '\0';
	return (ess);
}
