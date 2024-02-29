#include "project.h"
/**
 * _memset - fills memory
 * @pre2: address begin to fill
 * @b: value to set on memory
 * @n: numbers of bytes
 * Return: char
 */
char *_memset(char *pre2, char b, unsigned int n)
{
	unsigned int cont;

	for (cont = 0; cont < n; cont++)
		*(pre2 + cont) = b;
	return (pre2);
}
/**
 * _calloc - function that allocates memory for an array, using malloc
 * @arr_mem: amount to values to store on memory
 * @lenz: number of bytes of datatype
 *
 * Return: Void pointer
 */
void *_calloc(unsigned int arr_mem, int lenz)
{
	void *p = NULL;
	char *c;
	unsigned int i;

	if (arr_mem == 0 || lenz == 0)
		return (NULL);

	p = malloc(arr_mem * lenz);
	if (p == NULL)
		return (NULL);

	c = p;
	for (i = 0; i < (arr_mem * lenz); i++)
		c[i] = 0;

	return (p);
}

/**
 * own_env - print var global e_v
 * @e_v: variable global e_v
 * Return: err_exit;
 **/

void own_env(char **e_v)
{
	int ze = 0;

	while (e_v[ze] != NULL)
	{
		write(STDOUT_FILENO, e_v[ze], strlen(e_v[ze]));
		write(STDOUT_FILENO, "\n", 1);
		ze++;
	}
}

