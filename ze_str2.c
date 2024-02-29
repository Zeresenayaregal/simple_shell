#include "shell.h"

/**
 * ze_siz - finds the length of a given string
 * @sng: the given string
 *
 * Return: (Success) the length of the string
 */
int ze_siz(char *sng)
{
	int sze;

	for (sze = 0; sng[sze]; sze++)
		;
	return (sze);
}
/**
 * ze_comp - compare two strings
 * @sn1: the fs given string
 * @sn2: the se given string
 *
 * Return: (Success) a positive number
 */
int ze_comp(char *sn1, char *sn2)
{
	int cmp = 0, i;

	if (sn1 == NULL || sn2 == NULL)
		return (1);
	for (i = 0; sn1[i]; i++)
	{
		if (sn1[i] != sn2[i])
		{
			cmp = sn1[i] - sn2[i];
			break;
		}
		else
			continue;
	}
	return (cmp);
}
/**
 * ze_char - locates a char
 * @sng: the give sng
 * @cze: the give sng
 *
 * Return: a pointer
 */
char *ze_char(char *sng, char cze)
{
	char *pr;

	if (sng == NULL)
		return (NULL);
	for (pr = sng; *pr; pr++)
		if (*pr == cze)
			return (pr);
	return (NULL);
}
/**
 * ze_rep - dupicates sng
 * @sng: the give sng
 *
 * Return: a pointer
 */
char *ze_rep(char *sng)
{
	char *dupl;

	if (sng == NULL)
		return (NULL);
	dupl = malloc(ze_siz(sng) + 1);
	if (dupl == NULL)
		return (NULL);
	ze_copy(dupl, sng);
	return (dupl);
}
