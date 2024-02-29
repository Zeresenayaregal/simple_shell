#include "shell.h"
/**
 * b_tns - funcptr.
 * @s: is the command to compare.
 * Return: function to perform or NULL.
 */
int (*b_tns(char *s))(char *, char **, char *, char **, int, int)
{
	built ops[] = {
		{"exit", ex},
		{"env", envir},
		{NULL, NULL}
	};
	int i = 0;

	while (ops[i].comand)
	{
		if (_strcmp(ops[i].comand, s) == 0)
			return (ops[i].func);
		i++;
	}
	return (NULL);
}
