#include "project.h"

/**
 * op_scmp - this function compare two strings
 * @m1: the first string
 * @s2: the second string
 * Return: difference
 */
int op_scmp(char *m1, char *s2)
{
	int j;

	for (j = 0; m1[j] != '\0' || s2[j] != '\0'; j++)
	{
		if (m1[j] != s2[j])
		{
			return (m1[j] - s2[j]);
		}
	}
	return (0);
}

/**
 *op_sncmp -  compares 2 strings.
 *@m1: s one
 *@s2: s two
 *@n: number of characters
 * Return: difference
 */
int op_sncmp(const char *m1, const char *s2, size_t n)
{
	int i = 0, j = 0;

	while (n && m1[i] && (m1[i] == s2[j]))
	{
		i++;
		j++;
		n--;
	}
	if (n == 0)
	{
		return (0);
	}
	else
	{
		return (m1[i] - s2[j]);
	}
}


