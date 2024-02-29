#include "project.h"

/**
 * *op_scopy - copies the string
 * @de: char de
 * @sr: char sr
 * Return: de.
 */
char *op_scopy(char *de, char *sr)
{
	int id = 0;
	char temp;

	while (sr[id] != '\0')
	{
		temp = sr[id];
		de[id] = temp;
		id++;
	}
	de[id] = '\0';
	return (de);
}

/**
 * op_slen - length of a string.
 * @sa: pointer to String
 * Return: Nothing
 */
int op_slen(const char *sa)
{
	int id;

	for (id = 0; *(sa + id) != '\0'; id++)
	{
		;
	}

	return (id);
}
/**
 * op_sconc - concatenates two strings.
 * @de: string to destiny
 * @sr: string to source
 * Return: oncatenate string
 */
char *op_sconc(char *de, char *sr)
{
	int pre = 0;
	int pre2 = 0;

	while (de[pre] != '\0')
	{
		pre++;
	}
	while (sr[pre2] != '\0')
	{
		de[pre] = sr[pre2];
		pre++;
		pre2++;
	}
	de[pre] = '\0';
	return (de);
}

/**
 * op_sdup - copy a string.
 * @str: the string to copy
 * Return: void
 **/
char *op_sdup(char *str)
{
	int jd, l;
	char *pre2;

	if (!str)
	{
		return (NULL);
	}

	l = op_slen(str) + 1;

	pre2 = _calloc(l, sizeof(char));
	if (!pre2)
	{
		return (NULL);

	}

	for (jd = 0; jd < l; jd++)
	{
		pre2[jd] = str[jd];
	}
	return (pre2);
}
